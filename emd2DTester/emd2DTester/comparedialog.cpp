#include "comparedialog.h"
#include "ui_comparedialog.h"

compareDialog::compareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compareDialog)
{
    ui->setupUi(this);

	signalMapper = new QSignalMapper(this);
	connect(ui->btn_openimg1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_openimg1, "...");
	connect(ui->btn_openimg2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_openimg2, "....");
	connect(ui->btn_res, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_res, ".....");

	connect(ui->btn_caldiff, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_caldiff, "cal diff");

	connect(ui->btn_savediff, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_savediff, "save diff");

	connect(ui->btn_saveall, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui->btn_saveall, "save all");

	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(setimg1PathSignal()), this, SLOT(setimg1PathSlot()));
	connect(this, SIGNAL(setimg2PathSignal()), this, SLOT(setimg2PathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL(calDiffSignal()), this, SLOT(calDiffSlot()));
	connect(this, SIGNAL(saveDiffSignal()), this, SLOT(saveDiffSlot()));
	connect(this, SIGNAL(saveAllSignal()), this, SLOT(saveAllSlot()));


}

compareDialog::~compareDialog()
{
    delete ui;
}


void compareDialog::doClicked(const QString & btnname)
{
	if (btnname == "...")
		emit setimg1PathSignal();
	if (btnname == "....")
		emit setimg2PathSignal();
	if (btnname == ".....")
		emit setResPathSignal();
	if (btnname == "cal diff")
		emit calDiffSignal();
	if (btnname == "save diff")
		emit saveDiffSignal();
	if (btnname == "save all")
		emit saveAllSignal();
}

void compareDialog::setimg1PathSlot()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		"Open Image",
		QDir::currentPath(),
		"Images (*.png *.xpm *.jpg);;All files(*.*)");
	if (!filename.isNull()) { //用户选择了文件
		// 处理文件
		//qDebug() <<"filename:"<< filename;
		img1Path = filename;
		//QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);

		image_1 = imread(q2s(img1Path), 1);
		qimage_1 = new QImage;
		*qimage_1 = MatToQImage(image_1);
		ui->label_img1->setPixmap(QPixmap::fromImage(*qimage_1));
	}
	else // 用户取消选择
		QMessageBox::information(this, "Image", "No image", QMessageBox::Ok | QMessageBox::Cancel);

}

void compareDialog::setimg2PathSlot()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		"Open Image",
		QDir::currentPath(),
		"Images (*.png *.xpm *.jpg);;All files(*.*)");
	if (!filename.isNull()) { //用户选择了文件
		// 处理文件
		//qDebug() <<"filename:"<< filename;
		img2Path = filename;
		//QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);

		image_2 = imread(q2s(img2Path), 1);
		qimage_2 = new QImage;
		*qimage_2 = MatToQImage(image_2);
		ui->label_img2->setPixmap(QPixmap::fromImage(*qimage_2));
	}
	else // 用户取消选择
		QMessageBox::information(this, "Image", "No image", QMessageBox::Ok | QMessageBox::Cancel);

}

void compareDialog::setResPathSlot()
{
	QString file_path = QFileDialog::getExistingDirectory(this, "select save path...", "./");
	if (file_path.isEmpty())
	{
		return;
	}
	else{
		resPath = file_path;
		ui->t_res->setText(file_path);
	}

}
void compareDialog::calDiffSlot(){
	
	diffRes = calDiff(image_1, image_2);

	qimage_diff = new QImage;
	*qimage_diff = MatToQImage(diffRes);
	ui->label_imgdiff->setPixmap(QPixmap::fromImage(*qimage_diff));
}

void compareDialog::saveDiffSlot(){
	time_t nowtime = time(NULL);
	String filename = to_string(nowtime);
	filename.append(".jpg");

	String save_path = newDir(q2s(resPath),"savePair").append("/");
	save_path.append(filename);

	imwrite(save_path, diffRes);
}
void compareDialog::saveAllSlot(){
	time_t nowtime = time(NULL);
	String filename = to_string(nowtime);
	filename.append(".jpg");

	String save_path = newDir(q2s(resPath), "savePair").append("/");
	save_path.append(filename);

	savePairResult(image_1, image_2, diffRes,save_path);
}

void compareDialog::savePairResult(Mat image_r, Mat image_l, Mat diff, String filename){
	String save_path = newDir(q2s(resPath),"savePair").append("/");
	String save_path_save = save_path;
	save_path_save.append(filename);

	Mat res(diff.rows, diff.cols * 3, CV_8UC3);
	for (int i = 0; i < diff.rows; i++){
		for (int j = 0; j < diff.cols; j++){
			res.at<Vec3b>(i, j) = image_r.at<Vec3b>(i, j);
			res.at<Vec3b>(i, j + diff.cols) = image_l.at<Vec3b>(i, j);
			for (int c = 0; c < 3; c++)
				res.at<Vec3b>(i, j + diff.cols * 2)[c] = diff.at<uchar>(i, j);
		}
	}

	imwrite(save_path_save, res);
	save_path_save = save_path;
}


String compareDialog::newDir(String path, String opt)
{
	time_t tt = time(NULL);
	tm* t = localtime(&tt);
	String str_date = to_string(t->tm_mon + 1);
	str_date.append(to_string(t->tm_mday));

	String newDir_path = path.append("/");

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
			QMessageBox::information(this, ("mkdir"), ("create successfully!"));
	}
	return newDir_path;
}