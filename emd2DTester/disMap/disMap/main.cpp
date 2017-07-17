#define IMG_ROW 64
#define IMG_COL 64
#define DIS_MODE 2
#include "funcs.h"

int main(){

	float dis = 0;
	float dis_max = INT_MIN;
	float dis_min = INT_MAX;
	Mat res(IMG_ROW*15, IMG_COL*15, CV_8UC1);
	Mat resTemp(IMG_ROW, IMG_COL, CV_32FC1);

	for (int i = 0; i < IMG_ROW; i++){
		for (int j = 0; j < IMG_COL; j++){
			if (DIS_MODE==2){
				dis = sqrt((float)i*i + j*j);
				resTemp.at<float>(i, j) = dis;
				if (dis > dis_max)
					dis_max = dis;
				if (dis < dis_min)
					dis_min = dis;
			}
		}
	}


	int color = 0;
	int N =(1 + resTemp.rows)*resTemp.cols / 2;
	vector<int> colMins;
	vector<int> findMins;
	colMins = findMinInCols(resTemp,-1,colMins);
	for (int i = 0; i < N; i++){
		findMins = findMinInAll(resTemp, colMins);

		for (int j = 0; j < findMins.size(); j++)
		{
			int index = findMins.at(j);
			int r = index / resTemp.rows;
			int c = index%resTemp.rows;

			color =(color+3)%255;

			for (int m = r * 15; m < (r + 1) * 15; m++){
				for (int n = c * 15; n < (c + 1) * 15; n++){
					res.at<uchar>(m, n) = color;
					if (m == (r + 1) * 15 - 1 || n == (c + 1) * 15 - 1)
						res.at<uchar>(m, n) = (int)0;
				}
			}
			//res.at<uchar>(r, c) = color;
			resTemp.at<float>(r, c) = -1;
			colMins=findMinInCols(resTemp, c, colMins);
		}
	}

	imshow("dismap", res);
	waitKey();
	return 0;

}

