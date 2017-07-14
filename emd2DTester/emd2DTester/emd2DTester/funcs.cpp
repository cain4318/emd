#include "funcs.h"

QString s2q(const string &s)
{
	return QString(QString::fromLocal8Bit(s.c_str()));
}
string q2s(const QString &s)
{
	return string((const char *)s.toLocal8Bit());
}

Mat QImageToMat(QImage image)
{
	Mat mat;
	switch (image.format())
	{
	case QImage::Format_ARGB32:
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32_Premultiplied:
	{mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
	Mat retMat = Mat::zeros(mat.rows, mat.cols, CV_8UC3);
	for (int i = 0; i < mat.rows; i++)
		for (int j = 0; j < mat.cols; j++)
		{
			retMat.at<Vec3b>(i, j)[0] = mat.at<Vec4b>(i, j)[0];
			retMat.at<Vec3b>(i, j)[1] = mat.at<Vec4b>(i, j)[1];
			retMat.at<Vec3b>(i, j)[2] = mat.at<Vec4b>(i, j)[2];
		}
	return retMat;
	break;
	}
	case QImage::Format_RGB888:
		mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		//cvtColor(mat, mat, CV_BGR2RGB);
		break;
	case QImage::Format_Indexed8:
		mat = Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	return mat;
}

bool sameName(const QString filename1, const QString filename2, int suffix)
{
	String filename1_sub = q2s(filename1).substr(0, filename1.length() - suffix);
	qDebug() << s2q(filename1_sub);
	String filename2_sub = q2s(filename2).substr(0, filename1.length() - suffix);
	qDebug() << s2q(filename2_sub);

	if (filename1_sub.compare(filename2_sub) == 0)
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


void drawHis(vector<float> data, String title){

	int bins = data.size();
	int hist_size[] = { bins };

	float max = data[0];
	float min = data[0];
	for (int i = 0; i < bins; i++)
	{
		if (data[i]>max)
			max = data[i];
		if (data[i]<min)
			min = data[i];
	}

	int scale = 30;
	int hist_height = 200;
	Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
	for (int i = 0; i<bins; i++)
	{
		float bin_val = data[i];
		int intensity = cvRound(bin_val*hist_height / max);  //Ҫ���Ƶĸ߶�
		rectangle(hist_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			255);
	}
	imshow(title, hist_img);
	//cvWaitKey();
}



void drawGradHis(vector<float> data, String title){

	int bins = data.size();
	int hist_size[] = { bins };

	float max = data[0];
	float min = data[0];
	for (int i = 0; i < bins; i++)
	{
		if (data[i]>max)
			max = data[i];
		if (data[i]<min)
			min = data[i];
	}
	if (abs(max) > abs(min))
		max = max;
	else
		max = abs(min);


	int scale = 30;
	int hist_height = 100;
	Mat hist_img = Mat::zeros(hist_height * 2, bins*scale, CV_8UC1);
	for (int i = 0; i<bins; i++)
	{
		float bin_val = abs(data[i]);
		int intensity = cvRound(bin_val*hist_height / max);  //Ҫ���Ƶĸ߶�
		if (data[i]>0)
			rectangle(hist_img, Point(i*scale, hist_height - 1), Point((i + 1)*scale - 1, hist_height - intensity), 255);
		else
			rectangle(hist_img, Point(i*scale, hist_height + intensity - 1), Point((i + 1)*scale - 1, hist_height - 1), 255);
	}
	imshow(title, hist_img);
	//cvWaitKey();
}


void saveTestData(vector<float> data1, vector<float> data2, vector<float> data3, float emd, Mat plan, String filename)
{
	fstream fs;
	fs.open(filename, fstream::in | fstream::out | fstream::app);
	int sun = 0;
	int dim = data1.size();
	fs << "Supplys(in rows):\n";
	for (int i = 0; i < dim; i++)
	{
		fs << "s" << i << ",";
	}
	fs << "\n";
	for (int i = 0; i < dim; i++)
	{
		fs << data1[i] << ",";
	}
	fs << "\n";
	fs << "Demands(in cols):\n";
	for (int i = 0; i <dim; i++)
	{
		fs << "d" << i << ",";
	}
	fs << "\n";
	for (int i = 0; i < dim; i++)
	{
		fs << data2[i] << ",";
	}
	fs << "\n";


	fs << "unit cost matrex:\n";
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j <dim; j++)
		{
			float temp = abs(i - j);
			fs << (int)temp << "  :  ";
		}
		fs << "\n";
	}

	fs << "emd:" << emd << "\n";

	fs << "Grad:\n";
	for (int i = 0; i <dim; i++)
	{
		fs << i << "	";
	}
	fs << "\n";
	for (int i = 0; i < dim; i++)
	{
		fs << data3[i] << "	";
	}
	fs << "\n";

	fs << "plan:\n";
	for (int i = 0; i < plan.rows; i++){//for opencv emd
		for (int j = 0; j < plan.cols; j++)
		{
			if (plan.at<float>(i*plan.rows + j)<0)
				plan.at<float>(i*plan.rows + j) = 0;
			float temp = plan.at<float>(i*plan.rows + j);
			fs << (int)temp << "  :  ";
		}
		fs << "\n";
	}


	fs.close();
}

void saveTestData(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, float emd, float emd_ap, Mat plan, String filename)
{
	saveTestData(data1, data2, data3, emd, plan, filename);
	int dim = data4.size();
	fstream fs;
	fs.open(filename, fstream::in | fstream::out | fstream::app);
	fs << "\n";
	fs << "emd_ap:" << emd << "\n";

	fs << "Grad_ap:\n";
	for (int i = 0; i <dim; i++)
	{
		fs << i << "	";
	}
	fs << "\n";
	for (int i = 0; i < dim; i++)
	{
		fs << data4[i] << "	";
	}
	fs << "\n";
	fs.close();
}

void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, String  filename)
{
	int bins = data1.size();
	int max01 = 0;
	float max[3] = { data1[0], data2[0], data3[0] };
	float min[3] = { data1[0], data2[0], data3[0] };
	for (int i = 0; i < bins; i++)
	{
		if (data1[i]>max[0])
			max[0] = data1[i];
		if (data1[i]<min[0])
			min[0] = data1[i];
		if (data2[i]>max[1])
			max[1] = data2[i];
		if (data2[i]<min[1])
			min[1] = data2[i];
		if (data3[i]>max[2])
			max[2] = data3[i];
		if (data3[i]<min[2])
			min[2] = data3[i];
	}


	if (max[0]>max[1])
		max01 = max[0];
	else
		max01 = max[1];

	if (abs(max[2]) > abs(min[2]))
		max[2] = max[2];
	else
		max[2] = abs(min[2]);

	int scale = 30;
	int hist_height = 200;

	Mat result_img = Mat::zeros((hist_height + 20) * 3, bins*scale, CV_8UC1);

	//Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
	for (int i = 0; i < bins; i++)
	{
		float bin_val = data1[i];
		int intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			255);

		bin_val = data2[i];
		intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height * 2 + 20 - 1),
			Point((i + 1)*scale - 1, hist_height * 2 + 20 - intensity),
			255);


		bin_val = abs(data3[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[2]);  //Ҫ���Ƶĸ߶�
		if (data3[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) + intensity - 1), 255);
	}
	//imshow("result_img", result_img);
	imwrite(filename, result_img);
	//cvWaitKey();
}

void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, String  filename)
{
	int bins = data1.size();
	int max01 = 0;
	int max23 = 0;
	float max[4] = { data1[0], data2[0], data3[0], data4[0] };
	float min[4] = { data1[0], data2[0], data3[0], data4[0] };
	for (int i = 0; i < bins; i++)
	{
		if (data1[i]>max[0])
			max[0] = data1[i];
		if (data1[i]<min[0])
			min[0] = data1[i];
		if (data2[i]>max[1])
			max[1] = data2[i];
		if (data2[i]<min[1])
			min[1] = data2[i];
		if (data3[i]>max[2])
			max[2] = data3[i];
		if (data3[i]<min[2])
			min[2] = data3[i];
		if (data4[i]>max[3])
			max[3] = data4[i];
		if (data4[i]<min[3])
			min[3] = data4[i];
	}


	if (max[0]>max[1])
		max01 = max[0];
	else
		max01 = max[1];

	if (abs(max[2]) > abs(min[2]))
		max[2] = max[2];
	else
		max[2] = abs(min[2]);


	if (abs(max[3]) > abs(min[3]))
		max[3] = max[3];
	else
		max[3] = abs(min[3]);

	if (max[2]>max[3])
		max23 = max[2];
	else
		max23 = max[3];

	int scale = 30;
	int hist_height = 200;

	Mat result_img = Mat::zeros((hist_height + 20) * 4, bins*scale, CV_8UC1);

	//Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
	for (int i = 0; i < bins; i++)
	{
		float bin_val = data1[i];
		int intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			255);

		bin_val = data2[i];
		intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height * 2 + 20 - 1),
			Point((i + 1)*scale - 1, hist_height * 2 + 20 - intensity),
			255);


		bin_val = abs(data3[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[2]);//max23);  //Ҫ���Ƶĸ߶�
		if (data3[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) + intensity - 1), 255);

		bin_val = abs(data4[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[3]); //max23);  //Ҫ���Ƶĸ߶�
		if (data4[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 3 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 3 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 3 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 3 + 40 + (hist_height / 2) + intensity - 1), 255);
	}
	//imshow("result_img", result_img);
	imwrite(filename, result_img);
	//cvWaitKey();
}

void saveImage(vector<float> data1, vector<float> data2, vector<float> data3, vector<float> data4, vector<float> data5, String  filename)
{
	int bins = data1.size();
	int max01 = 0;
	int max23 = 0;
	float max[5] = { data1[0], data2[0], data3[0], data4[0], data5[0] };
	float min[5] = { data1[0], data2[0], data3[0], data4[0], data5[0] };
	for (int i = 0; i < bins; i++)
	{
		if (data1[i]>max[0])
			max[0] = data1[i];
		if (data1[i]<min[0])
			min[0] = data1[i];
		if (data2[i]>max[1])
			max[1] = data2[i];
		if (data2[i]<min[1])
			min[1] = data2[i];
		if (data3[i]>max[2])
			max[2] = data3[i];
		if (data3[i]<min[2])
			min[2] = data3[i];
		if (data4[i]>max[3])
			max[3] = data4[i];
		if (data4[i]<min[3])
			min[3] = data4[i];
		if (data5[i]>max[4])
			max[4] = data5[i];
		if (data5[i]<min[4])
			min[4] = data5[i];
	}


	if (max[0]>max[1])
		max01 = max[0];
	else
		max01 = max[1];

	if (abs(max[2]) > abs(min[2]))
		max[2] = max[2];
	else
		max[2] = abs(min[2]);


	if (abs(max[3]) > abs(min[3]))
		max[3] = max[3];
	else
		max[3] = abs(min[3]);

	if (abs(max[4]) > abs(min[4]))
		max[4] = max[4];
	else
		max[4] = abs(min[4]);

	if (max[2]>max[3])
		max23 = max[2];
	else
		max23 = max[3];

	int scale = 30;
	int hist_height = 200;

	Mat result_img = Mat::zeros((hist_height + 20) * 5, bins*scale, CV_8UC1);

	//Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
	for (int i = 0; i < bins; i++)
	{
		float bin_val = data1[i];
		int intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			255);

		bin_val = data2[i];
		intensity = cvRound(bin_val*hist_height / max01);  //Ҫ���Ƶĸ߶�
		rectangle(result_img, Point(i*scale, hist_height * 2 + 20 - 1),
			Point((i + 1)*scale - 1, hist_height * 2 + 20 - intensity),
			255);


		bin_val = abs(data3[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[2]);//max23);  //Ҫ���Ƶĸ߶�
		if (data3[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 2 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 2 + 40 + (hist_height / 2) + intensity - 1), 255);

		bin_val = abs(data4[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[3]); //max23);  //Ҫ���Ƶĸ߶�
		if (data4[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 3 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 3 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 3 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 3 + 40 + (hist_height / 2) + intensity - 1), 255);


		bin_val = abs(data5[i]);
		intensity = cvRound(bin_val*(hist_height / 2) / max[4]); //max23);  //Ҫ���Ƶĸ߶�
		if (data5[i]>0)
			rectangle(result_img, Point(i*scale, hist_height * 4 + 40 + (hist_height / 2) - 1), Point((i + 1)*scale - 1, hist_height * 4 + 40 + (hist_height / 2) - intensity), 255);
		else
			rectangle(result_img, Point(i*scale, hist_height * 4 + 40 + hist_height / 2 - 1), Point((i + 1)*scale - 1, hist_height * 4 + 40 + (hist_height / 2) + intensity - 1), 255);
	}
	//imshow("result_img", result_img);
	imwrite(filename, result_img);
	//cvWaitKey();
}


float emd_ap(vector<float> SData, vector<float> DData)
{
	int N = SData.size();
	int sumS = sumData(SData);
	int sumD = sumData(DData);
	float emd = 0;
	for (int i = 0; i < N; i++)
	{
		float ph_res = ph(SData, DData, i);
		//for (int j = 0; j < i; j++)
		//{
		//	ph += (SData[j] / sumS - DData[j] / sumD);
		//}
		emd += abs(ph_res);
	}
	return emd;
}

int sumData(vector<float> Data)
{
	int size = Data.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += Data.at(i);
	}
	return sum;
}
float ph(vector<float> SData, vector<float> DData, int i)
{
	int sumS = sumData(SData);
	int sumD = sumData(DData);
	float ph = 0;
	for (int j = 0; j < i; j++)
	{
		ph += (SData[j] / sumS - DData[j] / sumD);
	}
	return ph;
}


vector<float> emdGrad_ap(vector<float> SData, vector<float> DData)
{
	vector<float> grad_res;
	int N = SData.size();
	for (int i = 0; i < N; i++)
	{
		float temp = emdGradSingle_ap(SData, DData, i);
		grad_res.push_back(temp);
	}
	return grad_res;
}

float emdGradSingle_ap(vector<float> SData, vector<float> DData, int k)
{

	int N = SData.size();
	vector<float> delta(N, 0);
	delta[k] = 1;
	float grad = 0;
	for (int i = 0; i < N; i++)
	{
		int sgn_ph = ph(DData, SData, i) > 0 ? 1 : -1;
		int sum_delta = 0;
		for (int j = 0; j < i; j++)
		{
			sum_delta += (delta[j] * N - 1);
		}
		grad += sgn_ph*sum_delta;
	}
	return grad;
}