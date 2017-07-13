#include "dataprocess.h"
#include <math.h>

DataProcess::DataProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	signalMapper = new QSignalMapper(this);
	connect(ui.btn_root, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_root, "...");
	connect(ui.btn_res, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_res, "....");
	connect(ui.btn_demo, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_demo, "showDemo");
	connect(ui.btn_as, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_as, "alignSimp");
	connect(ui.btn_ai, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_ai, "alignIter");
	connect(ui.btn_icp, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_icp, "ICP");


	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL(doDemoSignal()), this, SLOT(doDemoSlot()));
	connect(this, SIGNAL(doAlignSimpSignal()), this, SLOT(doAlignSampSlot()));
	connect(this, SIGNAL(doAlignIterSignal()), this, SLOT(doAlignIterSlot()));
	connect(this, SIGNAL(doICPSignal()), this, SLOT(doICPSlot()));
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
	if (btnname == "showDemo")
	{
		emit doDemoSignal();
	}
	if (btnname == "alignSimp")
	{
		emit doAlignSimpSignal();
	}
	if (btnname == "ICP")
	{
		emit doICPSignal();
	}
	if (btnname == "alignIter")
	{
		emit doAlignIterSignal();
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

void DataProcess::doDemoSlot()
{
	emit doAlignSimpSignal();
	emit doAlignIterSignal();
	emit doICPSignal();
	//Mat image_R, image_L;
	//image_L = imread(q2s(imagePath_list.at(1)), CV_LOAD_IMAGE_COLOR);
	//image_R = imread(q2s(imagePath_list.at(0)), CV_LOAD_IMAGE_COLOR);

	//float dis_last = alignProcess(0, image_L, image_R);
	//float dis_now = 0;
	//float e_dis = dis_last;

	//while (e_dis > 1)
	//{
	//	dis_now = alignProcess(dis_last, image_L, image_R);
	//	e_dis = abs(dis_now - dis_last);
	//	dis_last = dis_now;
	//}

	//int dis = (dis_now + 0.5);
	//saveRes("test", "test1", "4j", dis, image_L, image_R);
	//saveRes("test", "test2", "2j", dis, image_L, image_R);
	//saveRes("test", "test3", "2s", dis, image_L, image_R);


}

void DataProcess::doAlignSampSlot()
{
	String dir_name = "alignSimp";
	String mode = "2s";
	for (int i = 0; i < imageName_list.length() - 1; i = i + 2)
	{
		Mat image_R, image_L;
		image_L = imread(q2s(imagePath_list.at(i + 1)), CV_LOAD_IMAGE_COLOR);
		image_R = imread(q2s(imagePath_list.at(i)), CV_LOAD_IMAGE_COLOR);

		int dis = alignProcess(0, image_L, image_R) + 0.5;
		saveRes(dir_name, to_string(i), mode, dis, image_L, image_R);

		qDebug() << i << "finished!";
	}

}

void DataProcess::doAlignIterSlot()
{
	String dir_name = "alignIter";
	String mode = "2s";
	for (int i = 0; i < imageName_list.length() - 1; i = i + 2)
	{
		Mat image_R, image_L;
		image_L = imread(q2s(imagePath_list.at(i + 1)), CV_LOAD_IMAGE_COLOR);
		image_R = imread(q2s(imagePath_list.at(i)), CV_LOAD_IMAGE_COLOR);

		float dis_last = alignProcess(0, image_L, image_R);
		float dis_now = 0;
		float e_dis = dis_last;

		while (e_dis > 1)
		{
			dis_now = alignProcess(dis_last, image_L, image_R);
			e_dis = abs(dis_now - dis_last);
			dis_last = dis_now;
		}

		int dis = (dis_now + 0.5);

		saveRes(dir_name,to_string(i),mode,dis, image_L,image_R);

		qDebug() << i << "finished!";
	}

}

void DataProcess::doICPSlot()
{
	String dir_name = "icp";
	String mode = "2s";
	for (int i = 0; i < imageName_list.length() - 1; i = i + 2)
	{
	Mat image_R, image_L;
	image_L = imread(q2s(imagePath_list.at(i+1)), CV_LOAD_IMAGE_COLOR);
	image_R = imread(q2s(imagePath_list.at(i)), CV_LOAD_IMAGE_COLOR);

	Mat image_L_8 = Mat::zeros(image_L.cols, image_L.rows, CV_32SC3);
	image_L.convertTo(image_L_8, CV_32SC3);
	//imshow("image_L", image_L);

	Mat image_R_8 = Mat::zeros(image_L.cols, image_L.rows, CV_32SC3);
	image_R.convertTo(image_R_8, CV_32SC3);

	vector<vector<int>> Lpoint;
	vector<vector<int>> Rpoint;
	int count = 0;

	for (int i = 0; i < image_L.rows; i++)
	{
		for (int j = 0; j < image_L.cols; j++)
		{
			vector<int> temp_lp;
			temp_lp.push_back(j);
			temp_lp.push_back(i);
			temp_lp.push_back(image_L_8.at<Vec3i>(i, j)[0] * 0.144 + image_L_8.at<Vec3i>(i, j)[1] * 0.587 + image_L_8.at<Vec3i>(i, j)[2] * 0.299);
			Lpoint.push_back(temp_lp);

			vector<int> temp_rp(temp_lp);
			temp_rp.at(2) = image_R_8.at<Vec3i>(i, j)[0] * 0.144 + image_R_8.at<Vec3i>(i, j)[1] * 0.587 + image_R_8.at<Vec3i>(i, j)[2] * 0.299;
			Rpoint.push_back(temp_rp);
		}
	}

	float dis= ICPiterator(Lpoint, Rpoint);
	qDebug() << "dis:" << dis;
	saveRes(dir_name, to_string(i), mode, dis, image_L, image_R);

	qDebug() << i << "finished!";
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
	else 
		str_date.append("_").append(opt);
	

	newDir_path.append(str_date);
	

	QDir *temp = new QDir;
	bool exist = temp->exists(s2q(newDir_path));
	//if (exist)
	//	QMessageBox::warning(this, tr("mkdir"), tr("allready exist!"));
	//else
	//{
		bool ok = temp->mkdir(s2q(newDir_path));
	//	if (ok)
	//		QMessageBox::warning(this, tr("mkdir"), tr("create successfully!"));
	//}
	return newDir_path;
}

float DataProcess::alignProcess(int dis, Mat img_l, Mat img_r)
{
	Mat image_L_8 = Mat::zeros(img_l.cols, img_l.rows, CV_32SC3);
	img_l.convertTo(image_L_8, CV_32SC3);
	//imshow("image_L", image_L);

	Mat image_R_8 = Mat::zeros(img_r.cols, img_r.rows, CV_32SC3);
	img_r.convertTo(image_R_8, CV_32SC3);

	float new_dis = 0;
	int nrows = img_r.rows;
	int ncols = img_r.cols;
	float sum_dis = 0;
	float sum_dis_h = 0;
	float diff_min = INT_MAX;
	int dis_min = 0;
	int dis_min_index = 0;
	float temp = 0;

	int count = 0;

	for (int row = 1; row < nrows - 1; row++)
	{
		for (int i = 1; i < ncols-dis - 1; i++)
		{
			for (int j = max(i - 150, dis+1); j < min(i + 150, ncols - 1); j++)
			{
				for (int c = 0; c < 3; c++)
				{
					//int j = j+dis;
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
				}
				if (temp < diff_min)
				{
					diff_min = temp;
					dis_min_index = j;
					dis_min = abs(j - i);
				}
				temp = 0;
			}
			sum_dis_h = sum_dis_h + dis_min;
			diff_min = INT_MAX;
		}
		sum_dis = sum_dis + sum_dis_h / (ncols - 2);
		sum_dis_h = 0;
	}
	new_dis = sum_dis / (nrows - 2);
	qDebug() << "new_dis:" << new_dis;

	return new_dis;
}

float DataProcess::BottomAlignProcess(int dis, Mat img_l, Mat img_r)
{
	Mat image_L_8 = Mat::zeros(img_l.cols, img_l.rows, CV_32SC3);
	img_l.convertTo(image_L_8, CV_32SC3);
	//imshow("image_L", image_L);

	Mat image_R_8 = Mat::zeros(img_r.cols, img_r.rows, CV_32SC3);
	img_r.convertTo(image_R_8, CV_32SC3);

	float new_dis = 0;
	int nrows = img_r.rows;
	int ncols = img_r.cols;
	float sum_dis = 0;
	float sum_dis_h = 0;
	float diff_min = INT_MAX;
	int dis_min = 0;
	int dis_min_index = 0;
	float temp = 0;

	int count = 0;

	for (int row = 1; row < nrows/2 - 1; row++)
	{
		for (int i = 1; i < ncols - dis - 1; i++)
		{
			for (int j = max(i - 150, dis + 1); j < min(i + 150, ncols - 1); j++)
			{
				for (int c = 0; c < 3; c++)
				{
					//int j = j+dis;
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
				}
				if (temp < diff_min)
				{
					diff_min = temp;
					dis_min_index = j;
					dis_min = abs(j - i);
				}
				temp = 0;
			}
			sum_dis_h = sum_dis_h + dis_min;
			diff_min = INT_MAX;
		}
		sum_dis = sum_dis + sum_dis_h / (ncols - 2);
		sum_dis_h = 0;
	}
	new_dis = sum_dis / (nrows - 2);
	qDebug() << "new_dis:" << new_dis;

	return new_dis;
}

bool DataProcess::saveRes(String dir_name,String file_name,String mode,int dis,Mat image_L, Mat image_R)
{
	String save_path = newDir(dir_name.append(mode)).append("/").append(file_name);
	qDebug() << s2q(save_path);
	//String save_path_temp = save_path;

	Mat res;
	qDebug() << mode.compare("4j");

	//模式1  产生4格拼接图 
	if (!mode.compare("4j")){
		res = Mat::zeros(image_L.rows * 2, image_L.cols * 2 + dis, CV_8UC3);
		for (int i = 0; i < image_L.cols; i++)
		{
			for (int j = 0; j < image_L.rows; j++)
			{
				res.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
			}
		}

		for (int i = 0; i < image_R.cols; i++)
		{
			for (int j = 0; j < image_R.rows; j++)
			{
				res.at<Vec3b>(i + image_R.rows, j) = image_R.at<Vec3b>(i, j);
			}
		}

		for (int i = 0; i < image_L.cols; i++)
		{
			for (int j = 0; j < image_L.rows; j++)
			{
				res.at<Vec3b>(i, j + image_L.cols) = image_L.at<Vec3b>(i, j);
			}
		}

		for (int i = 0; i < image_R.cols; i++)
		{
			for (int j = 0; j < image_R.rows; j++)
			{
				res.at<Vec3b>(i + image_R.rows, j + image_L.cols + dis) = image_R.at<Vec3b>(i, j);
			}
		}
		for (int i = 0; i < res.rows; i++)
		{
			res.at<Vec3b>(i, image_L.cols + dis) = (255, 0, 0);
			res.at<Vec3b>(i, image_L.cols * 2) = (255, 0, 0);
		}
		save_path.append(file_name.append(".jpg"));
		imwrite(save_path, res);
		return true;
	}

	//模式2  产生2格拼接图  
	if (!mode.compare("2j"))
	{
		res = Mat::zeros(image_L.rows * 2, image_L.cols + dis, CV_8UC3);
		for (int i = 0; i < image_L.cols; i++)
		{
			for (int j = 0; j < image_L.rows; j++)
			{
				res.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
			}
		}

		for (int i = 0; i < image_R.cols; i++)
		{
			for (int j = 0; j < image_R.rows; j++)
			{
				res.at<Vec3b>(i + image_R.rows, j + dis) = image_R.at<Vec3b>(i, j);
			}
		}
		for (int i = 0; i < res.rows; i++)
		{
			res.at<Vec3b>(i, image_L.cols) = (255, 0, 0);
			res.at<Vec3b>(i, dis) = (255, 0, 0);
		}
		save_path.append(file_name.append(".jpg"));
		imwrite(save_path, res);
		return true;
	}
	


	//模式3  产生2张单独的图片 
	if(!mode.compare("2s"))
	{
		Mat res_l = Mat::zeros(image_L.rows, image_L.cols + dis, CV_8UC3);
		Mat res_r = Mat::zeros(image_L.rows, image_L.cols + dis, CV_8UC3);
		for (int i = 0; i < image_L.cols; i++)
		{
			for (int j = 0; j < image_L.rows; j++)
			{
				res_l.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
			}
		}

		for (int i = 0; i < image_R.cols; i++)
		{
			for (int j = 0; j < image_R.rows; j++)
			{
				res_r.at<Vec3b>(i, j + dis) = image_R.at<Vec3b>(i, j);
			}
		}
		String save_path_temp_l = save_path;
		String save_path_temp_r = save_path;
		save_path_temp_l.append("_L.jpg");
		save_path_temp_r.append("_R.jpg");
		imwrite(save_path_temp_l, res_l);
		imwrite(save_path_temp_r, res_r);
		return true;
	}
	else
	{
		qDebug() << "bad mode input";
		return false ;
	}
}

//void DataProcess::doAlignSlot()
//{
//
//	String save_path1 = newDir("alignAll_res1").append("/");
//	String save_path2 = newDir("alignAll_res2").append("/");
//	String save_path_temp1 = save_path1;
//	String save_path_temp2 = save_path2;
//
//	for (int i = 0; i < imageName_list.length() - 1; i = i + 2)
//	{
//
//		Mat image_R, image_L;
//		image_L = imread(q2s(imagePath_list.at(i + 1)), CV_LOAD_IMAGE_COLOR);
//
//		image_R = imread(q2s(imagePath_list.at(i)), CV_LOAD_IMAGE_COLOR);
//
//		float dis_last = alignProcess(0, image_L, image_R);
//		float dis_now = 0;
//		float e_dis = dis_last;
//
//		while (e_dis > 1)
//		{
//			dis_now = alignProcess(dis_last, image_L, image_R);
//			e_dis = abs(dis_now - dis_last);
//			dis_last = dis_now;
//		}
//
//		int dis = (dis_now + 0.5);
//
//		Mat res = Mat::zeros(image_L.rows * 2, image_L.cols * 2 + dis, CV_8UC3);
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res.at<Vec3b>(i + image_R.rows, j) = image_R.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res.at<Vec3b>(i, j + image_L.cols) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res.at<Vec3b>(i + image_R.rows, j + image_L.cols + dis) = image_R.at<Vec3b>(i, j);
//			}
//		}
//		for (int i = 0; i < res.rows; i++)
//		{
//			res.at<Vec3b>(i, image_L.cols + dis) = (255, 0, 0);
//			res.at<Vec3b>(i, image_L.cols * 2) = (255, 0, 0);
//		}
//
//
//		Mat res2 = Mat::zeros(image_L.rows * 2, image_L.cols + dis, CV_8UC3);
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res2.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res2.at<Vec3b>(i + image_R.rows, j + dis) = image_R.at<Vec3b>(i, j);
//			}
//		}
//		for (int i = 0; i < res.rows; i++)
//		{
//			res2.at<Vec3b>(i, image_L.cols) = (255, 0, 0);
//			res2.at<Vec3b>(i, dis) = (255, 0, 0);
//		}
//		//imshow("res", res);
//
//		save_path_temp1.append(to_string(i).append(".jpg"));
//		imwrite(save_path_temp1, res);
//		save_path_temp1 = save_path1;
//
//		save_path_temp2.append(to_string(i).append(".jpg"));
//		imwrite(save_path_temp2, res2);
//		save_path_temp2 = save_path2;
//
//		qDebug() << i << "finished!";
//	}
//
//}
//void DataProcess::doICPSlot()
//{
//	String save_path1 = newDir("icp_res1").append("/");
//	String save_path2 = newDir("icp_res2").append("/");
//	String save_path_temp1 = save_path1;
//	String save_path_temp2 = save_path2;
//
//	for (int i = 0; i < imageName_list.length() - 1; i = i + 2)
//	{
//		Mat image_R, image_L;
//		image_L = imread(q2s(imagePath_list.at(i + 1)), CV_LOAD_IMAGE_COLOR);
//		image_R = imread(q2s(imagePath_list.at(i)), CV_LOAD_IMAGE_COLOR);
//
//		Mat image_L_8 = Mat::zeros(image_L.cols, image_L.rows, CV_32SC3);
//		image_L.convertTo(image_L_8, CV_32SC3);
//		//imshow("image_L", image_L);
//
//		Mat image_R_8 = Mat::zeros(image_L.cols, image_L.rows, CV_32SC3);
//		image_R.convertTo(image_R_8, CV_32SC3);
//
//		vector<vector<int>> Lpoint;
//		vector<vector<int>> Rpoint;
//		int count = 0;
//
//		for (int i = 0; i < image_L.rows; i++)
//		{
//			for (int j = 0; j < image_L.cols; j++)
//			{
//				vector<int> temp_lp;
//				temp_lp.push_back(j);
//				temp_lp.push_back(i);
//				temp_lp.push_back(image_L_8.at<Vec3i>(i, j)[0] * 0.144 + image_L_8.at<Vec3i>(i, j)[1] * 0.587 + image_L_8.at<Vec3i>(i, j)[2] * 0.299);
//				Lpoint.push_back(temp_lp);
//
//				vector<int> temp_rp(temp_lp);
//				//int temp = image_R_8.at<Vec3i>(i, j)[0] * 0.144 + image_R_8.at<Vec3i>(i, j)[1] * 0.587 + image_R_8.at<Vec3i>(i, j)[2] * 0.299;
//				temp_rp.at(2) = image_R_8.at<Vec3i>(i, j)[0] * 0.144 + image_R_8.at<Vec3i>(i, j)[1] * 0.587 + image_R_8.at<Vec3i>(i, j)[2] * 0.299;
//				Rpoint.push_back(temp_rp);
//			}
//		}
//
//
//		float dis = ICPiterator(Lpoint, Rpoint);
//		qDebug() << "dis:" << dis;
//
//
//		Mat res = Mat::zeros(image_L.rows * 2, image_L.cols * 2 + dis, CV_8UC3);
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res.at<Vec3b>(i + image_R.rows, j) = image_R.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res.at<Vec3b>(i, j + image_L.cols) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res.at<Vec3b>(i + image_R.rows, j + image_L.cols + dis) = image_R.at<Vec3b>(i, j);
//			}
//		}
//		for (int i = 0; i < res.rows; i++)
//		{
//			res.at<Vec3b>(i, image_L.cols + dis) = (255, 0, 0);
//			res.at<Vec3b>(i, image_L.cols * 2) = (255, 0, 0);
//		}
//
//		imshow("res", res);
//
//		Mat res2 = Mat::zeros(image_L.rows * 2, image_L.cols + dis, CV_8UC3);
//		for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res2.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//		for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res2.at<Vec3b>(i + image_R.rows, j + dis) = image_R.at<Vec3b>(i, j);
//			}
//		}
//		for (int i = 0; i < res2.rows; i++)
//		{
//			res2.at<Vec3b>(i, image_L.cols) = (255, 0, 0);
//			res2.at<Vec3b>(i, dis) = (255, 0, 0);
//		}
//		imshow("res2", res2);
//
//		save_path_temp1.append(to_string(i).append(".jpg"));
//		imwrite(save_path_temp1, res);
//		save_path_temp1 = save_path1;
//
//		save_path_temp2.append(to_string(i).append(".jpg"));
//		imwrite(save_path_temp2, res2);
//		save_path_temp2 = save_path2;
//
//		qDebug() << i << "finished!";
//	}
//}

//void DataProcess::doDemoSlot()
//{
//	/*String save_path=newDir("rename");
//	addSubFolderImages(s2q(save_path));
//	save_path = save_path.append("/");*/
//	String save_path = newDir("align").append("/");
//	String save_path_temp = save_path;
//
//	Mat image_R, image_L;
//	image_L = imread(q2s(imagePath_list.at(1)), CV_LOAD_IMAGE_COLOR);
//
//	image_R = imread(q2s(imagePath_list.at(0)), CV_LOAD_IMAGE_COLOR);
//
//	float dis_last = alignProcess(0, image_L, image_R);
//	float dis_now = 0;
//	float e_dis = dis_last;
//
//	while (e_dis > 1)
//	{
//		dis_now=alignProcess(dis_last, image_L, image_R);
//		e_dis = abs(dis_now - dis_last);
//		dis_last = dis_now;
//	}
//
//	int dis = (dis_now+0.5);
//	//Mat image_L_8 = Mat::zeros(image_L.cols, image_L.rows, CV_32SC3);
//	//image_L.convertTo(image_L_8, CV_32SC3);
//	////imshow("image_L", image_L);
//
//	//Mat image_R_8 = Mat::zeros(image_R.cols, image_R.rows, CV_32SC3);
//	//image_R.convertTo(image_R_8, CV_32SC3);
//	////imshow("image_R", image_R);
//
//
//	//int  row = image_L_8.rows / 2;
//	//int ncols = image_L_8.cols;
//	//int sum_dis = 0;
//	//float diff_min = INT_MAX;
//	//int dis_min = 0;
//	//int dis_min_index = 0;
//	//float temp = 0;
//
//	//for (int i = 1; i < ncols - 1; i++)
//	//{
//	//	for (int j = i; j < min(i + 50, ncols - 1); j++)
//	//	{
//	//		for (int c = 0; c < 3; c++)
//	//		{
//	//			//qDebug() << (image_R_8.at<Vec3i>(row - 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]);
//	//			//qDebug() << (image_R_8.at<Vec3i>(row - 1, j - 1)[c] - image_R_8.at<Vec3i>(row, j)[c]);
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i )[c]    - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j )[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row , i - 1)[c]    - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row , j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row , i + 1)[c]    - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i )[c]    - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j )[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//			temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//		}
//	//		if (temp<diff_min)
//	//		{
//	//			diff_min = temp;
//	//			dis_min_index = j;
//	//			dis_min = abs(j - i);
//	//		}	
//	//		temp = 0;
//	//	}
//	//	sum_dis = sum_dis + dis_min;
//	//	diff_min = INT_MAX;
//	//}
//
//	//int dis = floor(sum_dis / (ncols - 2) + 0.5);
//	//qDebug() << dis;
//	//int dis = 0;
//	//int nrows = image_L.rows;
//	//int ncols = image_L.cols;
//	//float sum_dis = 0;
//	//float sum_dis_h = 0;
//	//float diff_min = INT_MAX;
//	//int dis_min = 0;
//	//int dis_min_index = 0;
//	//float temp = 0;
//
//	//int count = 0;
//
//	//	for (int row = 1; row < nrows - 1; row++)
//	//	{
//	//		for (int i = 1; i < ncols - 1; i++)
//	//		{
//	//			for (int j = max(i - 50, 1); j < min(i + 50, ncols - 1); j++)
//	//			{
//	//				for (int c = 0; c < 3; c++)
//	//				{
//	//					//int j = j+dis;
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row - 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row - 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i - 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j - 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//					temp = temp + abs((image_R_8.at<Vec3i>(row + 1, i + 1)[c] - image_R_8.at<Vec3i>(row, i)[c]) - (image_L_8.at<Vec3i>(row + 1, j + 1)[c] - image_L_8.at<Vec3i>(row, j)[c]));
//	//				}
//	//				if (temp < diff_min)
//	//				{
//	//					diff_min = temp;
//	//					dis_min_index = j;
//	//					dis_min = abs(j - i);
//	//				}
//	//				temp = 0;
//	//			}
//	//			sum_dis_h = sum_dis_h + dis_min;
//	//			diff_min = INT_MAX;
//	//		}
//	//		sum_dis = sum_dis+sum_dis_h / (ncols - 2);
//	//		sum_dis_h = 0;
//	//	}
//	//	dis = sum_dis / (nrows - 2);
//	//	qDebug() << "dis:"<<dis;
//
//	
//
//	Mat res = Mat::zeros(image_L.rows*2, image_L.cols*2 + dis, CV_8UC3);
//	for (int i = 0; i < image_L.cols; i++)
//	{
//		for (int j = 0; j < image_L.rows; j++)
//		{
//			res.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//		}
//	}
//
//	for (int i = 0; i < image_R.cols; i++)
//	{
//		for (int j = 0; j < image_R.rows; j++)
//		{
//			res.at<Vec3b>(i + image_R.rows, j) = image_R.at<Vec3b>(i, j);
//		}
//	}
//
//	for (int i = 0; i < image_L.cols; i++)
//		{
//			for (int j = 0; j < image_L.rows; j++)
//			{
//				res.at<Vec3b>(i, j + image_L.cols) = image_L.at<Vec3b>(i, j);
//			}
//		}
//
//	for (int i = 0; i < image_R.cols; i++)
//		{
//			for (int j = 0; j < image_R.rows; j++)
//			{
//				res.at<Vec3b>(i + image_R.rows, j + image_L.cols + dis) = image_R.at<Vec3b>(i, j);
//			}
//		}
//	for (int i = 0; i < res.rows; i++)
//	{
//		res.at<Vec3b>(i,image_L.cols + dis) = (255,0,0);
//		res.at<Vec3b>(i, image_L.cols*2) = (255, 0, 0);
//	}
//
//	imshow("res", res);
//
//	Mat res2 = Mat::zeros(image_L.rows * 2, image_L.cols + dis, CV_8UC3);
//	for (int i = 0; i < image_L.cols; i++)
//	{
//		for (int j = 0; j < image_L.rows; j++)
//		{
//			res2.at<Vec3b>(i, j) = image_L.at<Vec3b>(i, j);
//		}
//	}
//
//	for (int i = 0; i < image_R.cols; i++)
//	{
//		for (int j = 0; j < image_R.rows; j++)
//		{
//			res2.at<Vec3b>(i + image_R.rows, j + dis) = image_R.at<Vec3b>(i, j);
//		}
//	}
//	for (int i = 0; i < res2.rows; i++)
//	{
//		res2.at<Vec3b>(i, image_L.cols) = (255, 0, 0);
//		res2.at<Vec3b>(i, dis) = (255, 0, 0);
//	}
//	imshow("res2", res2);
//
//	save_path_temp.append(to_string(0).append(".jpg"));;
//	imwrite(save_path_temp, res);
//	save_path_temp = save_path;
//
//
//}

