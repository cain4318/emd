#include "util.h"

float dist(feature_t *F1, feature_t *F2)
{
	float dX = dist( F1->x ,F2->x);
	return sqrt(double(dX*dX));
}

float dist(float p1, float p2)
{
	float dX =p1-p2;
	return sqrt(double(dX*dX));
}

void drawHis(float data[], int size, String title){

	int bins = size;
	int hist_size[] = { bins };

	float max = data[0];
	float min = data[0];
	for (int i = 0; i < size; i++)
	{
		if (data[i]>max)
			max = data[i];
		if (data[i]<min)
			min = data[i];
	}
	if (min < 0)
	{
		for (int i = 0; i < size; i++)
			data[i] = data[i] - min;
		max = max - min;
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

void addDelta(signature_t *Signature, float delta, int index) {
	if (index>Signature->n - 1)
	{
		Signature->Weights[index - 1] = Signature->Weights[index - 1] - delta;
		return;
	}
	if (index==0)
		Signature->Weights[index] = Signature->Weights[index] + delta;
		
	if (index != 0){
		Signature->Weights[index - 1] = Signature->Weights[index - 1] - delta;
		Signature->Weights[index] = Signature->Weights[index] + delta;
	}
}

void addDelta(Mat *Signature, float delta, int index)
{
	if (index != 0)
	{
		Signature->at< float>((index - 1) * 2+1) -= delta;
		Signature->at< float>(index * 2+1) += delta;
	}
}


void calGrad(signature_t *Signature1, signature_t *Signature2,
	float(*func)(feature_t *, feature_t *), float Delta, String title)
{
	signature_t* Signature_temp = Signature1;
	float delta = Delta;

	float *grad = new float[Signature1->n];
	int size = Signature1->n*Signature2->n;
	int* result = new int[size];
	int* result_delta = new int[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = 0;
		result_delta[i] = 0;
	}

	for (int i = 0; i < Signature1->n; i++)
	{
		for (int j = 0; j < Signature2->n; j++)
		{
			result[i*(Signature1->n) + j] = 0;
			result_delta[i*(Signature1->n) + j] = 0;
		}
		grad[i] = 0;
	}
	float e = emd(Signature1, Signature2, dist, 0, 0);

	for (int i = 0; i < Signature1->n; i++)
	{
		addDelta(Signature_temp, delta, i);
		float e_delta = emd(Signature_temp, Signature2, dist, 0, 0);

		//fstream fs;
		//fs.open("result.txt", fstream::in | fstream::out | fstream::app);
		//fs << "\n";
		//fs << "e_delta_s1s2_" << i << ":" << e_delta << "\n";

		//fs << "e_delta_s1s2_" << i << "_plan:\n";
		//for (int i = 0; i <Signature_temp->n; i++)
		//{
		//	for (int j = 0; j < Signature_temp->n; j++)
		//	{
		//		fs << result_delta[i*Signature_temp->n + j] << ";;";
		//	}
		//	fs << "\n";
		//}
		//fs.close();

		grad[i] = (e_delta - e) / delta;
	}


	//fstream fs;
	//fs.open("result.txt", fstream::in | fstream::out | fstream::app);
	//fs << "\n";
	//fs << "e_delta_s1s2_grad:\n";
	//for (int i = 0; i < Signature1->n; i++)
	//{
	//	fs << grad[i] << ";;";
	//}
	//fs.close();
	//drawHis(grad, Signature1->n,title);
	//+delta_x

}

/*保存基本信息（Signature1，Signature2，距离函数，delta，文件名）*/
void saveBasicInfo(signature_t *Signature1, signature_t *Signature2,
	float(*func)(feature_t *, feature_t *), float Delta, String filename,bool showCostMatrx)
{
	fstream fs;
	fs.open(filename, fstream::in | fstream::out | fstream::app);
	int sun = 0;
	fs << "Supplys(in rows):\n";
	for (int i = 0; i < Signature1->n; i++)
	{
		fs << "s" << i << "	";
	}
	fs << "\n";
	for (int i = 0; i < Signature1->n; i++)
	{
		fs << Signature1->Weights[i] << "	";
	}
	fs << "\n";
	fs << "Demands(in cols):\n";
	for (int i = 0; i < Signature2->n; i++)
	{
		fs << "d" << i << "	";
	}
	fs << "\n";
	for (int i = 0; i < Signature2->n; i++)
	{
		fs << Signature2->Weights[i] << "	";
	}
	fs << "\n";
	if (showCostMatrx){
		fs << "unit cost matrex:\n";
		for (int i = 0; i < Signature1->n; i++)
		{
			for (int j = 0; j < Signature2->n; j++)
			{
				float temp = func(&(Signature1->Features[i]), &(Signature2->Features[j]));
				fs << (int)temp << "  :  ";
			}
			fs << "\n";
		}
	}
	fs << "delta:" << Delta;

	fs.close();
}


void saveImage(float data1[], float data2[], float data3[], int size,String  filename)
{
	int bins = size;
	int max01=0;
	float max[3] = { data1[0], data2[0], data3[0] };
	float min[3] = { data1[0], data2[0], data3[0] };
	for (int i = 0; i < size; i++)
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
	if (min[0] < 0)
	{
		for (int i = 0; i < size; i++)
			data1[i] = data1[i] - min[0];
		max[0] = max[0] - min[0];
	}

	if (min[1] < 0)
	{
		for (int i = 0; i < size; i++)
			data2[i] = data2[i] - min[1];
		max[1] = max[1] - min[1];
	}

	if (min[2] < 0)
	{
		for (int i = 0; i < size; i++)
			data3[i] = data3[i]*(-1);
		max[2]=min[2]*(-1);
	}

	if (max[0]>max[1])
		max01 = max[0];
	else
		max01 = max[1];
	int scale = 30;
	int hist_height = 200;

	Mat result_img = Mat::zeros((hist_height+20)*3, bins*scale, CV_8UC1);

	//Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC1);
		for (int i = 0; i < bins; i++)
		{
			float bin_val = data1[i];
			int intensity = cvRound(bin_val*hist_height / max01);  //要绘制的高度
			rectangle(result_img, Point(i*scale, hist_height - 1),
				Point((i + 1)*scale - 1, hist_height - intensity),
				255);

			bin_val = data2[i];
			intensity = cvRound(bin_val*hist_height / max01);  //要绘制的高度
			rectangle(result_img, Point(i*scale, hist_height*2+20 - 1),
				Point((i + 1)*scale - 1, hist_height * 2 + 20 - intensity),
				255);

			bin_val = data3[i];
			intensity = cvRound(bin_val*hist_height / max[2]);  //要绘制的高度
			rectangle(result_img, Point(i*scale, hist_height * 3 + 40 - 1),
				Point((i + 1)*scale - 1, hist_height * 3 + 40 - intensity),
				255);
		}
	//imshow("result_img", result_img);
	imwrite(filename, result_img);
	//cvWaitKey();
}