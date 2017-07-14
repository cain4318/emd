#ifndef EMDTESTER_H
#define EMDTESTER_H

#include <QtWidgets/QMainWindow>
#include <time.h> 
#include "ui_emdtester.h"
#include "func.h"

class EMDtester : public QMainWindow
{
	Q_OBJECT

public:
	EMDtester(QWidget *parent = 0);
	~EMDtester();

private:
	Ui::EMDtesterClass ui;

public:
	QSignalMapper *signalMapper;
	QString supplyData;
	QString demandData;
	QString rootPath;
	QString resPath;
	int ndim = 1;

	Mat sigS;// (DATA_SIZE, 2, CV_32FC1);
	Mat sigD;// (DATA_SIZE, 2, CV_32FC1);
	Mat plan;
	vector<float> Sdata;
	vector<float> Ddata;
	vector<float> gradRes;
	vector<float> gradRes_ap;
	vector<float> gradRes_aap;

	int sumSupply = 0;
	int select_Ssum = 0;
	int sumDemand = 0;
	int select_Dsum = 0;
	float emdDis = 0;
	float emdDis_ap = 0;
	float delta = 1;
	////文件处理
	//QStringList imagePath_list;
	//QStringList imageDir_list;
	//QStringList imageName_list;
	//fstream fs;
	time_t nowtime;
	String savePath = "savedData/";
	String savePath_ap = "savedApData/";
private slots:
	void doClicked(const QString & btnname);
	void changeDimNumSlot(int);
	void showSupplyDistributeSlot(bool showHis);
	void showDemandDistributeSlot(bool showHis);
	void generateRandDataSlot();

	void calEMDDisSlot();
	void calEMDGradSlot();
	void calApEMDDisSlot();
	void calAApEMDGradSlot();
	void calApEMDGradSlot();
	void saveTestResSlot();
	void saveApTestResSlot();

	void setRootPathSlot();
	void setResPathSlot();
	void loadSingleDataSlot();
	void loadBatchDataSlot();


signals:
	void showSupplyDistributeSignal(bool showHis);
	void showDemandDistributeSignal(bool showHis);
	void generateRandDataSignal();

	void calEMDDisSignal();
	void calEMDGradSignal();
	void calApEMDDisSignal();
	void calApEMDGradSignal();
	void saveTestResSignal();
	void saveApTestResSignal();

	void setRootPathSignal();
	void setResPathSignal();
	void loadSingleDataSignal();
	void loadBatchDataSignal();



public:
	Mat initData(vector<float> data, int ndim);
	float calDeltaGrad(int index, String method);
	//void addSubFolderImages(QString path);
	/**创建结果文件夹 opt:rename  cut  resize**/
	//String newDir(String opt);
};

#endif // DATAPROCESS_H

