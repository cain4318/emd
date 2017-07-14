#include "dataprocess.h"


DataProcess::DataProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	signalMapper = new QSignalMapper(this);
	connect(ui.btn_root, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_root, "...");
	connect(ui.btn_res, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_res, "....");
	
	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
}

DataProcess::~DataProcess()
{

}

void DataProcess::doClicked(const QString & btnname)
{
	if (btnname == "...")
	{
		emit setRootPathSignal();
	}
	if (btnname == "....")
	{
		emit setResPathSignal();
	}

}

void DataProcess::setRootPathSlot()
{
	//QMessageBox::warning(this, tr("tip"), tr("signal received!!"), QMessageBox::Yes | QMessageBox::No);
	QString file_path = QFileDialog::getExistingDirectory(this, "select root path...", "./");
	if (file_path.isEmpty())
	{
		return;
	}
	else{
		rootPath = file_path;
		ui.le_root->setText(file_path);
	}
	addSubFolderImages(rootPath);
}

void DataProcess::setResPathSlot()
{
	QString file_path = QFileDialog::getExistingDirectory(this, "select save path...", "./");
	if (file_path.isEmpty())
	{
		return;
	}
	else{
		resPath = file_path;
		ui.le_res->setText(file_path);
	}
	
}




void DataProcess::addSubFolderImages(QString path)
{
	imagePath_list.clear();
	imageName_list.clear();
	imageDir_list.clear();

	//判断路径是否存在
	QDir dir(path);
	if (!dir.exists())
	{
		return;
	}

	//获取所选文件类型过滤器
	QStringList filters;
	filters << QString("*.jpeg") << QString("*.jpg") << QString("*.png") << QString("*.ppm") << QString("*.gif") << QString("*.bmp")<<QString("*.tif")<<QString("*.tiff");

	//定义迭代器并设置过滤器
	QDirIterator dir_iterator(path,
		filters,
		QDir::Files | QDir::NoSymLinks,
		QDirIterator::Subdirectories);
	while (dir_iterator.hasNext())
	{
		dir_iterator.next();
		QFileInfo file_info = dir_iterator.fileInfo();
		QString absolute_file_path = file_info.absoluteFilePath();
		QString file_dir = file_info.absolutePath();
		QString file_name = file_info.baseName();
		imagePath_list.append(absolute_file_path);
		imageDir_list.append(file_dir);
		imageName_list.append(file_name);
		//qDebug() << file_dir;
		qDebug() << file_name;
	}
}


String DataProcess::newDir(String opt)
{
	time_t tt = time(NULL);
	tm* t = localtime(&tt);
	String str_date = to_string(t->tm_mon + 1);
	str_date.append(to_string(t->tm_mday));

	String newDir_path = q2s(resPath).append("/");

	if (opt.compare("rename")==0)
		str_date.append("_rename");
	if (opt.compare("cut")==0)
		str_date.append("_cut");
	if (opt.compare("resize")==0)
		str_date.append("_resize");
	if (opt.compare("plus") == 0)
		str_date.append("_plus");

	newDir_path.append(str_date);
	

	QDir *temp = new QDir;
	bool exist = temp->exists(s2q(newDir_path));
	if (exist)
		QMessageBox::warning(this, tr("mkdir"), tr("allready exist!"));
	else
	{
		bool ok = temp->mkdir(s2q(newDir_path));
		if (ok)
			QMessageBox::warning(this, tr("mkdir"), tr("create successfully!"));
	}
	return newDir_path;
}


