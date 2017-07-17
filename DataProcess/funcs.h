#pragma once
#define IMG_ROWS 36
#define IMG_COLS 36

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

#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>

using namespace std;
using namespace cv;

QString s2q(const string &s);

string q2s(const QString &s);

/**判断文件名的前部是否相同**/
bool sameName(const QString filename1, const QString filename2, int suffix);

/**进行区域裁剪**/
Mat cut(Mat image, string flag);

float emdDis(Mat image_i, Mat image_j,int flag);

Mat preEMD(Mat image_i, int nC);

void emdGrad(Mat image_i, Mat image_j, String filepath);
float addDelta(Mat sig_i, Mat sig_j, int index, int delta);
//计算自定义的二维数据的emd
void emdGradRes(Mat image_i, Mat image_j, String filepath);



float l1Dis(Mat image_i, Mat image_j);

float l2Dis(Mat image_i, Mat image_j);


//emd 的近似实现
float emdDis_ap(Mat image_a, Mat image_b);


float ph(Mat image_a, Mat image_b, int index, int total_a, int total_b);

void emdGrad_ap(Mat image_a, Mat image_b, float delta,String filename);

float emdGradPixal_ap(Mat image_a, Mat image_b, int rowInd, int colInd, float delta);


//emd 近似实现2
float emdDis_ap2(Mat image_a, Mat image_b);
float ph2(Mat image_a, Mat image_b, int index, int total_a, int total_b);
float emdGradPixal_ap2(Mat image_a, Mat image_b, int rowInd, int colInd, float delta);

vector<int> center2left(int x, int y, int transDis);
vector<int> left2center(int i, int j, int transDis);

//emd 近似实现3
float emdDis_ap3(Mat image_a, Mat image_b);
float ph3(Mat image_a, Mat image_b, int index, int total_a, int total_b,int flag);

//emd 近似实现4
float emdDis_ap4(Mat image_a, Mat image_b);
float ph4(Mat image_a, Mat image_b, int index, int total_a, int total_b, int flag);
void emdGrad_ap4(Mat image_a, Mat image_b, float delta, String filename);
float emdGradPixal_ap4(Mat SData, Mat DData, int rowInd, int colInd, float delta);

//emd 近似实现2
float emdDis_ap5(Mat image_a, Mat image_b);
//float ph5(Mat image_a, Mat image_b, Mat* disMap, int index, int total_a, int total_b, float last_ph);
void emdGrad_ap5(Mat image_a, Mat image_b, float delta, String filename);
float emdGradPixal_ap5(Mat image_a, Mat image_b, int rowInd, int colInd, float delta);
vector<int> findMinInAll(Mat Data, vector<int> colMins);
vector<int> findMinInCols(Mat Data, int colIndex, vector<int> colMins);