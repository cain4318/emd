#ifndef COMPAREDIALOG_H
#define COMPAREDIALOG_H

#include <QDialog>
#include "funcs.h"

namespace Ui {
class compareDialog;
}

class compareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit compareDialog(QWidget *parent = 0);
    ~compareDialog();

private:
    Ui::compareDialog *ui;
public:
	QSignalMapper *signalMapper;
	QString img1Path;
	QString img2Path;
	QString resPath;

	QImage* qimage_1 = NULL;
	QImage* qimage_2 = NULL;
	QImage *qimage_diff = NULL;

	Mat image_1;
	Mat image_2;
	Mat diffRes;


	private slots:
	void doClicked(const QString & btnname);
	void setimg1PathSlot();
	void setimg2PathSlot();
	void setResPathSlot();
	
	void calDiffSlot();
	void saveDiffSlot();
	void saveAllSlot();

signals:
	void setimg1PathSignal();
	void setimg2PathSignal();
	void setResPathSignal();

	void calDiffSignal();
	void saveDiffSignal();
	void saveAllSignal();
public:
	String compareDialog::newDir(String path, String opt);
	void savePairResult(Mat image_r, Mat image_l, Mat grad, String filename);
};

#endif // COMPAREDIALOG_H
