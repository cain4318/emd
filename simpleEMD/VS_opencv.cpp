#define TEST_SIZE 10
#define DATA_SIZE 10
#define DELTA 1

#include "emd.h"
#include "util.h"　

int main()
{
//初始化
	//opencv Mat
	Mat sig1(DATA_SIZE, 2, CV_32FC1);
	Mat sig2(DATA_SIZE, 2, CV_32FC1);

	//Feature(position)
	feature_t   f1[DATA_SIZE] = { 0 }, f2[DATA_SIZE] = { 0 };
	for (int i = 0; i < DATA_SIZE; i++)
	{
		f1[i].x = i+1;
		f2[i].x = i+1;

		sig1.at< float>(i * 2+1) = i+1;
		sig1.at< float>(i * 2) =0;
		sig2.at< float>(i * 2+1) = i+1;
		sig2.at< float>(i * 2 ) =0;
	}
	//土
	float  w1[DATA_SIZE] = { 0 }, w2[DATA_SIZE] = { 0 };

	//两个签名
	signature_t s1 = { DATA_SIZE, f1, w1 }, s2 = { DATA_SIZE, f2, w2 };

	//random num
	default_random_engine generator;
	uniform_int_distribution<int> distribution(100, 500);

	String filename = "VS_opencv.txt";
	fstream fs;
	fs.open(filename, fstream::in | fstream::out | fstream::trunc);
	fs <<"compare the results \n" ;
	fs.close();

	float emd_me, emd_opencv;// , emd_delta_me_temp, emd_delta_opencv_temp;
	//float emd_delta_me[DATA_SIZE] = { 0 }, emd_delta_opencv[DATA_SIZE] = { 0 }, emd_grad_me[DATA_SIZE] = { 0 }, emd_grad_opencv[DATA_SIZE] = { 0 };
	Mat flow_opencv;
	flow_t flows[DATA_SIZE * 2 - 1];
	int flowsize[DATA_SIZE * 2 - 1] = { 0 };
	int size = s1.n*s2.n;
	int* result = new int[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = 0;
	}

//循环处理不同数据
	for (int test_index = 0; test_index < TEST_SIZE; test_index++)
	{
		//填充数据
		for (int i = 0; i < DATA_SIZE; i++)
		{
			int  temp = distribution(generator);
			s1.Weights[i] = temp;
			sig1.at< float>(i * 2) = temp;
			temp = distribution(generator);
			s2.Weights[i] = temp;
			sig2.at< float>(i * 2) = temp;
		}
		
		//文件保存基本信息
		fs.open(filename, fstream::in | fstream::out | fstream::app); 
		fs << "\n\n";
		fs << "-·-·-·-·-·-·-·-·-TEST";fs<<test_index;fs<<"-·-·-·-·-·-·-·-·-\n";
		fs.close();

		saveBasicInfo(&s1, &s2, dist, DELTA, filename,0);
		fs.open(filename, fstream::in | fstream::out | fstream::app);
		fs<<"\n\n";
		
		//计算结果
		emd_me = emd(&s1, &s2, dist, flows, flowsize);
		emd_opencv = EMD(sig1, sig2, CV_DIST_L2,0,0,flow_opencv);
		for (int i = 0; i < flow_opencv.rows; i++){//for opencv emd
			for (int j = 0; j < flow_opencv.cols; j++)
			{
				if (flow_opencv.at<float>(i*flow_opencv.rows + j)<0)
					flow_opencv.at<float>(i*flow_opencv.rows + j) = 0;
			}
		}

		for (int i = 0; i < DATA_SIZE * 2 - 1; i++) // for me emd
		{
			int index = flows[i].from*DATA_SIZE + flows[i].to;
			if (index < 0)
				continue;
			result[index] = (int)flows[i].amount;
		}

		//输出结果
		fs << "emd_me:    " << emd_me << "\n";
		fs << "emd_me_plan:    " << "\n";
		for (int i = 0; i <s1.n; i++)
		{
			for (int j = 0; j < s1.n; j++)
			{
				fs << result[i*s1.n + j] << "  ;  ";
			}
			fs<<"\n";
		}
		fs << "\n";

		fs<< "emd_opencv:" << emd_opencv << "\n";
		fs << "emd_opencv_plan:    " << "\n";
		for (int i = 0; i < flow_opencv.rows; i++){
			for (int j = 0; j < flow_opencv.cols; j++)
			{
				fs << (int)flow_opencv.at<float>(i*flow_opencv.rows + j) << "  ;  ";
			}
			fs<<"\n";
		}

		//save image data(data1_histogram,data2_histogram,grad_histogram)
		//saveImage(w1, w2, grad);
		//drawHis(w1, DATA_SIZE, "data1");
		//drawHis(w2, DATA_SIZE, "data2");
		fs.close();
	}
	return 0;
}