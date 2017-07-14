#include "emd2dtester.h"

emd2DTester::emd2DTester(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	signalMapper = new QSignalMapper(this);
	connect(ui.btn_root, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_root, "...");

	connect(ui.btn_res, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_res, "....");

	connect(ui.btn_calpair, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calpair, "calculate pair");

	connect(ui.btn_savepair, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_savepair, "save result");

	connect(ui.btn_calsaveall, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calsaveall, "cal and save all");


	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL((setPairIndexSignal(int))), this, SLOT((setPairIndexSlot(int))));
	connect(this, SIGNAL((calPairSignal())), this, SLOT((calPairSlot())));
	connect(this, SIGNAL((savePairSignal())), this, SLOT((savePairSlot())));
	connect(this, SIGNAL((calsaveAllSignal())), this, SLOT((calsaveAllSlot())));
}

emd2DTester::~emd2DTester()
{

}

void emd2DTester::doClicked(const QString & btnname)
{
	if (btnname == "...")
		emit setRootPathSignal();
	if (btnname == "....")
		emit setResPathSignal();
	if (btnname == "calculate pair")
		emit calPairSignal();
	if (btnname == "save result")
		emit savePairSignal();
	if (btnname == "cal and save all")
		emit calsaveAllSignal();
}

void emd2DTester::setRootPathSlot()
{
	//QMessageBox::warning(this, tr("tip"), tr("signal received!!"), QMessageBox::Yes | QMessageBox::No);
	QString file_path = QFileDialog::getExistingDirectory(this, "select root path...", "./");
	if (file_path.isEmpty())
	{
		return;
	}
	else{
		rootPath = file_path;
		ui.t_root->setText(file_path);
	}
	addSubFolderImages(rootPath);
}

void emd2DTester::setResPathSlot()
{
	QString file_path = QFileDialog::getExistingDirectory(this, "select save path...", "./");
	if (file_path.isEmpty())
	{
		return;
	}
	else{
		resPath = file_path;
		ui.t_res->setText(file_path);
	}

}

void emd2DTester::addSubFolderImages(QString path)
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
	filters << QString("*.jpeg") << QString("*.jpg") << QString("*.png") << QString("*.ppm") << QString("*.gif") << QString("*.bmp") << QString("*.tif") << QString("*.tiff");

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

String emd2DTester::newDir(String opt)
{
	time_t tt = time(NULL);
	tm* t = localtime(&tt);
	String str_date = to_string(t->tm_mon + 1);
	str_date.append(to_string(t->tm_mday));

	String newDir_path = q2s(resPath).append("/");

	if (opt.compare("rename") == 0)
		str_date.append("_rename");
	if (opt.compare("cut") == 0)
		str_date.append("_cut");
	if (opt.compare("resize") == 0)
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

void emd2DTester::setPairIndexSlot(int index){
	pairIndex = index;

	Mat image_i = imread(q2s(imagePath_list.at(2 * pairIndex)), 1);
	Mat image_j = imread(q2s(imagePath_list.at(2 * pairIndex + 1)), 1);

	*qimage_left = MatToQImage(image_i);
	ui.label_imgleft->setPixmap(QPixmap::fromImage(*qimage_left));
	*qimage_right = MatToQImage(image_j);
	ui.label_imgright->setPixmap(QPixmap::fromImage(*qimage_right));
}

void emd2DTester::calPairSlot(){

}
void emd2DTester::savePairSlot(){

}
void emd2DTester::calsaveAllSlot(){


}