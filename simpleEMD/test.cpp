//#define DATA_SIZE 10
//
//#include "emd.h"
//#include "util.h"
//
//int main() 
//{
//	//≥ı ºªØ
//	float delta = 1;
//	String filename = "result.txt";
//	feature_t   f1[DATA_SIZE] = { 0 }, f2[DATA_SIZE] = { 0 };
//
//	float       w1[DATA_SIZE] = {10,19,18,17,16,15,14,13,12,11}, w2[DATA_SIZE] = {2,13,14,15,16,17,18,8,10,12};
//	for (int i = 0; i < DATA_SIZE; i++)
//	{
//		f1[i].x = i;
//		f2[i].x = i;
//	}
//
//	//make signature
//	//Mat sig1(DATA_SIZE, 1, CV_32FC1);
//	//Mat sig2(DATA_SIZE, 1, CV_32FC1);
//	////fill value into signature
//	//for (int h = 0; h< DATA_SIZE; h++)
//	//{
//
//	//	sig1.at< float>(h) = w1[h];
//	//	sig2.at< float>(h) = w2[h];
//
//	//}
//	Mat sig1(DATA_SIZE,2, CV_32FC1);
//	Mat sig2(DATA_SIZE,2, CV_32FC1);
//	for (int h = 0; h< DATA_SIZE; h++)
//	{
//		sig1.at< float>(h * 2+1 ) = h+1;
//		sig2.at< float>(h * 2+1) = h + 1;
//		sig1.at< float>(h*2) = w1[h];
//		sig2.at< float>(h * 2) = w2[h];
//
//	}
//	//drawHis(w1, DATA_SIZE, "data1");
//	flow_t flows[DATA_SIZE * 2 - 1];
//	int flowsize[DATA_SIZE * 2 - 1] = {0};
//	signature_t s1 = { DATA_SIZE, f1, w1 }, s2 = { DATA_SIZE, f2, w2 };
//	float       e_s1s2;
//
//	//compare similarity of 2images using emd.
//	Mat flow;
//	Mat cost(DATA_SIZE, DATA_SIZE, CV_32FC1);
//	for (int i = 0; i < cost.rows; i++){
//		for (int j = 0; j < cost.cols; j++)
//		{
//			cost.at<float>(i*cost.rows + j) = dist(&(s1.Features[i]), &(s2.Features[j]));
//		}
//	}
//
//	float emd_opencv = cv::EMD(sig1, sig2, CV_DIST_L2, 0, 0, flow); //emd 0 is best matching. 
//	printf("emd:%f\n", emd_opencv);
//
//	for (int i = 0; i < flow.rows; i++){
//		for (int j = 0; j < flow.cols; j++)
//		{
//			if (flow.at<float>(i*flow.rows + j)<0)
//				flow.at<float>(i*flow.rows + j) = 0;
//		}
//	}
//
//	for (int i = 0; i < flow.rows; i++){
//		for (int j = 0; j < flow.cols; j++)
//		{
//			printf("%d;;", (int)flow.at<float>(i*flow.rows + j));
//		}
//		printf("\n");
//	}
//
//
//
//	e_s1s2 = emd(&s1, &s2, dist, flows, flowsize);
//
//	int size = s1.n*s2.n;
//	int* result = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		result[i] = 0;
//	}
//
//
//
//	for (int i = 0; i < DATA_SIZE*2-1; i++)
//	{
//		int index = flows[i].from*DATA_SIZE + flows[i].to;
//		if (index < 0)
//			continue;
//		result[index] = (int)flows[i].amount;
//	}
//
//		//fstream fs;
//		//fs.open(filename, fstream::in | fstream::out | fstream::app);
//
//		//fs<<"emd_s1s2="<< e_s1s2<<"\n";
//
//		//fs << "emd_s1s2_plan:\n";
//		//for (int i = 0; i <s1.n; i++)
//		//{
//		//	for (int j = 0; j < s1.n; j++)
//		//	{
//		//		fs << result[i*s1.n + j]<<";;";
//		//	}
//		//	fs<<"\n";
//		//}
//		//fs << "\n";
//		//fs.close();
//
//		printf("emd_s1s2=%f\n",e_s1s2);
//
//		printf("emd_s1s2_plan:\n");
//		for (int i = 0; i <s1.n; i++)
//		{
//			for (int j = 0; j < s1.n; j++)
//			{
//				printf("%d::",result[i*s1.n + j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	
//	//calGrad(&s1, &s2, dist, delta, "s1_s2_delta");
//
//
//	return 0;
//}
