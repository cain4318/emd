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
	int suffix = 5;

	QStringList imagePath_list;
	QStringList imageDir_list;
	QStringList imageName_list;


private slots:
	void doClicked(const QString & btnname);
	void setRootPathSlot();
	void setResPathSlot();
	

signals:
	void setRootPathSignal();
	void setResPathSignal();


public:
	void addSubFolderImages(QString path);
	/**创建结果文件夹 opt:rename  cut  resize**/
	String newDir(String opt);
};

#endif // DATAPROCESS_H
