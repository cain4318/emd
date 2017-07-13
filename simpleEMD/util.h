#ifndef H_UTIL
#define H_UTIL

#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <random>

#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>
#include "emd.h"

using namespace cv;
using namespace std;
float dist(feature_t *F1, feature_t *F2);
float dist(float p1, float p2);

void drawHis(float data[], int size, String title);

void addDelta(signature_t *Signature, float delta, int index);

void addDelta(Mat *Signature, float delta, int index);

void calGrad(signature_t *Signature1, signature_t *Signature2,
	float(*func)(feature_t *, feature_t *), float Delta, String title);

void saveBasicInfo(signature_t *Signature1, signature_t *Signature2,
	float(*func)(feature_t *, feature_t *), float Delta, String filename,bool showCostMartx);
void saveImage(float data1[], float data2[], float data3[], int size, String  filename);

#endif