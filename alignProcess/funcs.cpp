#include "funcs.h"

QString s2q(const string &s)
{
	return QString(QString::fromLocal8Bit(s.c_str()));
}
string q2s(const QString &s)
{
	return string((const char *)s.toLocal8Bit());
}

bool sameName(const QString filename1, const QString filename2, int suffix)
{
	String filename1_sub = q2s(filename1).substr(0, filename1.length() - suffix);
	qDebug()<< s2q(filename1_sub);
	String filename2_sub = q2s(filename2).substr(0, filename1.length() - suffix);
	qDebug() << s2q(filename2_sub);

	if (filename1_sub.compare(filename2_sub)==0)
		return true;
	else
		return false;
}


Mat cut(Mat image, String flag)
{

	if (image.cols < image.rows)
	{
		int temp = (image.rows - image.cols) / 2;
		Mat result = image(Rect(0, temp, image.cols, image.cols));
		return result;
	}

	if (image.cols > image.rows)
	{
		int temp = (image.cols - image.rows);
		/*if (flag.compare("R") == 0)
		{
			qDebug() << QRect(temp, 0, image.cols, image.rows);
			Mat result = image(Rect(temp, 0, image.rows, image.rows));
			return result;
		}

		if (flag.compare("L") == 0)
		{
			Mat result = image(Rect(0, 0, image.rows, image.rows));
			return result;
		}*/

			Mat result = image(Rect(0, 0, image.rows, image.rows));
			return result;
	}

	return image;
}


//计算两点距离的平方,即欧拉距离和
int calDis(vector<int> p1, vector<int> p2)
{
	int size = min(p1.size(), p2.size());
	int sum_dis = 0;
	for (int i = 0; i < size;i++)
	{	
		sum_dis = sum_dis + pow((p1.at(i) - p2.at(i)), 2);
	}
	return sum_dis;
}

int calDis(vector<vector<int>> p1, vector<vector<int>> p2)
{
	int size = min(p1.size(), p2.size());
	int sum_dis = 0;
	for (int i = 0; i < size; i++)
	{
		sum_dis = calDis(p1.at(i),p2.at(i));
	}
	return sum_dis;
}

/*点集中心化*/
vector<vector<int>> centerTrans(vector<vector<int>> p, vector<int> center)
{
	int p_size = p.size();
	vector<int> temp(3, 0);
	vector<vector<int>> res(p.size(), temp);
	for (int i = 0; i < p_size; i++)
	{
		vector<int> temp_res(3,0);
		vector<int> temp_p = p.at(i);
		for (int i = 0; i < center.size(); i++)
		{
			temp_res.at(i) = temp_p.at(i) - center.at(i);
		}
		res.at(i) = temp_res;
	}
	return res;
}

vector<vector<int>> counterCenterTrans(vector<vector<int>> p, vector<int> center)
{
	int p_size = p.size();
	vector<int> temp(3, 0);
	vector<vector<int>> res(p.size(), temp);
	for (int i = 0; i < p_size; i++)
	{
		vector<int> temp_res;
		vector<int> temp_p = p.at(i);
		for (int i = 0; i < center.size(); i++)
		{
			temp_res.at(i) = temp_p.at(i) + center.at(i);
		}
		res.at(i) = temp_res;
	}
	return res;
}

int centerTrans(int p_x, int center_x)
{
	return p_x - center_x;
}
int counterCenterTrans(int p_x, int center_x)
{
	return p_x+ center_x;
}


/*获得平移向量*/
vector<int> getTrans(vector<int> aimPointCenter, vector<int> sourcePointCenter)
{
	vector<int> trans(3,0);
	int size = min(aimPointCenter.size(), sourcePointCenter.size());
	for (int i = 0; i < size; i++)
	{
		trans.at(i) = aimPointCenter.at(i) - sourcePointCenter.at(i);
	}
	return trans;
}
/*获得x平移*/
int getTransX(vector<int> aimPointCenter, vector<int> sourcePointCenter)
{
	int transX;
	int size = min(aimPointCenter.size(), sourcePointCenter.size());
	transX= aimPointCenter.at(0) - sourcePointCenter.at(0);
	return transX;
}

/*获得点集中心*/
vector<int> getCenter(vector<vector<int>> points)
{
	vector<int> res(3,0);
	vector<int> temp;
	for (int i = 0; i < points.size(); i++)
	{
		temp = points.at(i);
		res.at(0) = res.at(0)+temp.at(0);
		res.at(1) = res.at(1) + temp.at(1);
		res.at(2) = res.at(2) + temp.at(2);
	}
	res.at(0) = res.at(0)/points.size();
	res.at(1) = res.at(1) / points.size();
	res.at(2) = res.at(2) / points.size();
	return res;
}

/*点对搜索匹配，得到匹配点集*/
Mat getAimPoint(Mat Lpoint, Mat Rpoint)
{
	return Rpoint;
}
vector<vector<int>> getAimPoint(vector<vector<int>> &Lpoint, vector<vector<int>> &Rpoint)
{
	vector<int> temp(3, 0);
	vector<vector<int>> res(Lpoint.size(),temp);
	int size_L = Lpoint.size();
	int size_R = Rpoint.size();
	int width = sqrt(size_L);
	float minDis = INT_MAX;
	for (int i = 0; i < size_L; i++)
	{
		//qDebug() << "i:" << i;
		minDis = calDis(Lpoint.at(i), Rpoint.at(0));
		res.at(i) = Rpoint.at(0);
		int nrow = i / width;
		int ncol = i - nrow*width;
		//for (int r = max(0,nrow-2); r < min(nrow+2,size_R/width-1); r++){
			for (int j = max(0, ncol -50); j < min(width, ncol + 50); j++)
			{
				//int index = min(r*width + j,size_R-1);
				int index = nrow*width + j;
				//int index = r*width + j;
				//qDebug() << "index:" << index;
				if (index < 0) index = 0;
				if (index > size_R) index = size_R-1;

				float tempDis = calDis(Lpoint.at(i), Rpoint.at(index));
				if (tempDis < minDis)
				{
					minDis = tempDis;
					res.at(i) = Rpoint.at(index);
				}
			}
		//}

	}

	return res;
}

/*迭代求解*/
int ICPiterator(vector<vector<int>> &Lpoint, vector<vector<int>> &Rpoint)
{
	float dis_last = INT_MAX;
	float dis_now = INT_MAX;
	float e_dis = dis_last;
	int transX = 0;
	int count = 0;
	while (e_dis >= dis_now/5 && count<5){
		Rpoint = getAimPoint(Lpoint, Rpoint);
		vector<int> LCenter = getCenter(Lpoint);
		vector<int> RCenter = getCenter(Rpoint);

		transX = transX+getTransX(LCenter, RCenter);
		qDebug() << transX;
		//vector<vector<int>> midL = centerTrans(Lpoint, LCenter);
		//vector<vector<int>> midR = centerTrans(Rpoint, RCenter);

		for (int i = 0; i < Lpoint.size(); i++)
		{
			Lpoint.at(i).at(0) = Lpoint.at(i).at(0) + transX;
		}
		dis_now = calDis(Lpoint, Rpoint);
		e_dis = abs(dis_now - dis_last);
		dis_last = dis_now;
		count++;
		qDebug() << count;
	}
	return transX;
	//return dis;
}