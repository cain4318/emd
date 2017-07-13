#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#include <QtWidgets/QMainWindow>
#include "ui_dataprocess.h"

#include "funcs.h"

class DataProcess : public QMainWindow
{
	Q_OBJECT

public:
	DataProcess(QWidget *parent = 0);
	~DataProcess();

private:
	Ui::DataProcessClass ui;
	
public:
	QSignalMapper *signalMapper;
	QString rootPath;
	QString resPath;
	QString data1Path;
	QString data2Path;
	int suffix = 5;

	QStringList imagePath_list;
	QStringList imageDir_list;
	QStringList imageName_list;
	fstream fs;

private slots:
	void doClicked(const QString & btnname);
	void setRootPathSlot();
	void setResPathSlot();

	void calGradSlot();
	void calDisSlot();
	void readData1Slot();
	void readData2Slot();
	void cal2DGradSlot();
	void calBatchDisSlot();

signals:
	void setRootPathSignal();
	void setResPathSignal();

	void calGardSignal();
	void calDisSignal();
	void readData1Signal();
	void readData2Signal();
	void cal2DGardSignal();
	void calBatchDisSignal();


public:
	void addSubFolderImages(QString path);
	/**创建结果文件夹 opt:rename  cut  resize**/
	String newDir(String opt);
};

#endif // DATAPROCESS_H
