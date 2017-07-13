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



float emdDis(Mat image_i, Mat image_j,int flag)
{
	Mat sig_i = preEMD(image_i, image_i.channels());
	Mat sig_j = preEMD(image_j, image_i.channels());
	float emd_dis = 0;
	if (flag==1)
	emd_dis=cv::EMD(sig_i, sig_j, CV_DIST_L1, 0, 0);
	if (flag==2)
		emd_dis = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
	return emd_dis;
}

Mat preEMD(Mat image_i,int nC)
{
	//make signature
	int size = IMG_ROWS*IMG_COLS;
	Mat sig(size, 3, CV_32FC1);

	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			if (nC == 3)
				sig.at<float>(3 * (i*IMG_ROWS + j)) = (int)((int)image_i.at<Vec3b>(i, j)[0])*0.3 + ((int)image_i.at<Vec3b>(i, j)[1])*0.59 + ((int)image_i.at<Vec3b>(i, j)[2])*0.11;
			if (nC == 1){
				//qDebug() <<i<<"-"<<j<<":" <<image_i.at<float>(i, j);
			sig.at<float>(3 * (i*IMG_ROWS + j)) = image_i.at<float>(i, j);
		}
			sig.at<float>(3 * (i*IMG_ROWS + j) + 1) = i;
			sig.at<float>(3 * (i*IMG_ROWS + j) + 2) = j;
		}
	}
	return sig;
}

Mat preL1(Mat image_i)
{
	//make signature
	int size = IMG_ROWS*IMG_COLS;
	Mat sig(size, 1, CV_32FC1);

	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			sig.at<float>((i*IMG_ROWS + j)) = (int)((int)image_i.at<Vec3b>(i, j)[0])*0.3 + ((int)image_i.at<Vec3b>(i, j)[1])*0.59 + ((int)image_i.at<Vec3b>(i, j)[2])*0.11;
		}
	}
	return sig;
}


//void emdGrad(Mat image_i, Mat image_j,String filepath)
//{
//	String filename1 = filepath;
//	String filename2 = filepath;
//	String filename3 = filepath;
//
//	int size = IMG_ROWS*IMG_COLS;
//
//	Mat sig_i = preEMD(image_i, image_i.channels());
//	Mat sig_j = preEMD(image_j,image_i.channels());
//	float emd_ij = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
//
//	Mat gradij_emd = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//	Mat gradij_l1 = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//	Mat gradij_l2 = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//	Mat gradij_emd_img = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//	Mat gradij_l1_img = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//	Mat gradij_l2_img = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
//
//	float  temp_emdGrad_ij = 0;
//	//float temp_emdGrad_ij = 0;
//	float temp_emdGrad_max = INT_MIN;
//	float temp_emdGrad_min = INT_MAX;
//
//	float temp_l2Grad_ij = 0;
//	float temp_l2Grad_max = INT_MIN;
//	float temp_l2Grad_min = INT_MAX;
//
//	time_t start, stop;
//	//求解梯度
//	int count = 0;
//	for (int i = 0; i < IMG_ROWS; i++)
//	{
//		for (int j = 0; j < IMG_COLS; j++)
//		{
//			start = time(NULL);
//			sig_i.at<float>(3 * (i*IMG_ROWS + j)) += 10;
//			float delta_emd = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
//			temp_emdGrad_ij = (delta_emd - emd_ij) / 10;
//			sig_i.at<float>(3 * (i*IMG_ROWS + j)) -= 10;
//
//			gradij_emd.at<float>((i*IMG_ROWS + j)) = temp_emdGrad_ij;
//			if (temp_emdGrad_ij > temp_emdGrad_max)
//				temp_emdGrad_max = temp_emdGrad_ij;
//			if (temp_emdGrad_ij < temp_emdGrad_min)
//				temp_emdGrad_min = temp_emdGrad_ij;
//
//			float temp_x1 = sig_i.at<float>(3 * (i*IMG_ROWS + j))*0.3 + sig_i.at<float>(3 * (i*IMG_ROWS + j) + 1)*0.59 + sig_i.at<float>(3 * (i*IMG_ROWS + j) + 2)*0.11;
//			float temp_x2 = sig_j.at<float>(3 * (i*IMG_ROWS + j))*0.3 + sig_j.at<float>(3 * (i*IMG_ROWS + j) + 1)*0.59 + sig_j.at<float>(3 * (i*IMG_ROWS + j) + 2)*0.11;
//			gradij_l1.at<float>((i*IMG_ROWS + j)) = (abs(temp_x1 + 10 - temp_x2) - abs(temp_x1 - temp_x2)) / 10;
//			temp_l2Grad_ij = ((temp_x1 + 10 - temp_x2)*(temp_x1 + 10 - temp_x2) - (temp_x1 - temp_x2)*(temp_x1 - temp_x2)) / 10;
//			gradij_l2.at<float>((i*IMG_ROWS + j)) = temp_l2Grad_ij;
//
//			if (temp_l2Grad_ij > temp_l2Grad_max)
//				temp_l2Grad_max = temp_l2Grad_ij;
//			if (temp_l2Grad_ij < temp_l2Grad_min)
//				temp_l2Grad_min = temp_l2Grad_ij;
//			count++;
//			stop = time(NULL);
//			qDebug() << count <<"/"<<size<<"use time:"<< (stop - start);
//		}
//	}
//
//	//梯度可视化
//	int step_emd = 255 / (temp_emdGrad_max - temp_emdGrad_min);
//	int step_l2 = 255 / (temp_l2Grad_max - temp_l2Grad_min);
//
//	for (int i = 0; i < IMG_ROWS; i++)
//	{
//		for (int j = 0; j < IMG_COLS; j++)
//		{
//			gradij_emd_img.at<float>((i*IMG_ROWS + j)) = (gradij_emd.at<float>((i*IMG_ROWS + j)) - temp_emdGrad_min)*step_emd;
//			gradij_l1_img.at<float>((i*IMG_ROWS + j)) = gradij_l1.at<float>((i*IMG_ROWS + j)) == 1 ? 255 : 0;
//			gradij_l2_img.at<float>((i*IMG_ROWS + j)) = (gradij_l2.at<float>((i*IMG_ROWS + j)) - temp_l2Grad_min) / (temp_l2Grad_max - temp_l2Grad_min) * 255;
//		}
//	}
//
//
//	imwrite(filename1.append("gradij_emd_img.jpg"), gradij_emd_img);
//	imwrite(filename2.append("gradij_l1_img.jpg"), gradij_l1_img);
//	imwrite(filename3.append("gradij_l2_img.jpg"), gradij_l2_img);
//	waitKey(0);
//}

void emdGrad(Mat image_i, Mat image_j, String filepath)
{
	String filename1 = filepath;

	int size = IMG_ROWS*IMG_COLS;

	Mat sig_i = preEMD(image_i, image_i.channels());
	Mat sig_j = preEMD(image_j, image_i.channels());
	//float emd_ij = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
	float emd_ij = cv::EMD(sig_i, sig_j, CV_DIST_L1, 0, 0);

	Mat gradij_emd = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);
	Mat gradij_emd_img = Mat::zeros(IMG_ROWS, IMG_COLS, CV_32FC1);

	float  temp_emdGrad_ij = 0;
	//float temp_emdGrad_ij = 0;
	float temp_emdGrad_max = INT_MIN;
	float temp_emdGrad_min = INT_MAX;
	//float delta_emd = 0;

	time_t start, stop;
	//求解梯度
	int count = 0;
	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			start = time(NULL);
			int index = i*IMG_ROWS + j;
			//float delta_emd=addDelta(sig_i, sig_j, index, 1);
			vector<int> pos;
			int N = IMG_COLS*IMG_ROWS;
			for (int m = 0; m < N; m++)
				{
					if (m == index)
					{
						sig_i.at<float>(3 * m) += (N - 1)*1;
					}
					else
					{
						if (sig_i.at<float>(3 * m)>=1)
							sig_i.at<float>(3 *m) -= 1;
						else
						{
							sig_i.at<float>(3 * index) -= 1;
							pos.push_back(m);
						}
					}
					//qDebug() << sig_i.at<float>(3 * m);
				}


			temp_emdGrad_ij = cv::EMD(sig_i, sig_j, CV_DIST_L1, 0, 0);

			for (int m = 0; m < N; m++)
			{
				if (m == index)
				{
					sig_i.at<float>(3 * m) -= (N - 1) * 1;
				}
				else
				{
					sig_i.at<float>(3 * m) += 1;
				}
			}

			for (int m = 0; m < pos.size(); m++)
			{
				int temp_pos = pos.at(m);
				sig_i.at<float>(3 * index) += 1;
				sig_i.at<float>(3 * temp_pos) -= 1;
			}
			//sig_i.at<float>(3 * index) += 10;
			//float delta_emd = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
			//temp_emdGrad_ij = (delta_emd - emd_ij) / 10;
			//sig_i.at<float>(3 * (i*IMG_ROWS + j)) -= 10;

			gradij_emd.at<float>(index) = temp_emdGrad_ij;
			if (temp_emdGrad_ij > temp_emdGrad_max)
				temp_emdGrad_max = temp_emdGrad_ij;
			if (temp_emdGrad_ij < temp_emdGrad_min)
				temp_emdGrad_min = temp_emdGrad_ij;

			count++;
			stop = time(NULL);
			qDebug() << count << "/" << size << "use time:" << (stop - start);
		}
	}

	//梯度可视化
	//int step_emd = 255 / (temp_emdGrad_max - temp_emdGrad_min);

	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			gradij_emd_img.at<float>((i*IMG_ROWS + j)) = abs((gradij_emd.at<float>((i*IMG_ROWS + j)) - temp_emdGrad_min) / (temp_emdGrad_max - temp_emdGrad_min))*255;
		}
	}


	imwrite(filename1, gradij_emd_img);
	waitKey(0);
}

float addDelta(Mat sig_i, Mat sig_j, int index, int delta)
{
	int N = IMG_COLS*IMG_ROWS;
	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			if (i*IMG_ROWS + j == index)
			{
				sig_i.at<float>(3 * (i*IMG_ROWS + j)) += (N - 1)*delta;
			}
			else
			{
				sig_i.at<float>(3 * (i*IMG_ROWS + j)) -= delta;
			}
		}
	}

	float delta_emd = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);

	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			if (i*IMG_ROWS + j == index)
			{
				sig_i.at<float>(3 * (i*IMG_ROWS + j)) -= (N - 1)*delta;
			}
			else
			{
				sig_i.at<float>(3 * (i*IMG_ROWS + j)) += delta;
			}
		}
	}

	return delta_emd;
}

void emdGradRes(Mat image_i, Mat image_j, String filepath)
{
	time_t nowtime = time(NULL);
	String seconds = to_string(nowtime);
	fstream fs;
	String filename = filepath.append("/").append(seconds).append(".txt");
	fs.open(filename, fstream::in | fstream::out | fstream::app);

	int size = IMG_ROWS*IMG_COLS;

	Mat sig_i = preEMD(image_i, image_i.channels());
	Mat sig_j = preEMD(image_j, image_i.channels());
	
	double emd_ij = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);

	Mat gradij_emd = Mat::zeros(IMG_ROWS, IMG_COLS, CV_64FC1);
	
	double  temp_emdGrad_ij = 0;
	//float temp_emdGrad_ij = 0;
	
	time_t start, stop;

	//求解梯度
	int count = 0;
	for (int i = 0; i < IMG_ROWS; i++)
	{
		for (int j = 0; j < IMG_COLS; j++)
		{
			start = time(NULL);
			sig_i.at<float>(3 * (i*IMG_ROWS + j)) += 1;
			double delta_emd = cv::EMD(sig_i, sig_j, CV_DIST_L2, 0, 0);
			temp_emdGrad_ij = (delta_emd - emd_ij) / 1;
			sig_i.at<float>(3 * (i*IMG_ROWS + j)) -= 1;

			gradij_emd.at<double>(i,j) = temp_emdGrad_ij;
			fs << temp_emdGrad_ij;
			if (j != IMG_COLS - 1)
				fs << ",";
			count++;
			stop = time(NULL);
			qDebug() << count << "/" << size << "use time:" << (stop - start);
		}
		fs << ";\n";
	}

	fs.close();

}


float l1Dis(Mat image_i, Mat image_j)
{
	int size = IMG_ROWS*IMG_COLS;
	float sum_diff = 0;
	//for (int i = 0; i < IMG_ROWS; i++)
	//{
	//	for (int j = 0; j < IMG_COLS; j++)
	//	{
	//		sum_diff += (int)((int)image_i.at<Vec3b>(i, j)[0])*0.3 + ((int)image_i.at<Vec3b>(i, j)[1])*0.59 + ((int)image_i.at<Vec3b>(i, j)[2])*0.11
	//				 - (int)((int)image_j.at<Vec3b>(i, j)[0])*0.3 + ((int)image_j.at<Vec3b>(i, j)[1])*0.59 + ((int)image_j.at<Vec3b>(i, j)[2])*0.11;

	//	}
	//}
	Mat sig_i = preL1(image_i);
	Mat sig_j = preL1(image_j);
	float res =norm(sig_i, sig_j, NORM_L1);

	//return sum_diff / size;
	return res;
}

float l2Dis(Mat image_i, Mat image_j)
{
	int size = IMG_ROWS*IMG_COLS;
	float sum_diff = 0;


	return sum_diff / size;
}



//emd 的近似实现
float emdDis_ap(Mat image_a, Mat image_b)
{
	if (image_a.rows != image_a.cols){
		qDebug() << "the rows and cols are not equal in image";
		return -1;
	}
	if (image_a.rows != image_b.rows){
		qDebug() << "the dimentions in two image are not equal";
		return -1;
	}
	float emd_dis = 0;
	int N = image_a.rows;
	//图像像素总量求和
	int total_a = 0;
	int total_b = 0;
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			if (image_a.channels() == 3)
			{
				total_a += (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
				total_b += (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			}
			else//if (image_a.channels() == 1)
			{
				total_a += image_a.at<float>(i, j);
				total_b += image_b.at<float>(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int a_mn = 0;
		int b_mn = 0;
		float ph_i = ph(image_a, image_b, i, total_a, total_b);
		emd_dis += abs(ph_i);
	}
	return emd_dis;
}


float ph(Mat image_a, Mat image_b, int index, int total_a, int total_b)
{
	int N = image_a.rows;
	int a_mn = 0;
	int b_mn = 0;

		for (int m = 0; m < index; m++)
		{
			for (int n = 0; n < index; n++)
			{
				if (image_a.channels() == 3){
				a_mn += (int)((int)image_a.at<Vec3b>(m, n)[0])*0.3 + ((int)image_a.at<Vec3b>(m, n)[1])*0.59 + ((int)image_a.at<Vec3b>(m, n)[2])*0.11;
				b_mn += (int)((int)image_b.at<Vec3b>(m, n)[0])*0.3 + ((int)image_b.at<Vec3b>(m, n)[1])*0.59 + ((int)image_b.at<Vec3b>(m, n)[2])*0.11;
				}
				else//if (image_a.channels() == 1)
				{
					a_mn += image_a.at<float>(m, n);
					b_mn += image_b.at<float>(m, n);
				}
			}
		}
		float pi_res = (float)a_mn/total_a - (float)b_mn/total_b;
		return pi_res;
}

void emdGrad_ap(Mat image_a, Mat image_b, float delta,String filename)
{
	Mat grad_emd = Mat::zeros(image_a.rows, image_b.cols, CV_32FC1);
	float emd_dis = emdDis_ap(image_a, image_b);
	float emdDelta_dis = 0;
	float min_grad = INT_MAX;
	float max_grad = INT_MIN;
	int sign = 0;
	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			emdDelta_dis = emdGradPixal_ap(image_a, image_b, i, j, delta);
			grad_emd.at<float>(i, j) = (emd_dis - emdDelta_dis) / delta;
			float temp_a = (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
			float temp_b = (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			sign += (temp_a - temp_b);
			if (grad_emd.at<float>(i, j)>max_grad)
				max_grad = grad_emd.at<float>(i, j);
			if (grad_emd.at<float>(i, j)<min_grad)
				min_grad = grad_emd.at<float>(i, j);
		}
	}


	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			if (sign < 0)
			{
				float temp= -(grad_emd.at<float>(i, j) - min_grad);
				grad_emd.at<float>(i, j) = temp;
			}
			else
			{
				float temp  = -(grad_emd.at<float>(i, j) - max_grad);
				grad_emd.at<float>(i, j) = temp;
			}
		}
	}

	if (sign < 0)
	{
		max_grad = -(max_grad - min_grad);
		min_grad = 0;
	}
		
	else
	{
		min_grad = -(min_grad - max_grad);
		max_grad = 0;
	}

	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			grad_emd.at<float>(i, j) =abs( (grad_emd.at<float>(i, j) - min_grad) / (max_grad - min_grad) )* 255;
		}
	}
	imwrite(filename, grad_emd);
}

float emdGradPixal_ap(Mat image_a, Mat image_b,int rowInd,int colInd, float delta)
{
	image_a.at<Vec3b>(rowInd, colInd)[0] += delta;
	image_a.at<Vec3b>(rowInd, colInd)[1] += delta;
	image_a.at<Vec3b>(rowInd, colInd)[2] += delta;
	float emdDelta_ap=emdDis_ap(image_a, image_b);
	return emdDelta_ap;
}

float emdGradPixal_ap2(Mat image_a, Mat image_b, int rowInd, int colInd, float delta)
{
	int N = image_a.rows*image_a.cols;
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			if (i == rowInd&&j == colInd)
			{
				image_a.at<Vec3b>(rowInd, colInd)[0] += delta*N;
				image_a.at<Vec3b>(rowInd, colInd)[1] += delta*N;
				image_a.at<Vec3b>(rowInd, colInd)[2] += delta*N;
			}
			else
			{
				image_a.at<Vec3b>(rowInd, colInd)[0] -= delta;
				image_a.at<Vec3b>(rowInd, colInd)[1] -= delta;
				image_a.at<Vec3b>(rowInd, colInd)[2] -= delta;
			}
		}
	}
	image_a.at<Vec3b>(rowInd, colInd)[0] += delta;
	image_a.at<Vec3b>(rowInd, colInd)[1] += delta;
	image_a.at<Vec3b>(rowInd, colInd)[2] += delta;
	float emdDelta_ap = emdDis_ap(image_a, image_b);
	return emdDelta_ap;
}


//emd近似实现2
float emdDis_ap2(Mat image_a, Mat image_b)
{
	if (image_a.rows != image_a.cols){
		qDebug() << "the rows and cols are not equal in image";
		return -1;
	}
	if (image_a.rows != image_b.rows){
		qDebug() << "the dimentions in two image are not equal";
		return -1;
	}
	float emd_dis = 0;
	int N = ((int)(image_a.rows - 1) / 2)*2;
	//图像像素总量求和
	int total_a = 0;
	int total_b = 0;
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			if (image_a.channels() == 3)
			{
				total_a += (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
				total_b += (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			}
			else//if (image_a.channels() == 1)
			{
				total_a += image_a.at<float>(i, j);
				total_b += image_b.at<float>(i, j);
			}
		}
	}
	//计算
	for (int i = 0; i <=N; i++)
	{
		float ph_i = ph2(image_a, image_b, i,total_a,total_b);
		emd_dis += abs(ph_i);
	}
	return emd_dis;
}

float ph2(Mat image_a, Mat image_b, int index,int total_a, int total_b)
{
	int N = ((int)(image_a.rows - 1) / 2) * 2;
	int transDis = (int)((float)image_a.rows/ 2+0.5)-1;
	int sum_a = 0;
	int sum_b = 0;

	if (index <= N / 2)
	{
		for (int x = -index; x <= index; x++)
		{
			for (int y = -(index - abs(x)); y <= (index - abs(x)); y++)
			{
				vector<int> temp = center2left(x, y, transDis);
				int i = temp[0];
				int j = temp[1];

				if (image_a.channels() == 3){
					sum_a += (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
					sum_b += (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
				}
				else
				{
					sum_a += image_a.at<float>(i, j);
					sum_b += image_b.at<float>(i, j);
				}
			}
		}
	}
	else
	{
		sum_a = total_a;
		sum_b = total_b;
		index =index - N / 2;
		for (int x = index; x <= N / 2; x++)
		{
			for (int y = N / 2; y >= N / 2-(x-index); y--)
			{
				int sign_x[4] = {1,1,-1,-1};
				int sign_y[4] = {1,-1,-1,1};
				for (int t = 0; t < 4; t++){

					vector<int> temp = center2left(x*sign_x[t], y*sign_y[t], transDis);
					int i = temp[0];
					int j = temp[1];

					if (image_a.channels() == 3){
					sum_a -= (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
					sum_b -= (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
				}
				else
				{
					sum_a -= image_a.at<float>(i, j);
					sum_b -= image_b.at<float>(i, j);
				}
				}
			}
		}


	}
	
	float pi_res = (float)sum_a / total_a - (float)sum_b / total_b;
	return pi_res;
}

vector<int> left2center(int i, int j,int transDis)
{
	int x = i - transDis;
	int y = -(j - transDis);
	vector<int> res;
	res.push_back(x);
	res.push_back(y);
	return res;
}

vector<int> center2left(int x, int y, int transDis)
{
	int i = x + transDis;
	int j = transDis - y;
	vector<int> res;
	res.push_back(i);
	res.push_back(j);
	return res;
}


//emd近似实现3
float emdDis_ap3(Mat image_a, Mat image_b)
{
	if (image_a.rows != image_a.cols){
		qDebug() << "the rows and cols are not equal in image";
		return -1;
	}
	if (image_a.rows != image_b.rows){
		qDebug() << "the dimentions in two image are not equal";
		return -1;
	}
	float emd_dis = 0;
	int N = image_a.rows;
	//图像像素总量求和
	int total_a = 0;
	int total_b = 0;
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			if (image_a.channels() == 3)
			{
				total_a += (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
				total_b += (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			}
			else//if (image_a.channels() == 1)
			{
				total_a += image_a.at<float>(i, j);
				total_b += image_b.at<float>(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int a_mn = 0;
		int b_mn = 0;
		float ph_i = 0;
		float temp_emd = 0;
		for (int flag = 1; flag <= 4; flag++)
		{
			ph_i = ph3(image_a, image_b, i, total_a, total_b, flag);
			temp_emd += abs(ph_i);
		}
		emd_dis += temp_emd/4;
		temp_emd = 0;
	}
	return emd_dis;
}


float ph3(Mat image_a, Mat image_b, int index, int total_a, int total_b, int flag)
{
	int N = image_a.rows;
	int a_mn = 0;
	int b_mn = 0;

	for (int m = 0; m <= index; m++)
	{
		for (int n = 0; n <= index; n++)
		{
			if (image_a.channels() == 3){
				switch (flag)
				{
				case 1:
					a_mn += (int)((int)image_a.at<Vec3b>(m, n)[0])*0.3 + ((int)image_a.at<Vec3b>(m, n)[1])*0.59 + ((int)image_a.at<Vec3b>(m, n)[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(m, n)[0])*0.3 + ((int)image_b.at<Vec3b>(m, n)[1])*0.59 + ((int)image_b.at<Vec3b>(m, n)[2])*0.11;
					break;
				case 2:
					a_mn += (int)((int)image_a.at<Vec3b>(m, N - (n + 1))[0])*0.3 + ((int)image_a.at<Vec3b>(m, N - (n + 1))[1])*0.59 + ((int)image_a.at<Vec3b>(m, N - (n + 1))[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(m, N - (n + 1))[0])*0.3 + ((int)image_b.at<Vec3b>(m, N - (n + 1))[1])*0.59 + ((int)image_b.at<Vec3b>(m, N - (n + 1))[2])*0.11;
					break;
				case 3:
					a_mn += (int)((int)image_a.at<Vec3b>(N - (m + 1), n)[0])*0.3 + ((int)image_a.at<Vec3b>(N - (m + 1), n)[1])*0.59 + ((int)image_a.at<Vec3b>(N - (m + 1), n)[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(N - (m + 1), n)[0])*0.3 + ((int)image_b.at<Vec3b>(N - (m + 1), n)[1])*0.59 + ((int)image_b.at<Vec3b>(N - (m + 1), n)[2])*0.11;
					break;
				case 4:
					a_mn += (int)((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[0])*0.3 + ((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[1])*0.59 + ((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[0])*0.3 + ((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[1])*0.59 + ((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[2])*0.11;
					break;
				}
			}
			else//if (image_a.channels() == 1)
			{
				switch (flag)
				{
				case 1:
					a_mn += image_a.at<float>(m, n);
					b_mn += image_b.at<float>(m, n);
					break;
				case 2:
					a_mn += image_a.at<float>(m, N - (n + 1));
					b_mn += image_b.at<float>(m, N - (n + 1));
					break;
				case 3:
					a_mn += image_a.at<float>(N - (m + 1), n);
					b_mn += image_b.at<float>(N - (m + 1), n);
					break;
				case 4:
					a_mn += image_a.at<float>(N - (m + 1), N - (n + 1));
					b_mn += image_b.at<float>(N - (m + 1), N - (n + 1));
					break;
				}
			}
		} 
	}
	
	float pi_res =(float)a_mn / total_a - (float)b_mn / total_b;
	return pi_res;
}


//emd近似实现4
float emdDis_ap4(Mat image_a, Mat image_b)
{
	if (image_a.rows != image_a.cols){
		qDebug() << "the rows and cols are not equal in image";
		return -1;
	}
	if (image_a.rows != image_b.rows){
		qDebug() << "the dimentions in two image are not equal";
		return -1;
	}
	float emd_dis = 0;
	int N = image_a.rows;
	//图像像素总量求和
	int total_a = 0;
	int total_b = 0;
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			if (image_a.channels() == 3)
			{
				total_a += (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
				total_b += (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			}
			else//if (image_a.channels() == 1)
			{
				total_a += image_a.at<float>(i, j);
				total_b += image_b.at<float>(i, j);
			}
		}
	}
	for (int i = 0; i < N/2; i++)
	{
		int a_mn = 0;
		int b_mn = 0;
		float ph_i = 0;
		float temp_emd = 0;
		for (int flag = 1; flag <= 4; flag++)
		{
			ph_i = ph3(image_a, image_b, i, total_a, total_b, flag);
			temp_emd += abs(ph_i);
		}
		emd_dis += temp_emd / 4;
		temp_emd = 0;
	}
	return emd_dis;
}


float ph4(Mat image_a, Mat image_b, int index, int total_a, int total_b, int flag)
{
	int N = image_a.rows;
	int a_mn = 0;
	int b_mn = 0;

	for (int m = 0; m <= index; m++)
	{
		for (int n = 0; n <= index; n++)
		{
			if (image_a.channels() == 3){
				switch (flag)
				{
				case 1:
					a_mn += (int)((int)image_a.at<Vec3b>(m, n)[0])*0.3 + ((int)image_a.at<Vec3b>(m, n)[1])*0.59 + ((int)image_a.at<Vec3b>(m, n)[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(m, n)[0])*0.3 + ((int)image_b.at<Vec3b>(m, n)[1])*0.59 + ((int)image_b.at<Vec3b>(m, n)[2])*0.11;
					break;
				case 2:
					a_mn += (int)((int)image_a.at<Vec3b>(m, N - (n + 1))[0])*0.3 + ((int)image_a.at<Vec3b>(m, N - (n + 1))[1])*0.59 + ((int)image_a.at<Vec3b>(m, N - (n + 1))[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(m, N - (n + 1))[0])*0.3 + ((int)image_b.at<Vec3b>(m, N - (n + 1))[1])*0.59 + ((int)image_b.at<Vec3b>(m, N - (n + 1))[2])*0.11;
					break;
				case 3:
					a_mn += (int)((int)image_a.at<Vec3b>(N - (m + 1), n)[0])*0.3 + ((int)image_a.at<Vec3b>(N - (m + 1), n)[1])*0.59 + ((int)image_a.at<Vec3b>(N - (m + 1), n)[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(N - (m + 1), n)[0])*0.3 + ((int)image_b.at<Vec3b>(N - (m + 1), n)[1])*0.59 + ((int)image_b.at<Vec3b>(N - (m + 1), n)[2])*0.11;
					break;
				case 4:
					a_mn += (int)((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[0])*0.3 + ((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[1])*0.59 + ((int)image_a.at<Vec3b>(N - (m + 1), N - (n + 1))[2])*0.11;
					b_mn += (int)((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[0])*0.3 + ((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[1])*0.59 + ((int)image_b.at<Vec3b>(N - (m + 1), N - (n + 1))[2])*0.11;
					break;
				}
			}
			else//if (image_a.channels() == 1)
			{
				switch (flag)
				{
				case 1:
					a_mn += image_a.at<float>(m, n);
					b_mn += image_b.at<float>(m, n);
					break;
				case 2:
					a_mn += image_a.at<float>(m, N - (n + 1));
					b_mn += image_b.at<float>(m, N - (n + 1));
					break;
				case 3:
					a_mn += image_a.at<float>(N - (m + 1), n);
					b_mn += image_b.at<float>(N - (m + 1), n);
					break;
				case 4:
					a_mn += image_a.at<float>(N - (m + 1), N - (n + 1));
					b_mn += image_b.at<float>(N - (m + 1), N - (n + 1));
					break;
				}
			}
		}
	}

	float pi_res = (float)a_mn / total_a - (float)b_mn / total_b;
	return pi_res;
}


void emdGrad_ap4(Mat image_a, Mat image_b, float delta, String filename)
{
	Mat SData = Mat::zeros(image_a.rows, image_b.cols, CV_32FC1);
	Mat DData = Mat::zeros(image_a.rows, image_b.cols, CV_32FC1);
	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			if (image_a.channels() == 3)
			{
				SData.at<float>(i, j) = (int)((int)image_a.at<Vec3b>(i, j)[0])*0.3 + ((int)image_a.at<Vec3b>(i, j)[1])*0.59 + ((int)image_a.at<Vec3b>(i, j)[2])*0.11;
				DData.at<float>(i, j) = (int)((int)image_b.at<Vec3b>(i, j)[0])*0.3 + ((int)image_b.at<Vec3b>(i, j)[1])*0.59 + ((int)image_b.at<Vec3b>(i, j)[2])*0.11;
			}
			else
			{
				SData.at<float>(i, j) = image_a.at<float>(i, j);
				DData.at<float>(i, j) = image_b.at<float>(i, j);
			}
			float temp_s = SData.at<float>(i, j);
			float temp_d = DData.at<float>(i, j);
		}
	}

	Mat grad_emd = Mat::zeros(image_a.rows, image_b.cols, CV_32FC1);
	float emd_dis = emdDis_ap4(image_a, image_b);
	float emdDelta_dis = 0;
	float min_grad = INT_MAX;
	float max_grad = INT_MIN;
	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			emdDelta_dis = emdGradPixal_ap4(SData, DData, i, j, delta);
			grad_emd.at<float>(i, j) = (emd_dis - emdDelta_dis) / delta;
			float temp_g = grad_emd.at<float>(i, j);
			if (grad_emd.at<float>(i, j)>max_grad)
				max_grad = grad_emd.at<float>(i, j);
			if (grad_emd.at<float>(i, j)<min_grad)
				min_grad = grad_emd.at<float>(i, j);
		}
	}

	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			grad_emd.at<float>(i, j) = abs((grad_emd.at<float>(i, j) - min_grad) / (max_grad - min_grad)) * 255;
			float temp = grad_emd.at<float>(i, j);
		}
	}
	//imwrite("s", SData);
	//imwrite("D", DData);
	imwrite(filename, grad_emd);
}

float emdGradPixal_ap4(Mat SData, Mat DData, int rowInd, int colInd, float delta)
{
	int N = IMG_ROWS*IMG_COLS;
	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			if (i==rowInd&&j==colInd)
				SData.at<float>(i, j) +=(N-1)*delta;
			else
				SData.at<float>(i, j) -= delta;
		}
	}
	float emdDelta_ap = emdDis_ap4(SData, DData);

	for (int i = 0; i < IMG_ROWS/*image_a.rows*/; i++)
	{
		for (int j = 0; j < IMG_COLS/*image_a.cols*/; j++)
		{
			if (i == rowInd&&j == colInd)
				SData.at<float>(i, j) -= (N - 1)*delta;
			else
				SData.at<float>(i, j) += delta;
		}
	}
	return emdDelta_ap;
}
