/* example1.c */

#define IMG_SIZE   2
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

int main()
{
	Mat image1= imread("d:/demo1.jpg", 1);
	Mat image2 = imread("d:/demo2.jpg", 1);
	Mat image3 = imread("d:/demo3.jpg", 1);
	/*imshow("image", image);*/
	//for (int i = 0; i < image.rows; i++){
	//	for (int j = 0; j < image.cols; j++)
	//	{
	//		int r = image.at<Vec3b>(i, j)[0];
	//		int g = image.at<Vec3b>(i, j)[1];
	//		int b = image.at<Vec3b>(i, j)[2];
	//		printf("%d;;%d;;%d;;\n",r,g,b);
	//	}
	//}

	feature_t   f1[IMG_SIZE * IMG_SIZE] = { { 0, 0 } }, f2[IMG_SIZE * IMG_SIZE] = { { 0, 0 } }, f3[IMG_SIZE * IMG_SIZE] = { { 0, 0 } };
	float       w1[IMG_SIZE * IMG_SIZE] = { 0 }, w2[IMG_SIZE * IMG_SIZE] = { 0 }, w3[IMG_SIZE * IMG_SIZE] = { 0 };
	for (int i = 0; i < IMG_SIZE; i++)
	{
		for (int j = 0; j < IMG_SIZE; j++)
		{
			f1[i * IMG_SIZE + j] = { i, j };
			f2[i * IMG_SIZE + j] = { i, j };
			f3[i * IMG_SIZE + j] = { i, j };
			w1[i * IMG_SIZE + j] = ((int)(image1.at<Vec3b>(i, j)[0]) + (int)(image1.at<Vec3b>(i, j)[1]) + (int)(image1.at<Vec3b>(i, j)[2])) / 3;
			w2[i * IMG_SIZE + j] = ((int)(image2.at<Vec3b>(i, j)[0]) + (int)(image2.at<Vec3b>(i, j)[1]) + (int)(image2.at<Vec3b>(i, j)[2])) / 3;
			w3[i * IMG_SIZE + j] = ((int)(image3.at<Vec3b>(i, j)[0]) + (int)(image3.at<Vec3b>(i, j)[1]) + (int)(image3.at<Vec3b>(i, j)[2])) / 3;
		}
	}

	//float *w1 = new float[3];
	//float *w2 = new float[4];

	//w1[0] = 1; w1[1] = 2; w1[2] = 3;
	//w2[0] = 1; w2[1] = 2; w2[2] = 3; w2[3] = 4;

	signature_t s1 = { IMG_SIZE * IMG_SIZE, f1, w1 },
		s2 = { IMG_SIZE * IMG_SIZE, f2, w2 };
	float       e;

	e = emd(&s1, &s2, dist, 0, 0);

	printf("emd=%f\n", e);
	return 0;
}
