// Include libraries
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

int main(void){

	// Path to the image we are going to read
	// This can be an absolute or relative path
	// Here we are using a relative path
	string imageName = DATA_PATH+"images/boy.jpg";

	// Load the image
	Mat image;
	image = imread(imageName, IMREAD_COLOR);

	//imshow("Input Image",image);
	//waitKey(0);

	return 0;
}
