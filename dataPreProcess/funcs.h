#pragma once

#include <QLabel>
#include <qbuttongroup.h>
#include <QMessageBox>  
#include <qfiledialog.h>
#include <qbuffer.h>
#include <QPushButton>  
#include <QMessageBox> 
#include <qstring.h>
#include <QDialogButtonBox>
#include <qsignalmapper.h>
#include <qdebug.h>
#include <qdiriterator.h>

#include <time.h>

#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>

using namespace std;
using namespace cv;

QString s2q(const string &s);

string q2s(const QString &s);

/**�ж��ļ�����ǰ���Ƿ���ͬ**/
bool sameName(const QString filename1, const QString filename2, int suffix);

/**��������ü�**/
Mat cut(Mat image, string flag);