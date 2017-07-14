#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_emd2dtester.h"
#include "funcs.h"

class emd2DTester : public QMainWindow
{
    Q_OBJECT

public:
    emd2DTester(QWidget *parent = Q_NULLPTR);
	~emd2DTester();

private:
    Ui::emd2DTesterClass ui;
public:
	QSignalMapper *signalMapper;
	QString rootPath;
	QString resPath;
	int pairIndex = 0;
	int radius = 0;
	float weightSum = 0;

	QStringList imagePath_list;
	QStringList imageDir_list;
	QStringList imageName_list;

	QImage* qimage_left = NULL;
	QImage* qimage_right = NULL;
	QImage *qimage_grad = NULL;

	Mat image_l;
	Mat image_r;
	Mat gradRes;

	vector<float> lineEmds;
	vector<float> weights;

	private slots:
	void doClicked(const QString & btnname);
	void setRootPathSlot();
	void setResPathSlot();
	void setPairIndexSlot(int index);
	void setRadiusSlot(int r);

	void calPairSlot();
	void savePairSlot();
	void saveGradSlot();
	void calsaveAllSlot();

signals:
	void setRootPathSignal();
	void setResPathSignal();

	void calPairSignal();
	void savePairSignal();
	void saveGradSignal();
	void calsaveAllSignal();


public:
	void addSubFolderImages(QString path);
	/**创建结果文件夹 opt:rename  cut  resize**/
	String newDir(String opt);
	vector<float> calLineEmds(Mat image_r, Mat image_l);
	vector<float> initData(Mat data, int lineInd);
	Mat calGrad(Mat image_r, Mat image_l, float delta, bool visilize);
	void savePairResult(Mat image_r, Mat image_l, Mat grad, String filename);
};
