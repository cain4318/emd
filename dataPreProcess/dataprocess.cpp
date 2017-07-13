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
	connect(ui.btn_rename, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_rename, "rename");
	connect(ui.btn_cut, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_cut, "cut");
	connect(ui.btn_plus, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_plus, "plus");
	connect(ui.btn_resize, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_resize, "resize");
	connect(ui.btn_renameAll, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_renameAll, "renameAll");


	connect(ui.btn_sclar, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_sclar, "sclar");

	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL(doRenameSignal()), this, SLOT(doRenameSlot()));
	connect(this, SIGNAL(doCutSignal()), this, SLOT(doCutSlot()));
	connect(this, SIGNAL(doPlusSignal()), this, SLOT(doPlusSlot()));
	connect(this, SIGNAL(doResizeSignal()), this, SLOT(doResizeSlot()));
	connect(this, SIGNAL(doRenameAllSignal()), this, SLOT(doRenameAllSlot()));

	connect(this, SIGNAL(doSclarSignal()), this, SLOT(doSclarSlot()));
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
	if (btnname == "rename")
	{
		emit doRenameSignal();
	}
	if (btnname == "cut")
	{
		emit doCutSignal();
	}
	if (btnname == "plus")
	{
		emit doPlusSignal();
	}
	if (btnname == "resize")
	{
		emit doResizeSignal();
	}
	if (btnname == "renameAll")
	{
		emit doRenameAllSignal();
	}

	if (btnname == "sclar")
	{
		emit doSclarSignal();
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

void DataProcess::doRenameSlot()
{
	/*String save_path=newDir("rename");
	addSubFolderImages(s2q(save_path));
	save_path = save_path.append("/");*/

	String save_path = newDir("rename").append("/");
	String save_path_R = save_path;
	String save_path_L = save_path;

	for (int i = 0; i < imageName_list.length()-1; i=i+2)
	{
		bool issame = sameName(imageName_list.at(i), imageName_list.at(i+1), suffix);

		Mat image_R,image_L;
		image_R = imread(q2s(imagePath_list.at(i)), 1);

		image_L = imread(q2s(imagePath_list.at(i+1)), 1);
		if (!image_R.data)
		{
			qDebug() << "read image failed:"<<i<<"-image" << endl;
		}
		if (!image_L.data)
		{
			qDebug() << "read image failed:" << i+1 << "-image" << endl;
		}
		save_path_R.append(to_string(i).append("_R.jpg"));
		//qDebug() << s2q(save_path_R);
		imwrite(save_path_R, image_R);
		save_path_L.append(to_string(i).append("_L.jpg"));
		//qDebug() << s2q(save_path_L);
		imwrite(save_path_L, image_L);


		//Mat image_R, image_L;
		//image_R = imread(q2s(imagePath_list.at(i)), 1);
		//image_L = imread(q2s(imagePath_list.at(i + 1)), 1);
		//if (!image_R.data)
		//{
		//	qDebug() << "read image failed:" << i << "-image" << endl;
		//}
		//if (!image_L.data)
		//{
		//	qDebug() << "read image failed:" << i + 1 << "-image" << endl;
		//}
		//Mat image_r(image_R.rows, image_R.cols, CV_32FC3);
		//image_R.convertTo(image_r, CV_32FC3, 1 / 255.0);

		//Mat image_l(image_L.rows, image_L.cols, CV_32FC3);
		//image_L.convertTo(image_l, CV_32FC3, 1 / 255.0);

		//save_path_R.append(to_string(i).append("_R.jpg"));
		////qDebug() << s2q(save_path_R);
		//imwrite(save_path_R, image_r);
		//save_path_L.append(to_string(i).append("_L.jpg"));
		////qDebug() << s2q(save_path_L);
		//imwrite(save_path_L, image_l);
		save_path_R = save_path;
		save_path_L = save_path;
	}
	
}

void DataProcess::doCutSlot()
{
	/*String save_path = newDir("cut");
	addSubFolderImages(s2q(save_path));
	save_path = save_path.append("/");*/

	String save_path = newDir("cut").append("/");
	String save_path_save = save_path;

	for (int i = 0; i < imageName_list.length(); i++)
	{
		Mat image;
		image = imread(q2s(imagePath_list.at(i)), 1);
		String flag = q2s(imageName_list.at(i));
		flag = flag.substr(flag.length() - 1, 1);
		Mat result = cut(image, flag);

		save_path_save.append(q2s(imageName_list.at(i))).append(".jpg");
		qDebug() << s2q(save_path_save);
		imwrite(save_path_save, result);
		save_path_save = save_path;
	}



}

void DataProcess::doResizeSlot()
{
	String save_path = newDir("resize").append("/");
	String save_path_save = save_path;

	int size =atoi(q2s(ui.le_size->text()).c_str());
	if (size < 10 || size>512)
		QMessageBox::warning(this, "improper size", "input size between [10,512]");

	for (int i = 0; i < imageName_list.length(); i++)
	{
		Mat image;
		image = imread(q2s(imagePath_list.at(i)), 1);
		Mat result = Mat::zeros(Size(size, size), CV_8U);
		cv::resize(image, result, Size(size, size), 0, 0, INTER_LINEAR);
		
		save_path_save.append(q2s(imageName_list.at(i))).append(".jpg");
		qDebug() << s2q(save_path_save);
		imwrite(save_path_save, image);
		save_path_save = save_path;
	}
}

void DataProcess::doPlusSlot()
{
	String save_path = newDir("plus").append("/");
	String save_path_save = save_path;


	for (int i = 0; i < imageName_list.length(); i=i+2)
	{
		Mat image1 = imread(q2s(imagePath_list.at(i)), 1);
		Mat image2 = imread(q2s(imagePath_list.at(i+1)), 1);

		int totalCols = image1.cols + image2.cols;

		Mat mergedDescriptors(image1.rows, totalCols,image1.type());
		Mat submat = mergedDescriptors.colRange(0,image1.cols);
		image1.copyTo(submat);
		submat = mergedDescriptors.colRange(image1.cols, totalCols);
		image2.copyTo(submat);

		save_path_save.append(to_string(i)).append(".jpg");
		qDebug() << s2q(save_path_save);
		imwrite(save_path_save, mergedDescriptors);
		save_path_save = save_path;
	}
}

void DataProcess::doRenameAllSlot()
{
	/*String save_path=newDir("rename");
	addSubFolderImages(s2q(save_path));
	save_path = save_path.append("/");*/

	String save_path = newDir("renameAll").append("/");
	String save_path_save = save_path;
	for (int i = 0; i < imageName_list.length() - 1; i ++)
	{
		
		Mat image;
		image = imread(q2s(imagePath_list.at(i)), 1);
		
		//save_path_save.append(to_string(i).append(".jpg"));
		save_path_save.append(to_string(i).append(".jpg"));
		//save_path_save.append(to_string(i).append("_R.jpg"));
		imwrite(save_path_save, image);
		save_path_save = save_path;
	}

}


void DataProcess::doSclarSlot()
{
	/*String save_path = newDir("sclar").append("/");
	String save_path_save = save_path;

	int size = atoi(q2s(ui.le_size->text()).c_str());
	
	for (int i = 0; i < imageName_list.length(); i++)
	{
		Mat image;
		image = imread(q2s(imagePath_list.at(i)), 1);
		Mat result = Mat::zeros(Size(image.rows/size,image.cols/size), CV_8U);
		cv::resize(image, result, Size(image.rows / size, image.cols / size), 0, 0, INTER_LINEAR);

		save_path_save.append(q2s(imageName_list.at(i))).append(".jpg");
		qDebug() << s2q(save_path_save);
		imwrite(save_path_save, image);
		save_path_save = save_path;
	}*/

	String save_path = newDir("renameAll").append("/");
	String save_path_save = save_path;
	for (int i = 0; i < imageName_list.length() - 1; i++)
	{

		Mat image;
		image = imread(q2s(imagePath_list.at(i)), 1);

		//save_path_save.append(to_string(i).append(".jpg"));
		save_path_save.append(to_string(i).append("_L.jpg"));
		//save_path_save.append(to_string(i).append("_R.jpg"));
		imwrite(save_path_save, image);
		save_path_save = save_path;
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


