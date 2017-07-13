//#define TEST_NUM 1
//#define TEST_SIZE 10
//#define DATA_SIZE 10
//#define DELTA 1
//
//#include <iostream>
//#include <fstream>
//#include <stdio.h>
//#include "emd.h"
//#include "util.h"　
//using namespace std;
//
//int main()
//{
//	char buffer[256];
//	int supplys[TEST_SIZE][DATA_SIZE];
//	int demands[TEST_SIZE][DATA_SIZE];
//	//自定义数据的读入
//	ifstream in("test.txt");
//	if (!in.is_open())
//	{
//		cout << "not open";
//	}
//	
//		for (int i = 0; i < TEST_SIZE; i++)
//		{
//			if (!in.eof()){
//				for (int j = 0; j < DATA_SIZE; j++)
//				{
//					if (j == 9)
//						in.getline(buffer, 20, '\n');
//					else
//						in.getline(buffer, 20, ' ');
//					supplys[i][j] = atoi(buffer);
//				}
//				for (int j = 0; j < DATA_SIZE; j++)
//				{
//					if (j == 9)
//						in.getline(buffer, 20, '\n');
//					else
//						in.getline(buffer, 20, ' ');
//					demands[i][j] = atoi(buffer);
//				}
//			}
//			else
//				break;
//		}
//		
//
//	//计算emd
//
//		feature_t   f1[DATA_SIZE] = { 0 }, f2[DATA_SIZE] = { 0 };
//		for (int i = 0; i < DATA_SIZE; i++)
//		{
//			f1[i].x = i + 1;
//			f2[i].x = i + 1;
//		}
//		//土
//		float  w1[DATA_SIZE] = { 0 }, w2[DATA_SIZE] = { 0 };
//	
//		//两个签名
//		signature_t s1 = { DATA_SIZE, f1, w1 }, s2 = { DATA_SIZE, f2, w2 };
//	
//		String filename = "design";
//		String filename_temp = filename;
//		String filename_img = filename;
//		fstream fs;
//	
//		float emd_me,emd_delta;// , emd_delta_me_temp, emd_delta_opencv_temp;
//		float emd_grad_me[DATA_SIZE] = { 0 };
//		//float emd_delta_me[DATA_SIZE] = { 0 }, emd_delta_opencv[DATA_SIZE] = { 0 }, emd_grad_me[DATA_SIZE] = { 0 }, emd_grad_opencv[DATA_SIZE] = { 0 };
//		flow_t flows[DATA_SIZE * 2 - 1];
//		int flowsize[DATA_SIZE * 2 - 1] = { 0 };
//		int size = s1.n*s2.n;
//		int* result = new int[size];
//		int* result_delta = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			result[i] = 0;
//			result_delta[i] = 0;
//		}
//	
//		
//		
//		//循环处理不同数据
//		for (int test_index = 0; test_index < TEST_SIZE; test_index++)
//		{
//			filename_temp = filename;
//			filename_img = filename;
//			filename_temp.append(".txt");
//			filename_img.append(to_string(test_index) + ".jpg");
//			//填充数据
//			for (int i = 0; i < DATA_SIZE; i++)
//			{
//				s1.Weights[i] = supplys[test_index][i];
//				s2.Weights[i] = demands[test_index][i];
//			}
//	
//				
//			//文件保存基本信息
//			/*fs.open(filename_temp, fstream::in | fstream::out | fstream::app);
//			fs.close();
//			saveBasicInfo(&s1, &s2, dist, DELTA, filename_temp, 0);
//			fs.open(filename_temp, fstream::in | fstream::out | fstream::app);*/
//			saveBasicInfo(&s1, &s2, dist, DELTA, filename_temp, 0);
//			fs.open(filename_temp, fstream::in | fstream::out | fstream::app);
//	
//			//计算结果
//			emd_me = emd(&s1, &s2, dist, flows, flowsize);
//	
//			for (int i = 0; i < DATA_SIZE*2-1; i++) // for me emd
//			{
//				int index = flows[i].from*DATA_SIZE + flows[i].to;
//				if (index < 0)
//					continue;
//				result[index] = (int)flows[i].amount;
//				int temp = result[index];
//			}
//			//输出结果
//			fs << "emd_me:    " << emd_me << "\n";
//			fs << "emd_me_plan:    " << "\n";
//			for (int i = 0; i <s1.n; i++)
//			{
//				for (int j = 0; j < s1.n; j++)
//				{
//					fs << result[i*s1.n + j] << "  ;  ";
//				}
//				fs << "\n";
//			}
//			fs << "\n";
//	
//			//fs << "emd_opencv_plan:    " << "\n";
//			
//	
//			//求偏导
//			for (int index = 0; index < DATA_SIZE; index++)
//			{
//				//fs << "-·-·-·-·-·-·-·-·-s"; fs << index; fs << "+delta-·-·-·-·-·-·-·-·-\n";
//				addDelta(&s1, DELTA, index);
//				emd_delta = emd(&s1, &s2, dist, flows, flowsize);
//				for (int i = 0; i < DATA_SIZE*2-1; i++) // for me emd
//				{
//					int index = flows[i].from*DATA_SIZE + flows[i].to;
//					if (index < 0)
//						continue;
//					result_delta[index] = (int)flows[i].amount;
//				}
//				////输出结果
//				//fs << "emd_delta_" << index << ":    " << emd_delta << "\n";
//				//fs << "emd_me__" << index << "plan:    " << "\n";
//				//for (int i = 0; i <s1.n; i++)
//				//{
//				//	for (int j = 0; j < s1.n; j++)
//				//	{
//				//		fs << result_delta[i*s1.n + j] << "  ;  ";
//				//	}
//				//	fs << "\n";
//				//}
//				//fs << "\n";
//
//				emd_grad_me[index] = emd_delta - emd_me;
//			}
//			fs << "gradiant:(with delta="<<DELTA<<")";
//			fs << "\n";
//			for (int i = 0; i < DATA_SIZE; i++)
//			{
//				fs << emd_grad_me[i] << " ";
//			}
//			fs << "\n";
//			fs << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-\n";
//			saveImage(w1, w2, emd_grad_me, DATA_SIZE, filename_img);
//			fs.close();
//		}
//	return 0;
//}