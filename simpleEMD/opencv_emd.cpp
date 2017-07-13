
#define ROWS 40
#define COLS 40
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>
#include <time.h>
#include "emd.h"

using namespace cv;
using namespace std;



int main()
{
	//load 3 images
	Mat image1 = imread("test1.jpg", 1);
	Mat image2 = imread("test2.jpg", 1);
	Mat image3 = imread("test3.jpg", 1);
	Mat image4 = imread("test4.jpg", 1);

	//make signature
	int size = ROWS*COLS;
	//Mat sig1(size, 3, CV_32FC1);
	//Mat sig2(size, 3, CV_32FC1);
	Mat sig3(size, 3, CV_32FC1);
	Mat sig4(size, 3, CV_32FC1);
	Mat grad34_emd = Mat::zeros(ROWS, COLS, CV_32FC1);
	Mat grad34_l1 = Mat::zeros(ROWS, COLS, CV_32FC1);
	Mat grad34_l2 = Mat::zeros(ROWS, COLS, CV_32FC1);
	Mat grad34_emd_img = Mat::zeros(ROWS, COLS, CV_32FC1);
	Mat grad34_l1_img = Mat::zeros(ROWS, COLS, CV_32FC1);
	Mat grad34_l2_img = Mat::zeros(ROWS, COLS, CV_32FC1);
	//Mat grad4 = Mat::zeros(ROWS, COLS, CV_32FC1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			/*sig1.at<float>(3 * (i*ROWS + j)) = (int)((int)image1.at<Vec3b>(i, j)[0])*0.3 + ((int)image1.at<Vec3b>(i, j)[1])*0.59 + ((int)image1.at<Vec3b>(i, j)[2])*0.11;
			sig1.at<float>(3 * (i*ROWS + j)+1) = i;
			sig1.at<float>(3 * (i*ROWS + j)+2) = j;

			sig2.at<float>(3 * (i*ROWS + j)) = (int)((int)image2.at<Vec3b>(i, j)[0])*0.3 + ((int)image2.at<Vec3b>(i, j)[1])*0.59 + ((int)image2.at<Vec3b>(i, j)[2])*0.11;
			sig2.at<float>(3 * (i*ROWS + j) + 1) = i;
			sig2.at<float>(3 * (i*ROWS + j) + 2) = j;
*/
			sig3.at<float>(3 * (i*ROWS + j)) = (int)((int)image3.at<Vec3b>(i, j)[0])*0.3 + ((int)image3.at<Vec3b>(i, j)[1])*0.59 + ((int)image3.at<Vec3b>(i, j)[2])*0.11;
			sig3.at<float>(3 * (i*ROWS + j) + 1) = i;
			sig3.at<float>(3 * (i*ROWS + j) + 2) = j;

			sig4.at<float>(3 * (i*ROWS + j)) = (int)((int)image4.at<Vec3b>(i, j)[0])*0.3 + ((int)image4.at<Vec3b>(i, j)[1])*0.59 + ((int)image4.at<Vec3b>(i, j)[2])*0.11;
			sig4.at<float>(3 * (i*ROWS + j) + 1) = i;
			sig4.at<float>(3 * (i*ROWS + j) + 2) = j;
		}
	}

	//计算emd
	//float emd_12 = cv::EMD(sig1, sig2, CV_DIST_L2, 0, 0); 
	float emd_34 = cv::EMD(sig3, sig4, CV_DIST_L2, 0, 0);
	/*float emd_13 = cv::EMD(sig1, sig3, CV_DIST_L2, 0, 0); 
	float emd_14 = cv::EMD(sig1, sig4, CV_DIST_L2, 0, 0); 
	float emd_23 = cv::EMD(sig2, sig3, CV_DIST_L2, 0, 0);
	float emd_24 = cv::EMD(sig2, sig4, CV_DIST_L2, 0, 0);*/



	//printf("emd_12:%f\n", emd_12);
	printf("emd_34:%f\n", emd_34);
	/*printf("emd_13:%f\n", emd_13);
	printf("emd_14:%f\n", emd_14);
	printf("emd_23:%f\n", emd_23);
	printf("emd_24:%f\n", emd_24);*/

	float  temp_emdGrad_34 = 0;
	//float temp_emdGrad_34 = 0;
	float temp_emdGrad_max = INT_MIN;
	float temp_emdGrad_min = INT_MAX;

	float temp_l2Grad_34 = 0;
	float temp_l2Grad_max = INT_MIN;
	float temp_l2Grad_min = INT_MAX;

	time_t start, stop;
	//求解梯度
	int count = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			start = time(NULL);
			sig3.at<float>(3 * (i*ROWS + j)) += 10;
			float delta_emd = cv::EMD(sig3, sig4, CV_DIST_L2, 0, 0);
			temp_emdGrad_34 = (delta_emd - emd_34)/10;
			sig3.at<float>(3 * (i*ROWS + j)) -= 10;

			grad34_emd.at<float>((i*ROWS + j)) = temp_emdGrad_34;
			if (temp_emdGrad_34 > temp_emdGrad_max)
				temp_emdGrad_max = temp_emdGrad_34;
			if (temp_emdGrad_34 < temp_emdGrad_min)
				temp_emdGrad_min = temp_emdGrad_34;

			float temp_x1 = sig3.at<float>(3 * (i*ROWS + j));
			float temp_x2 = sig4.at<float>(3 * (i*ROWS + j));
			grad34_l1.at<float>((i*ROWS + j)) = (abs(temp_x1 + 10 - temp_x2) - abs(temp_x1 - temp_x2))/10;
			//float temp = ((temp_x1 + 10 - temp_x2)*(temp_x1 + 10 - temp_x2) - (temp_x1 - temp_x2)*(temp_x1 - temp_x2)) / 10;
			//grad34_l2.at<float>((i*ROWS + j)) =(sqrt((temp_x1 + 10 - temp_x2)*(temp_x1 + 10 - temp_x2)) - sqrt((temp_x1 - temp_x2)*(temp_x1 - temp_x2)))/10;
			temp_l2Grad_34 = ((temp_x1 + 10 - temp_x2)*(temp_x1 + 10 - temp_x2) - (temp_x1 - temp_x2)*(temp_x1 - temp_x2)) / 10;
			grad34_l2.at<float>((i*ROWS + j)) = temp_l2Grad_34;

			if (temp_l2Grad_34 > temp_l2Grad_max)
				temp_l2Grad_max = temp_l2Grad_34;
			if (temp_l2Grad_34 < temp_l2Grad_min)
				temp_l2Grad_min = temp_l2Grad_34;
			count++;
			stop = time(NULL);
			printf("%d/%d....use time:%ld\n", count, size,(stop-start));
		}
	}
	
	//梯度可视化
	int step_emd = 255 / (temp_emdGrad_max - temp_emdGrad_min);
	int step_l2 = 255 / (temp_l2Grad_max - temp_l2Grad_min);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			grad34_emd_img.at<float>((i*ROWS + j)) = (grad34_emd.at<float>((i*ROWS + j)) - temp_emdGrad_min)*step_emd;
			grad34_l1_img.at<float>((i*ROWS + j)) = grad34_l1.at<float>((i*ROWS + j)) == 1 ? 255 : 0;

			float t1 = grad34_l2.at<float>((i*ROWS + j));
			float t2 = grad34_l2.at<float>((i*ROWS + j)) - temp_l2Grad_min;
			float t3 = temp_l2Grad_max - temp_l2Grad_min;
			float t4 = t2 / t3;
			float te = t4 * 255;

			grad34_l2_img.at<float>((i*ROWS + j)) = (grad34_l2.at<float>((i*ROWS + j)) - temp_l2Grad_min) / (temp_l2Grad_max - temp_l2Grad_min) * 255;
		}
	}

	imshow("grad34_emd_img", grad34_emd_img);
	imshow("grad34_l1_img", grad34_l1_img);
	imshow("grad34_l2_img", grad34_l2_img);

	imwrite("D:/grad34_emd_img.jpg", grad34_emd_img);
	imwrite("D:/grad34_l1_img.jpg", grad34_l1_img);
	imwrite("D:/grad34_l2_img.jpg", grad34_l2_img);
	waitKey(0);

	return 0;
}
