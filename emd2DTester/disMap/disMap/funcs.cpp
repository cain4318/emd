#include "funcs.h"

vector<int> findMinInAll(Mat Data, vector<int> colMins){

	float min_dis = INT_MAX;
	float temp_dis = 0;
	int pos=0;
	vector<int> res;
	for (int i = 0; i < colMins.size(); i++){
		pos = colMins.at(i);
		if (pos == -1)
			continue;
		temp_dis = Data.at<float>(pos / Data.rows, pos % Data.rows);
		if (temp_dis < min_dis && temp_dis!=-1)
		{
			min_dis = temp_dis;
			res.clear();
			res.push_back(pos);
		}
		else
		{
			if (temp_dis == min_dis)
				res.push_back(pos);
		}
	}
	return res;
}

vector<int> findMinInCols(Mat Data, int colIndex, vector<int> colMins)
{
	float minDis = INT_MAX;
	int pos=0;
	if (colIndex == -1)//更新所有列的最小值
	{
		colMins.clear();
		for (int i = 0; i < Data.cols; i++){
			for (int j = 0; j < Data.rows; j++){
				if (Data.at<float>(i, j) < minDis && Data.at<float>(i, j)!=-1){
					minDis = Data.at<float>(i, j);
					pos= j*Data.rows+i;
				}
			}
			colMins.push_back(pos);
			minDis = INT_MAX;
		}
		return colMins;
	}
	else{ //更新某一列的最小值
		bool change = false;
		for (int i = 0; i < Data.rows; i++){
			if (Data.at<float>(i, colIndex) < minDis && Data.at<float>(i, colIndex) != -1){
				minDis = Data.at<float>(i, colIndex);
				pos = i*Data.rows+ colIndex;
				change = true;
			}
		}
		if (change)
			colMins.at(colIndex)=pos;
		else
			colMins.at(colIndex) = -1;
	}
	return colMins;
}