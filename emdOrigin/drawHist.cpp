#define DATA_SIZE 10
#include <stdio.h>
#include <math.h>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>

#include "emd.h"

using namespace cv;
float dist(feature_t *F1, feature_t *F2)
{
	int dX = F1->x - F2->x;
	return sqrt(double(dX*dX));
}

void drawHis(float data[],int size,String title){

	int bins = size;
	int hist_size[] = { bins };

	float max = data[0];
	for (int i = 0; i < size; i++)
	{
		if (data[i]>max)
			max = data[i];
	}

	int scale = 30;
	int hist_height = 200;
	Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
	for (int i = 0; i<bins; i++)
	{
		float bin_val = data[i];
		int intensity = cvRound(bin_val*hist_height / max);  //要绘制的高度
		rectangle(hist_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			255);
	}
	imshow(title, hist_img);
	cvWaitKey();
}


int main()
{

	feature_t   f1[DATA_SIZE] = { 0 }, f2[DATA_SIZE] = { 0 }, f3[DATA_SIZE] = { 0 };
	float       w1[DATA_SIZE] = {10,9,7,6,5,4,3,2,1,1}, w2[DATA_SIZE] = {1,1,1,1,1,3,5,6,7,12}, w3[DATA_SIZE] = {1,1,2,3,4,6,8,10,5,4};
	for (int i = 0; i < DATA_SIZE; i++)
	{
		f1[i].x = i;
		f2[i].x = i;
		f3[i].x = i;
	}
	drawHis(w1, DATA_SIZE, "data1");
	drawHis(w2, DATA_SIZE, "data2");
	drawHis(w3, DATA_SIZE, "data3");

	signature_t s1 = { DATA_SIZE, f1, w1 }, s2 = { DATA_SIZE, f2, w2 }, s3 = { DATA_SIZE, f3, w3 };
	float       e_s1s2,e_s1s3;

	e_s1s2 = emd(&s1, &s2, dist, 0, 0,0);
	printf("emd_s1s2=%f\n", e_s1s2);

	int size = s1.n*s2.n;
	int* result = new int[size];
	emd(&s1, &s2, dist, 0, 0, result);

	e_s1s3 = emd(&s1, &s3, dist, 0, 0,0);
	printf("emd_s1s3=%f\n", e_s1s3);
	return 0;
}
