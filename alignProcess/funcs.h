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
#include <vector>

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

/*�������*/
int calDis(vector<int> p1, vector<int> p2);
int calDis(vector<vector<int>> p1, vector<vector<int>> p2);

/*�㼯���Ļ�*/
vector<vector<int>> centerTrans(vector<vector<int>> p, vector<int> center);
vector<vector<int>> counterCenterTrans(vector<vector<int>> p, vector<int> center);
int centerTrans(int p_x, int center_x);
int counterCenterTrans(int p_x, int center_x);

/*���ƽ������*/
vector<int> getTrans(vector<int> aimPointCenter, vector<int> sourcePointCenter);

/*���xƽ��*/
int getTransX(vector<int> aimPointCenter, vector<int> sourcePointCenter);

/*��õ㼯����*/
//vector<int> getCenter(Mat img);
vector<int> getCenter(vector<vector<int>> points);

/*�������ƥ�䣬�õ�ƥ��㼯*/
Mat getAimPoint(Mat Lpoint, Mat Rpoint);
vector<vector<int>> getAimPoint(vector<vector<int>> &Lpoint, vector<vector<int>> &Rpoint);

/*�������*/
int ICPiterator(vector<vector<int>> &Lpoint, vector<vector<int>> &Rpoint);