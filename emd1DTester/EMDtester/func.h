#pragma once
#define IMG_ROWS 40
#define IMG_COLS 40

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

QImage MatToQImage(const Mat&);

/**判断文件名的前部是否相同**/
bool sameName(const QString filename1, const QString filename2, int suffix);

//void drawHis(vector<float> data,  String title);

//void drawGradHis(vector<float> data, String title);

void saveTestData(vector<float> data1, vector<float> data2, vector<float> data3, float emd, Mat plan, String filename);
//void saveTestData(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, float emd, float emd_ap, Mat plan, String filename);

void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, String  filename);
//void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, String  filename);
//void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, vector<float> data5, String  filename);

float emd_ap(vector<float> SData, vector<float> DData);

int sumData(vector<float> Data);

float ph(vector<float> SData, vector<float> DData, int i);

vector<float> emdGrad_ap(vector<float> SData, vector<float> DData);

float emdGradSingle_ap(vector<float> SData, vector<float> DData, int k);
//float emdDis(Mat image_i, Mat image_j);
//
//Mat preEMD(Mat image_i);
//
//void emdGrad(Mat image_i, Mat image_j, String filepath);
//
//void emdGradPara(Mat image_i, Mat image_j, String filepath);
//
//
//float l1Dis(Mat image_i, Mat image_j);
//
//float l2Dis(Mat image_i, Mat image_j);