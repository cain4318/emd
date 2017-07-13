//#define TEST_SIZE 10
//#define DATA_SIZE 10
//#define DELTA_SIZE 20
//
//#include "emd.h"
//#include "util.h"　
//
//int main()
//{
//	//定义delta层次：
//	float DELTA[20] = { 10, 8, 5, 3, 2, 1, 0.8, 0.5, 0.3, 0.2, 0.1, 0.08, 0.05, 0.03, 0.02, 0.01, 0.008, 0.005, 0.003, 0.002 };
//	//初始化
//
//	//Feature(position)
//	feature_t   f1[DATA_SIZE] = { 0 }, f2[DATA_SIZE] = { 0 };
//	for (int i = 0; i < DATA_SIZE; i++)
//	{
//		f1[i].x = i + 1;
//		f2[i].x = i + 1;
//	}
//	//土
//	float  w1[DATA_SIZE] = { 0 }, w2[DATA_SIZE] = { 0 };
//
//	//两个签名
//	signature_t s1 = { DATA_SIZE, f1, w1 }, s2 = { DATA_SIZE, f2, w2 };
//
//	//random num
//	default_random_engine generator;
//	uniform_int_distribution<int> distribution(100, 1000);
//
//	String filename = "diff_Delta_data";
//	String filename_temp = filename;
//	String filename_img = filename;
//	fstream fs;
//	
//	float emd_me, emd_delta;// , emd_delta_me_temp, emd_delta_opencv_temp;
//	float emd_grad_me[DATA_SIZE] = { 0 };
//	//float emd_delta_me[DATA_SIZE] = { 0 }, emd_delta_opencv[DATA_SIZE] = { 0 }, emd_grad_me[DATA_SIZE] = { 0 }, emd_grad_opencv[DATA_SIZE] = { 0 };
//	flow_t flows[DATA_SIZE * 2 - 1];
//	int flowsize[DATA_SIZE * 2 - 1] = { 0 };
//	int size = s1.n*s2.n;
//	int* result = new int[size];
//	int* result_delta = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		result[i] = 0;
//		result_delta[i] = 0;
//	}
//
//
//	//opencv:
//	Mat sig1(DATA_SIZE, 2, CV_32FC1);
//	Mat sig2(DATA_SIZE, 2, CV_32FC1);
//	Mat flow;
//
//
//	//循环处理不同数据
//	for (int test_index = 0; test_index < TEST_SIZE; test_index++)
//	{
//		filename_temp = filename;
//		filename_img = filename;
//		filename_temp.append(to_string(test_index) + ".txt");
//		filename_img.append(to_string(test_index) + ".jpg");
//		//填充数据
//		for (int i = 0; i < DATA_SIZE; i++)
//		{
//			int  temp = distribution(generator);
//			s1.Weights[i] = temp;
//			temp = distribution(generator);
//			s2.Weights[i] = temp;
//		}
//
//		//opencv
//		for (int h = 0; h< DATA_SIZE; h++)
//		{
//			sig1.at< float>(h * 2 + 1) = h + 1;
//			sig2.at< float>(h * 2 + 1) = h + 1;
//			sig1.at< float>(h * 2) = w1[h];
//			sig2.at< float>(h * 2) = w2[h];
//
//		}
//
//
//		//文件保存基本信息
//		fs.open(filename_temp, fstream::in | fstream::out | fstream::trunc);
//		//fs.close();
//		//saveBasicInfo(&s1, &s2, dist, DELTA[0], filename_temp, 0);
//		//fs.open(filename_temp, fstream::in | fstream::out | fstream::app);
//		//fs << "\n\n";
//
//		//计算结果
//		emd_me = emd(&s1, &s2, dist, flows, flowsize);
//	//	float emd_opencv = cv::EMD(sig1, sig2, CV_DIST_L2, 0, 0, flow); //emd 0 is best matching. 
//
//		//for (int i = 0; i < DATA_SIZE * 2 - 1; i++) // for me emd
//		//{
//		//	int index = flows[i].from*DATA_SIZE + flows[i].to;
//		//	if (index < 0)
//		//		continue;
//		//	result[index] = (int)flows[i].amount;
//		//	int temp = result[index];
//		//}
//		//输出结果
//	//	fs << "emd_me:    " << emd_me << "\n";
//		//fs << "emd_opencv:    " << emd_opencv << "\n";
//		
//		for (int num_delta = 0; num_delta < DELTA_SIZE; num_delta++){
//			//求偏导
//			for (int index = 0; index < DATA_SIZE; index++)
//			{
//				//fs << "-·-·-·-·-·-·-·-·-s"; fs << index; fs << "+delta-·-·-·-·-·-·-·-·-\n";
//				addDelta(&s1, DELTA[num_delta], index);
//				emd_delta = emd(&s1, &s2, dist, flows, flowsize);
//				for (int i = 0; i < DATA_SIZE * 2 - 1; i++) // for me emd
//				{
//					int index = flows[i].from*DATA_SIZE + flows[i].to;
//					if (index < 0)
//						continue;
//					result_delta[index] = (int)flows[i].amount;
//				}
//				////输出结果
//				//fs << "emd_delta_" << index << ":    " << emd_delta << "\n";
//				//fs << "emd_me__" << index << "plan:    " << "\n";
//				//for (int i = 0; i < s1.n; i++)
//				//{
//				//	for (int j = 0; j < s1.n; j++)
//				//	{
//				//		fs << result_delta[i*s1.n + j] << "  ;  ";
//				//	}
//				//	fs << "\n";
//				//}
//				//fs << "\n";
//				emd_grad_me[index] = emd_delta - emd_me;
//			}
//			addDelta(&s1, DELTA[num_delta], s1.n);
//		//	fs << "-·-·-·-gradiant:(with delta=" << DELTA[num_delta] << ")-·-·-·-";
//			//saveBasicInfo(&s1, &s2, dist, DELTA[num_delta], filename_temp, 0);
//		//	fs << "\n";
//			for (int i = 0; i < DATA_SIZE; i++)
//			{
//				fs << emd_grad_me[i] << " ";
//			}
//			fs << "\n";
//
//			//saveImage(w1, w2, emd_grad_me, DATA_SIZE, filename_img);
//		}
//		fs.close();
//	}
//	return 0;
//}