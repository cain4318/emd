//#define test_size 10
//#define data_size 10
//#define delta 1
//
//#include "emd.h"
//#include "util.h"　
//
//int main()
//{
//	//初始化
//
//	//feature(position)
//	feature_t   f1[data_size] = { 0 }, f2[data_size] = { 0 };
//	for (int i = 0; i < data_size; i++)
//	{
//		f1[i].x = i + 1;
//		f2[i].x = i + 1;
//	}
//	//土
//	float  w1[data_size] = { 0 }, w2[data_size] = { 0 };
//
//	//两个签名
//	signature_t s1 = { data_size, f1, w1 }, s2 = { data_size, f2, w2 };
//
//	//random num
//	default_random_engine generator;
//	uniform_int_distribution<int> distribution(10, 100);
//
//	string filename = "vs_opencv";
//	string filename_temp = filename;
//	string filename_img = filename;
//	fstream fs;
//	fs.open(filename, fstream::in | fstream::out | fstream::trunc);
//	fs << "compare the results \n";
//	fs.close();
//
//	float emd_me,emd_delta;// , emd_delta_me_temp, emd_delta_opencv_temp;
//	float emd_grad_me[data_size] = { 0 };
//	//float emd_delta_me[data_size] = { 0 }, emd_delta_opencv[data_size] = { 0 }, emd_grad_me[data_size] = { 0 }, emd_grad_opencv[data_size] = { 0 };
//	flow_t flows[data_size * 2 - 1];
//	int flowsize[data_size * 2 - 1] = { 0 };
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
//	mat sig1(data_size, 2, cv_32fc1);
//	mat sig2(data_size, 2, cv_32fc1);
//	mat flow;
//
//
//	//循环处理不同数据
//	for (int test_index = 0; test_index < test_size; test_index++)
//	{
//		filename_temp = filename;
//		filename_img = filename;
//		filename_temp.append(to_string(test_index) + ".txt");
//		filename_img.append(to_string(test_index) + ".jpg");
//		//填充数据
//		for (int i = 0; i < data_size; i++)
//		{
//			int  temp = distribution(generator);
//			s1.weights[i] = temp;
//			temp = distribution(generator);
//			s2.weights[i] = temp;
//		}
//
//		//opencv
//		for (int h = 0; h< data_size; h++)
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
//		fs.close();
//		savebasicinfo(&s1, &s2, dist, delta, filename_temp, 0);
//		fs.open(filename_temp, fstream::in | fstream::out | fstream::app);
//		fs << "\n\n";
//
//		//计算结果
//		emd_me = emd(&s1, &s2, dist, flows, flowsize);
//		float emd_opencv = cv::emd(sig1, sig2, cv_dist_l2, 0, 0, flow); //emd 0 is best matching. 
//
//		for (int i = 0; i < data_size*2-1; i++) // for me emd
//		{
//			int index = flows[i].from*data_size + flows[i].to;
//			if (index < 0)
//				continue;
//			result[index] = (int)flows[i].amount;
//			int temp = result[index];
//		}
//		//输出结果
//		fs << "emd_me:    " << emd_me << "\n";
//		fs << "emd_opencv:    " << emd_opencv << "\n";
//		fs << "emd_me_plan:    " << "\n";
//		for (int i = 0; i <s1.n; i++)
//		{
//			for (int j = 0; j < s1.n; j++)
//			{
//				fs << result[i*s1.n + j] << "  ;  ";
//			}
//			fs << "\n";
//		}
//		fs << "\n";
//
//		fs << "emd_opencv_plan:    " << "\n";
//		for (int i = 0; i < flow.rows; i++){
//			for (int j = 0; j < flow.cols; j++)
//			{
//				if (flow.at<float>(i*flow.rows + j)<0)
//					flow.at<float>(i*flow.rows + j) = 0;
//			}
//		}
//
//		for (int i = 0; i < flow.rows; i++){
//			for (int j = 0; j < flow.cols; j++)
//			{
//				fs<<(int)flow.at<float>(i*flow.rows + j)<<" :: ";
//			}
//			fs << "\n";
//		}
//
//		//求偏导
//		for (int index = 0; index < data_size; index++)
//		{
//			fs << "-·-·-·-·-·-·-·-·-s"; fs << index; fs << "+delta-·-·-·-·-·-·-·-·-\n";
//			adddelta(&s1, delta, index);
//			emd_delta = emd(&s1, &s2, dist, flows, flowsize);
//			for (int i = 0; i < data_size*2-1; i++) // for me emd
//			{
//				int index = flows[i].from*data_size + flows[i].to;
//				if (index < 0)
//					continue;
//				result_delta[index] = (int)flows[i].amount;
//			}
//			//输出结果
//			fs << "emd_delta_" << index << ":    " << emd_delta << "\n";
//			fs << "emd_me__" << index << "plan:    " << "\n";
//			for (int i = 0; i <s1.n; i++)
//			{
//				for (int j = 0; j < s1.n; j++)
//				{
//					fs << result_delta[i*s1.n + j] << "  ;  ";
//				}
//				fs << "\n";
//			}
//			fs << "\n";
//			emd_grad_me[index] = emd_delta - emd_me;
//		}
//		fs << "gradiant:(with delta="<<delta<<")";
//		fs << "\n";
//		for (int i = 0; i < data_size; i++)
//		{
//			fs << emd_grad_me[i] << " ";
//		}
//		fs << "\n";
//		
//		saveimage(w1, w2, emd_grad_me, data_size, filename_img);
//		fs.close();
//	}
//	return 0;
//}