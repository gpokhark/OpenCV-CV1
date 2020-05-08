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
	double contrastPercentage = 30.0;
	// Multiply with scaling factor to increase contrast
	Mat contrastHigh = image;
	// Convert contrastHigh to float
	contrastHigh.convertTo(contrastHigh, CV_64F);
	contrastHigh = contrastHigh * (1+contrastPercentage/100.0);
	imwrite("../results/highContrast.png",contrastHigh);
	//imshow("High Contrast",contrastHigh);
	//waitKey(0);
	
	return 0;
}
