// Include libraries
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(void){
	// Read image
	Mat image = imread(DATA_PATH+"images/boy.jpg");
	
	double scalingFactor = 1/255.0;
	double shift = 0;

	//Converting from unsigned char to float(32bit)
	image.convertTo(image, CV_32FC3, scalingFactor, shift);
	
	//Converting from float to unsigned char
	image.convertTo(image, CV_8UC3, 1.0/scalingFactor, shift);
	
	return 0;
}
