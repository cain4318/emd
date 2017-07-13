/* example1.c */

#include <stdio.h>
#include <math.h>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>  
#include <opencv2\core\core.hpp>

#include "emd.h"
float dist(feature_t *F1, feature_t *F2)
{
  int dX = F1->data - F2->data;
  return sqrt(dX*dX); 
}

main()
{

	feature_t   f1[3] = { 1, 2, 3 },
	      f2[4] = { 1,2,3,4};
  float       w1[3] = { 20,25,15},
              w2[4] = { 10,15,15,20};
  signature_t s1 = { 3, f1, w1},
	      s2 = { 4, f2, w2};
  float       e;

  e = emd(&s1, &s2, dist, 0, 0);

  printf("emd=%f\n", e);
}
