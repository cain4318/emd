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

	connect(ui.btn_savegrad, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_savegrad, "save grad");

	connect(ui.btn_calsaveall, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calsaveall, "cal and save all");


	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(ui.sb_index, SIGNAL(valueChanged(int)), this, SLOT(setPairIndexSlot(int)));
	connect(ui.sb_radius, SIGNAL(valueChanged(int)), this, SLOT(setRadiusSlot(int)));
	connect(this, SIGNAL(calPairSignal()), this, SLOT(calPairSlot()));
	connect(this, SIGNAL(savePairSignal()), this, SLOT(savePairSlot()));
	connect(this, SIGNAL(saveGradSignal()), this, SLOT(saveGradSlot()));
	connect(this, SIGNAL(calsaveAllSignal()), this, SLOT(calsaveAllSlot()));
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
	if (btnname == "save grad")
		emit saveGradSignal();
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
	
	str_date.append("_").append(opt);

	newDir_path.append(str_date);


	QDir *temp = new QDir;
	bool exist = temp->exists(s2q(newDir_path));
	if (!exist)
		//QMessageBox::warning(this, tr("mkdir"), tr("allready exist!"));
	//else
	{
		bool ok = temp->mkdir(s2q(newDir_path));
		if (ok)
			QMessageBox::warning(this, tr("mkdir"), tr("create successfully!"));
	}
	return newDir_path;
}

void emd2DTester::setPairIndexSlot(int index){
	if (index <= imagePath_list.size() / 2)
		pairIndex = index - 1;
	else{
	QMessageBox::warning(this, tr("warning"), tr("the index is out of range"), QMessageBox::Yes | QMessageBox::No);
	ui.sb_index->setValue(pairIndex);
}

	image_l = imread(q2s(imagePath_list.at(2 * pairIndex)), 1);
	image_r = imread(q2s(imagePath_list.at(2 * pairIndex + 1)), 1);

	qimage_left = new QImage;
	qimage_right = new QImage;
	*qimage_left = MatToQImage(image_l);
	ui.label_imgleft->setPixmap(QPixmap::fromImage(*qimage_left));
	*qimage_right = MatToQImage(image_r);
	ui.label_imgright->setPixmap(QPixmap::fromImage(*qimage_right));
}

void emd2DTester::setRadiusSlot(int r)
{
	radius = r;
}

void emd2DTester::calPairSlot(){
	lineEmds.clear();


	//获得权重
	QString data = ui.t_weights->toPlainText();
	QStringList dataList = data.split(",");
	int total_line = dataList.size();


	if (total_line<radius*2+1)
		QMessageBox::warning(this, tr("error"), tr("weight data not enough"), QMessageBox::Yes | QMessageBox::No);
	else{
		weights.clear();
		weightSum = 0;
		for (int i = 0; i < radius * 2 + 1; i++)
		{
			float temp_data = dataList.at(i).toFloat();
			weights.push_back(temp_data);
			weightSum += temp_data;
		}
	}

	image_l = imread(q2s(imagePath_list.at(2 * pairIndex)), 1);
	image_r = imread(q2s(imagePath_list.at(2 * pairIndex + 1)), 1);

	//计算行emd
	lineEmds = calLineEmds(image_r, image_l);
	//for (int i = 0; i < image_r.rows; i++)
	//{
	//	//初始source数据
	//	vector<float> SData = initData(image_r, i);
	//	vector<float> TData;
	//	float remp_lineemd = 0;
	//	for (int j = -radius; j <= radius; j++)
	//	{
	//		int neigInd = i + j;
	//		if (neigInd < 0)
	//			neigInd = 0;
	//		if (neigInd >= image_r.rows)
	//			neigInd = image_r.rows - 1;
	//		TData = initData(image_l, neigInd);
	//		float emdDis_ap = emd_ap(TData, SData);
	//		remp_lineemd = emdDis_ap*weights.at(j + radius);
	//	}
	//	lineEmds.push_back(remp_lineemd);
	//}

	//显示行emd
	float sum_lineemd = 0;
	String line_emd_content = "";
	for (int l = 0; l < lineEmds.size(); l++)
	{
		float temp_lineemd = lineEmds.at(l);
		sum_lineemd += temp_lineemd;
		line_emd_content.append(to_string(temp_lineemd));
		line_emd_content.append(";\n");
	}
	sum_lineemd = sum_lineemd / lineEmds.size();
	ui.t_lineemd->setText(s2q(line_emd_content));
	ui.label_avgemd->setText(s2q(to_string(sum_lineemd)));
	
	//显示梯度信息
	gradRes = calGrad(image_r, image_l, 1, true);
	qimage_grad = new QImage;
	*qimage_grad = MatToQImage(gradRes);
	ui.label_imggrad->setPixmap(QPixmap::fromImage(*qimage_grad));
	//float maxGrad = INT_MIN;
	//float minGrad = INT_MAX;
	//for (int i = 0; i < image_r.rows; i++)
	//{
	//	vector<float> SData = initData(image_r, i);
	//	for (int j = 0; j < image_r.cols; j++)
	//	{

	//	
	//	vector<float> TData;
	//	float remp_lineemd = 0;
	//	for (int j = -radius; j <= radius; j++)
	//	{
	//		int neigInd = i + j;
	//		if (neigInd < 0)
	//			neigInd = 0;
	//		if (neigInd >= image_r.rows)
	//			neigInd = image_r.rows - 1;
	//		TData = initData(image_l, neigInd);
	//		float emdDis_ap = emd_ap(TData, SData);
	//		remp_lineemd = emdDis_ap*weights.at(j + radius);
	//	}
	//	
	//		
	//	}
	//}

}

vector<float> emd2DTester::initData(Mat data, int lineInd)
{
	vector<float> sig;

	for (int d = 0; d < data.cols; d++)
	{
		int temp_data;
		if (data.channels() == 3)
			temp_data = (int)((int)data.at<Vec3b>(lineInd, d)[0])*0.3 + ((int)data.at<Vec3b>(lineInd, d)[1])*0.59 + ((int)data.at<Vec3b>(lineInd, d)[2])*0.11;
		if (data.channels() == 1)
			temp_data = data.at<float>(lineInd, d);

			sig.push_back(temp_data);
			/*sig.at<float>(d * 2) = temp_data;
	sig.at<float>(d * 2 + 1) = d;*/
	}
	return sig;
}

vector<float> emd2DTester::calLineEmds(Mat image_r, Mat image_l){
	vector<float> lineEmds;
	for (int i = 0; i < image_r.rows; i++)
	{
		//初始source数据
		vector<float> SData = initData(image_r, i);
		vector<float> TData;
		float remp_lineemd = 0;
		for (int j = -radius; j <= radius; j++)
		{
			int neigInd = i + j;
			if (neigInd < 0)
				neigInd = 0;
			if (neigInd >= image_r.rows)
				neigInd = image_r.rows - 1;
			TData = initData(image_l, neigInd);
			float emdDis_ap = emd_ap(TData, SData);
			remp_lineemd = emdDis_ap*weights.at(j + radius);
		}
		remp_lineemd = remp_lineemd / weightSum;
		lineEmds.push_back(remp_lineemd);
	}
	return lineEmds;
}

Mat emd2DTester::calGrad(Mat image_r, Mat image_l,float delta,bool visilize){
	Mat grad(image_r.size(), CV_32FC1);
	Mat grad2(image_r.size(), CV_8UC1);
	vector<int> pos;
	float maxGrad = INT_MIN;
	float minGrad = INT_MAX;
	int N = image_r.cols;

	if (lineEmds.size() == 0)
		lineEmds = calLineEmds(image_r, image_l);

	for (int i = 0; i < image_r.rows; i++)
	{
		vector<float> SData = initData(image_r, i);
		for (int j = 0; j < image_r.cols; j++)
		{
			pos.clear();
			//增量
			for (int m = 0; m < image_r.cols; m++)
			{
				if (m == j)
					SData.at(m) += (N - 1)*delta;
				else
				{
					if (SData.at(m) >= delta)
						SData.at(m) -= delta;
					else{
						SData.at(j) -= delta;
						pos.push_back(m);
					}
				}
			}

			vector<float> TData;
			float temp_lineemd = 0;
			for (int j = -radius; j <= radius; j++)
			{
				int neigInd = i + j;
				if (neigInd < 0)
					neigInd = 0;
				if (neigInd >= image_r.rows)
					neigInd = image_r.rows - 1;
				TData = initData(image_l, neigInd);
				float emdDis_ap = emd_ap(TData, SData);
				temp_lineemd = emdDis_ap*weights.at(j + radius);
			}
			temp_lineemd = temp_lineemd / weightSum;
			float temp_grad = (temp_lineemd - lineEmds.at(i)) / (N - 1 - pos.size());
			if (temp_grad > maxGrad)
				maxGrad = temp_grad;
			if (temp_grad < minGrad)
				minGrad = temp_grad;
			grad.at<float>(i, j) = temp_grad;
		}
	}

	if (visilize)
	{
		for (int i = 0; i < grad.rows; i++){
			for (int j = 0; j < grad.cols; j++){
			
				float temp_grad = grad.at<float>(i, j);
				temp_grad = (temp_grad - minGrad) / (maxGrad - minGrad) * 255;
				grad2.at<uchar>(i, j) = (int)temp_grad;
			}
		}

		return grad2;
	}


	return grad;
}

void emd2DTester::savePairSlot(){
	time_t nowtime = time(NULL);
	String filename = to_string(nowtime);
	filename.append(".jpg");
	savePairResult(image_r, image_l, gradRes, filename);
}

void emd2DTester::savePairResult(Mat image_r, Mat image_l, Mat grad, String filename){
		String save_path = newDir("savePair").append("/");
		String save_path_save = save_path;
		save_path_save.append(filename);

		Mat res(grad.rows, grad.cols * 3, CV_8UC3);
		for (int i = 0; i < grad.rows; i++){
			for (int j = 0; j < grad.cols; j++){
				res.at<Vec3b>(i, j) = image_r.at<Vec3b>(i, j);
				res.at<Vec3b>(i, j+grad.cols) = image_l.at<Vec3b>(i, j);
				for (int c = 0; c < 3;c++)
					res.at<Vec3b>(i, j + grad.cols * 2)[c] = grad.at<uchar>(i, j);
			}
		}

		imwrite(save_path_save, res);
		save_path_save = save_path;
}
void emd2DTester::saveGradSlot(){
	time_t nowtime = time(NULL);
	String filename = to_string(nowtime);
	filename.append(".jpg");

	String save_path = newDir("savePair").append("/");
	save_path.append(filename);

	imwrite(save_path, gradRes);
}
void emd2DTester::calsaveAllSlot(){
	for (pairIndex = 0; pairIndex < imagePath_list.size() / 2; pairIndex++)
	{
		image_l = imread(q2s(imagePath_list.at(2 * pairIndex)), 1);
		image_r = imread(q2s(imagePath_list.at(2 * pairIndex + 1)), 1);

		qimage_left = new QImage;
		qimage_right = new QImage;
		*qimage_left = MatToQImage(image_l);
		ui.label_imgleft->setPixmap(QPixmap::fromImage(*qimage_left));
		*qimage_right = MatToQImage(image_r);
		ui.label_imgright->setPixmap(QPixmap::fromImage(*qimage_right));
		calPairSlot();
		savePairSlot();
	}
}