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
	connect(ui.btn_calGrad, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calGrad, "calGrad");
	connect(ui.btn_calDis, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calDis, "calDis");
	connect(ui.btn_data1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_data1, "data1");
	connect(ui.btn_data2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_data2, "data2");
	connect(ui.btn_calGrad_2D, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calGrad_2D, "2DGrad");
	connect(ui.btn_calDis_batch, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calDis_batch, "batchDis");

	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL(calGardSignal()), this, SLOT(calGradSlot()));
	connect(this, SIGNAL(calDisSignal()), this, SLOT(calDisSlot()));
	connect(this, SIGNAL(cal2DGardSignal()), this, SLOT(cal2DGradSlot()));
	connect(this, SIGNAL(readData1Signal()), this, SLOT(readData1Slot()));
	connect(this, SIGNAL(readData2Signal()), this, SLOT(readData2Slot()));
	connect(this, SIGNAL(calBatchDisSignal()), this, SLOT(calBatchDisSlot()));
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

	if (btnname == "calGrad")
	{
		emit calGardSignal();
	}

	if (btnname == "calDis")
	{
		emit calDisSignal();
	}

	if (btnname == "data1")
	{
		emit readData1Signal();
	}


	if (btnname == "data2")
	{
		emit readData2Signal();
	}

	if (btnname == "2DGrad")
	{
		emit cal2DGardSignal();
	}
	if (btnname == "batchDis")
	{
		emit calBatchDisSignal();
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




void DataProcess::calGradSlot()
{
	int size = atoi(q2s(ui.le_size->text()).c_str());
	String save_path = newDir("Grad").append("/");
	String save_path_save = save_path;

		//Mat image_i = imread(q2s(imagePath_list.at(0)), 1);
		//String filename = "grad";
		for (int j =0; j < imageName_list.length()/2; j++)
		{
			Mat image_i = imread(q2s(imagePath_list.at(2*j)), 1);
			Mat image_j = imread(q2s(imagePath_list.at(2 * j+1)), 1);
			save_path_save.append(to_string(j)).append(".jpg");
			//qDebug() << "compare between 0 and" << j;
			emdGrad(image_i, image_j, save_path_save);
			//emdGrad_ap4(image_i, image_j, 1, save_path_save);
			save_path_save = save_path;
//filename = "grad";
			//emdGradPara(image_i, image_j, save_path);
		}


}

//emd距离，L1距离可视化实现
//
//void DataProcess::calDisSlot()
//{
//	int size = atoi(q2s(ui.le_size->text()).c_str());
//	String save_path = newDir("Dis").append("/");
//	String save_path_save = save_path;
//
//	String filename = save_path_save.append("dis.txt");
//	save_path_save = save_path;
//	String Imagename_emd = save_path_save.append("img_emd.jpg");
//	save_path_save = save_path;
//	String Imagename_l1 = save_path_save.append("img_l1.jpg");
//
//	fs.open(filename, fstream::in | fstream::out | fstream::trunc);
//	for (int i = 0; i < imageName_list.length(); i++)
//		fs << "	" << "img_" << i << "	";
//	//fs.close();
//
//	//for 可视化
//	vector<vector<float>> emd_res;
//	vector<vector<float>> l1_res;
//	float l1_max = INT_MIN;
//	float emd_max = INT_MIN;
//	float l1_min = INT_MAX;
//	float emd_min = INT_MAX;
//	float emd_ij = 0;
//	float l1_ij = 0;
//
//	for (int i = 0; i < imageName_list.length(); i ++)
//	{
//		Mat image_i = imread(q2s(imagePath_list.at(i)), 1);
//		fs << "img_" << i << ": ";
//		for (int j = 0; j < imageName_list.length(); j++)
//		{
//			Mat image_j = imread(q2s(imagePath_list.at(j)), 1);
//			emd_ij=emdDis(image_i,image_j);
//			if (emd_ij > emd_max)
//				emd_max = emd_ij;
//			if (emd_ij < emd_min)
//				emd_min = emd_ij;
//			if (j == 0)
//			{
//				vector<float> temp;
//				temp.push_back(emd_ij);
//				emd_res.push_back(temp);
//			}
//			else
//				emd_res.at(i).push_back(emd_ij);
//
//			l1_ij = l1Dis(image_i, image_j);
//			if (l1_ij > l1_max)
//				l1_max = l1_ij;
//			if (l1_ij < l1_min)
//				l1_min = l1_ij;
//			if (j == 0)
//			{
//				vector<float> temp;
//				temp.push_back(l1_ij);
//				l1_res.push_back(temp);
//			}
//			else
//				l1_res.at(i).push_back(l1_ij);
//
//			fs << emd_ij << "/" << l1_ij << "	";
//			qDebug() << i << ":" << j<<"\n";
//		}
//		fs << "\n";
//	}
//	fs.close();
//
//
//
//	//可视化
//	Mat emd_r_v = Mat::zeros(imageName_list.length() * 10, imageName_list.length() * 10, CV_32FC1);
//	Mat l1_r_v = Mat::zeros(imageName_list.length() * 10, imageName_list.length() * 10, CV_32FC1);
//
//	for (int i = 0; i < imageName_list.length(); i++)
//	{
//		for (int j = 0; j < imageName_list.length(); j++)
//		{
//			float t1 = emd_res.at(i).at(j) - emd_min;
//			float t2 = emd_max - emd_min;
//			float temp_emd_color =(int)( (emd_res.at(i).at(j) - emd_min) / (emd_max - emd_min) * 255);
//			float temp_l1_color = (int)((l1_res.at(i).at(j) - l1_min) / (l1_max - l1_min) * 255);
//
//			for (int m = 0; m < 9; m++){
//				for (int n = 0; n < 9; n++)
//				{
//					emd_r_v.at<float>(i * 10 + m, j * 10 + n) = temp_emd_color;
//					l1_r_v.at<float>(i * 10 + m, j * 10 + n) = temp_l1_color;
//				}
//			}
//
//		}
//	}
//	imwrite(Imagename_emd, emd_r_v);
//	imwrite(Imagename_l1, l1_r_v);
//
//}
//

void DataProcess::calDisSlot()
{
	int size = atoi(q2s(ui.le_size->text()).c_str());
		String save_path = newDir("Dis").append("/");
		String save_path_save = save_path;
	
		String filename_l1 = save_path_save.append("dis_l1.txt");
		save_path_save = save_path;
		String filename_l2 = save_path_save.append("dis_l2.txt");
		//save_path_save = save_path;
		//String filename_ap1 = save_path_save.append("dis_ap1.txt");
		//save_path_save = save_path;
		//String filename_ap2 = save_path_save.append("dis_ap2.txt");
		save_path_save = save_path;
		String filename_ap4 = save_path_save.append("dis_ap4.txt");
		save_path_save = save_path;
		String filename_ap4_k = save_path_save.append("dis_ap4_k.txt");
		//fs.open(filename, fstream::in | fstream::out | fstream::trunc);

		Mat data1(IMG_ROWS, IMG_COLS, CV_32FC1);
		Mat data2(IMG_ROWS, IMG_COLS, CV_32FC1);
		int sum_i = 0;
		int sum_j = 0;
		float k_i = 1;
		float k_j = 1;
		//Mat image_i = imread(q2s(imagePath_list.at(0)), 1);
		//Mat image_j = imread(q2s(imagePath_list.at(1)), 1);
		//emd_ij_ap = emdDis_ap2(image_i, image_j);
	
		for (int i = 0; i < imageName_list.length(); i ++)
		{
		//int i = 0;
			Mat image_i = imread(q2s(imagePath_list.at(i)), 1);
			sum_i = 0;
			for (int m = 0; m < image_i.rows; m++)
			{
				for (int n = 0; n < image_i.cols;n++)
				{
					sum_i += (int)((int)image_i.at<Vec3b>(m, n)[0])*0.3 + ((int)image_i.at<Vec3b>(m, n)[1])*0.59 + ((int)image_i.at<Vec3b>(m, n)[2])*0.11;
				}
			}


			for (int j = 0; j < imageName_list.length(); j++)
			{
				sum_j = 0;
				Mat image_j = imread(q2s(imagePath_list.at(j)), 1);
				for (int m = 0; m < image_j.rows; m++)
				{
					for (int n = 0; n < image_j.cols; n++)
					{
						sum_j += (int)((int)image_j.at<Vec3b>(m, n)[0])*0.3 + ((int)image_j.at<Vec3b>(m, n)[1])*0.59 + ((int)image_j.at<Vec3b>(m, n)[2])*0.11;
					}
				}

				k_i = 1; k_j = 1;
				if (sum_j > sum_i)
					k_i = (float)sum_j / sum_i;
				else
					k_j = (float)sum_i / sum_j;
				qDebug() << i << ":" << j << ":" << k_i << k_j;
				for (int m = 0; m < IMG_ROWS; m++)
				{
					for (int n = 0; n < IMG_COLS; n++)
					{
						data1.at<float>(m, n) = k_i*(((int)image_i.at<Vec3b>(m, n)[0])*0.3 + ((int)image_i.at<Vec3b>(m, n)[1])*0.59 + ((int)image_i.at<Vec3b>(m, n)[2])*0.11);
						data2.at<float>(m, n) = k_j*(((int)image_j.at<Vec3b>(m, n)[0])*0.3 + ((int)image_j.at<Vec3b>(m, n)[1])*0.59 + ((int)image_j.at<Vec3b>(m, n)[2])*0.11);
					}
				}

				float emd_ij_l1=emdDis(data1,data2,1);
				float emd_ij_l2 = emdDis(data1, data2,2);
				//float emd_ij_ap2 = emdDis_ap2(image_i, image_j);
				float emd_ij_ap4_k = emdDis_ap4(image_i, image_j);
				float emd_ij_ap4 = emdDis_ap4(data1, data2);
				fs.open(filename_l1, fstream::in | fstream::out | fstream::app);
				fs << emd_ij_l1 << "\n";// << "/" << emd_ij_ap;
				fs.close();

				fs.open(filename_l2, fstream::in | fstream::out | fstream::app);
				fs << emd_ij_l2 << "\n";// << "/" << emd_ij_ap;
				fs.close();
				//fs.open(filename_ap2, fstream::in | fstream::out | fstream::app);
				//fs <<emd_ij_ap2 << "\n";// << "/" << emd_ij_ap2 << "\n";
				//fs.close();
				fs.open(filename_ap4, fstream::in | fstream::out | fstream::app);
				fs << emd_ij_ap4 << "\n";// << "/" << emd_ij_ap << "\n";
				fs.close();
				fs.open(filename_ap4_k, fstream::in | fstream::out | fstream::app);
				fs << emd_ij_ap4_k << "\n";// << "/" << emd_ij_ap << "\n";
				fs.close();

				qDebug() << i << ":" << j<<"done！\n";
			}
		}
		fs.close();
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
	if (opt.compare("Dis") == 0)
		str_date.append("_dis");
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


void  DataProcess::readData1Slot()
{
	data1Path = QFileDialog::getOpenFileName(this, tr("Open txt"), ".", tr("txt Files(*.txt )"));
	if (data1Path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
		return;
	}
	qDebug() << "path:" << data1Path;
}

void  DataProcess::readData2Slot()
{
	data2Path = QFileDialog::getOpenFileName(this, tr("Open txt"), ".", tr("txt Files(*.txt )"));
	if (data2Path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
		return;
	}
	qDebug() << "path:" << data2Path;
}

void DataProcess::cal2DGradSlot()
{
	if (data1Path.size() == 0)
		data1Path = "C:/Users/lcy/Desktop/data1.txt";
	if (data2Path.size() == 0)
		data2Path = "C:/Users/lcy/Desktop/data2.txt";
	if (resPath.size() == 0)
		resPath = "C:/Users/lcy/Desktop";

	int size = atoi(q2s(ui.le_size->text()).c_str());
	String save_path = newDir("Dis").append("/");
	String save_path_save = save_path;

	String filename_l1 = save_path_save.append("dis_l1.txt");
	save_path_save = save_path;
	String filename_l2 = save_path_save.append("dis_l2.txt");
	save_path_save = save_path;
	String filename_ap1 = save_path_save.append("dis_ap1.txt");
	save_path_save = save_path;
	String filename_ap2 = save_path_save.append("dis_ap2.txt");

	ifstream fin1(q2s(data1Path));
	ifstream fin2(q2s(data2Path));
	string s;
	QString temp;
	QStringList dataList;
	Mat data1;
	Mat data2;

	if (getline(fin1, s))
	{
		temp = s2q(s);
		dataList = temp.split(",");
		int dim = dataList.size();
		data1=Mat(dim, dim, CV_32FC1);

		for (int i = 0; i < dim; i++)
		{
			data1.at<float>(0, i) = dataList[i].toFloat();
		}

		//int count = 1;
		for (int count = 1; count < dim;count++)
		//while (getline(fin1, s))
		{
			getline(fin1, s);
			temp = s2q(s);
			dataList = temp.split(",");
			for (int i = 0; i < dim; i++)
			{
					data1.at<float>(count, i) = dataList[i].toFloat();
			}
			//count++;
		}
	}

	
	if (getline(fin2, s))
	{
		temp = s2q(s);
		dataList = temp.split(",");
		int dim = dataList.size();
		data2 = Mat(dim, dim, CV_32FC1);

		for (int i = 0; i < dim; i++)
		{
			data2.at<float>(0, i) = dataList[i].toFloat();
		}

		//int count = 1;
		for (int count = 1; count < dim; count++)
		//while (getline(fin2, s))
		{
			getline(fin2, s);
			temp = s2q(s);
			dataList = temp.split(",");
			for (int i = 0; i < dim; i++)
			{
				data2.at<float>(count, i) = dataList[i].toFloat();
			}
			//count++;
		}
	}

	//for (int i = 0; i < data1.rows; i++)
	//{
	//	for (int j = 0; j < data1.cols; j++)
	//	{
	//		qDebug() << data1.at<float>(i, j) << "/" << data2.at<float>(i, j);
	//	}
	//}
	//计算emd距离
	float emd_l1 = emdDis(data1, data2, 1);
	float emd_l2 = emdDis(data1, data2, 2);
	float emd_dis_ap=emdDis_ap(data1, data2);
	float emd_dis_ap2 = emdDis_ap2(data1, data2);

	fs.open(filename_l1, fstream::in | fstream::out | fstream::app);
	fs << emd_l1 << "\n";// << "/" << emd_ij_ap;
	fs.close();
	fs.open(filename_l2, fstream::in | fstream::out | fstream::app);
	fs << emd_l2 << "\n";// << "/" << emd_ij_ap;
	fs.close();
	fs.open(filename_ap2, fstream::in | fstream::out | fstream::app);
	fs << emd_dis_ap << "\n";// << "/" << emd_ij_ap2 << "\n";
	fs.close();
	fs.open(filename_ap1, fstream::in | fstream::out | fstream::app);
	fs << emd_dis_ap2 << "\n";// << "/" << emd_ij_ap << "\n";
	fs.close();
	qDebug() << "done!";

	//计算二维梯度
	//emdGradRes(data1, data2, q2s(resPath));
}

void DataProcess::calBatchDisSlot()
{
	if (resPath.size() == 0)
		resPath = "C:/Users/lcy/Desktop";

	String save_path = newDir("Dis").append("/");
	String save_path_save = save_path;

	String filename_l1 = save_path_save.append("dis_l1.txt");
	save_path_save = save_path;
	String filename_l2 = save_path_save.append("dis_l2.txt");
	save_path_save = save_path;
	String filename_ap1 = save_path_save.append("dis_ap1.txt");
	save_path_save = save_path;
	String filename_ap2 = save_path_save.append("dis_ap2.txt");
	save_path_save = save_path;
	String filename_ap3 = save_path_save.append("dis_ap3.txt");
	save_path_save = save_path;
	String filename_ap4 = save_path_save.append("dis_ap4.txt");
	//ifstream fin1(q2s(data1Path));
	//ifstream fin2(q2s(data2Path));
	//string s;
	//QString temp;
	//QStringList dataList;
	Mat data1(IMG_ROWS, IMG_COLS, CV_32FC1);
	Mat data2(IMG_ROWS, IMG_COLS, CV_32FC1);

	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			data1.at<float>(i, j) = 10;
			data2.at<float>(i, j) = 10;
		}
	}

	time_t nowtime = time(NULL);
	String seconds = to_string(nowtime);

	fs.open(filename_l1, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds<<"---------------------" << "\n";
	fs.close();
	fs.open(filename_l2, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds << "---------------------" << "\n";
	fs.close();
	fs.open(filename_ap1, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds << "---------------------" << "\n";
	fs.close();
	fs.open(filename_ap2, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds << "---------------------" << "\n";
	fs.close();
	fs.open(filename_ap3, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds << "---------------------" << "\n";
	fs.close();
	fs.open(filename_ap4, fstream::in | fstream::out | fstream::app);
	fs << "---------------------" << seconds << "---------------------" << "\n";
	fs.close();

	for (int m = 1; m < 100; m++)
	//for (int m = 1; m < IMG_ROWS/2; m++)
	{
		//test1
		//data2.at<float>(0, 0) = 5; 
		//data2.at<float>(0, m) = 15;
		//test2
		//data2.at<float>(IMG_ROWS-1, 0) = 5;
		//data2.at<float>(IMG_ROWS-1, m) = 15;
		//test3
		//data2.at<float>(0, 0) = 5;
		//data2.at<float>(m, 0) = 15;
		//test4
		//data2.at<float>(0, IMG_ROWS - 1) = 5;
		//data2.at<float>(m, IMG_ROWS - 1) = 15;
		//test5
		//data2.at<float>(0, 0) = 5;
		//data2.at<float>(m, m) = 15;
		//test6
	/*	data2.at<float>(0, IMG_ROWS - 1) = 5;
		data2.at<float>(m, IMG_ROWS - m-1) = 15;*/
		//test7
		//data2.at<float>(IMG_ROWS/2, IMG_ROWS/2) = 5;
		//data2.at<float>(IMG_ROWS / 2+m, IMG_ROWS / 2+m) = 15;
		//test 8
		srand((unsigned)time(NULL));
		int pos1 = rand() % (IMG_ROWS*IMG_COLS);
		int pos2 = rand() % (IMG_ROWS*IMG_COLS);
		int randData = rand() % (20);
		data2.at<float>(pos1 / IMG_ROWS, pos1%IMG_ROWS) = randData;
		data2.at<float>(pos2 / IMG_ROWS, pos2%IMG_ROWS) = 20 - randData;

		//计算emd距离
		float emd_l1 = emdDis(data1, data2, 1);
		float emd_l2 = emdDis(data1, data2, 2);
		//float emd_dis_ap = emdDis_ap(data1, data2);
		//float emd_dis_ap2 = emdDis_ap2(data1, data2);
		//float emd_dis_ap3 = emdDis_ap3(data1, data2);
		float emd_dis_ap4 = emdDis_ap4(data1, data2);

		fs.open(filename_l1, fstream::in | fstream::out | fstream::app);
		fs << emd_l1 << "\n";// << "/" << emd_ij_ap;
		fs.close();
		fs.open(filename_l2, fstream::in | fstream::out | fstream::app);
		fs << emd_l2 << "\n";// << "/" << emd_ij_ap;
		fs.close();
		//fs.open(filename_ap1, fstream::in | fstream::out | fstream::app);
		//fs << emd_dis_ap << "\n";// << "/" << emd_ij_ap2 << "\n";
		//fs.close();
		//fs.open(filename_ap2, fstream::in | fstream::out | fstream::app);
		//fs << emd_dis_ap2 << "\n";// << "/" << emd_ij_ap << "\n";
		//fs.close();
		//fs.open(filename_ap3, fstream::in | fstream::out | fstream::app);
		//fs << emd_dis_ap3 << "\n";// << "/" << emd_ij_ap << "\n";
		//fs.close();
		fs.open(filename_ap4, fstream::in | fstream::out | fstream::app);
		fs << emd_dis_ap4 << "\n";// << "/" << emd_ij_ap << "\n";
		fs.close();

		//data2.at<float>(0, 0) = 10;
		//data2.at<float>(0, m) = 10;
		//data2.at<float>(IMG_ROWS - 1, 0) = 10;
		//data2.at<float>(IMG_ROWS - 1, m) = 10;
		////test3
		//data2.at<float>(0, 0) = 10;
		//data2.at<float>(m, 0) = 10;
		////test4
		//data2.at<float>(0, IMG_ROWS - 1) = 10;
		//data2.at<float>(m, IMG_ROWS - 1) = 10;
		////test5
		//data2.at<float>(0, 0) = 10;
		//data2.at<float>(m, m) = 10;
		////test6
		//data2.at<float>(0, IMG_ROWS - 1) = 10;
		//data2.at<float>(m, IMG_ROWS - m - 1) = 10;
		////test7
		//data2.at<float>(IMG_ROWS / 2, IMG_ROWS / 2) = 10;
		//data2.at<float>(IMG_ROWS / 2 + m, IMG_ROWS / 2 + m) = 10;

		//test8
		data2.at<float>(pos1 / IMG_ROWS, pos1%IMG_ROWS) = 10;
		data2.at<float>(pos2 / IMG_ROWS, pos2%IMG_ROWS) = 10;
		qDebug() << "done!";
	}
	qDebug() << "all done!";
}
