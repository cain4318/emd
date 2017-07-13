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

	QStringList imagePath_list;
	QStringList imageDir_list;
	QStringList imageName_list;


	private slots:
	void doClicked(const QString & btnname);
	void setRootPathSlot();
	void setResPathSlot();
	void doDemoSlot();
	void doAlignIterSlot();
	void doAlignSampSlot();
	void doICPSlot();

signals:
	void setRootPathSignal();
	void setResPathSignal();
	void doDemoSignal();
	void doAlignIterSignal();
	void doAlignSimpSignal();
	void doICPSignal();


public:
	void addSubFolderImages(QString path);
	/**创建结果文件夹 opt:rename  cut  resize**/
	String newDir(String opt);
	float alignProcess(int dis, Mat img_l, Mat img_r);
	float BottomAlignProcess(int dis, Mat img_l, Mat img_r);
	bool DataProcess::saveRes(String dir_name, String file_name, String mode,int dis, Mat image_L, Mat image_R);
};

#endif // DATAPROCESS_H
