#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>

using namespace std;
using namespace cv;
vector<int> findMinInAll(Mat Data, vector<int> colMins);
vector<int> findMinInCols(Mat Data, int colIndex, vector<int> colMins);