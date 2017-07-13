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
	void doRenameSlot();
	void doCutSlot();
	void doPlusSlot();
	void doResizeSlot();
	void doRenameAllSlot();

	void doSclarSlot();

signals:
	void setRootPathSignal();
	void setResPathSignal();
	void doRenameSignal();
	void doCutSignal();
	void doPlusSignal();
	void doResizeSignal();
	void doRenameAllSignal();

	void doSclarSignal();

public:
	void addSubFolderImages(QString path);
	/**��������ļ��� opt:rename  cut  resize**/
	String newDir(String opt);
};

#endif // DATAPROCESS_H
