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
	// Crop out a rectangle
	// x coordinates = 170 to 320
	// y coordinates = 40 to 200
	Mat crop = image(Range(40,200),Range(170,320));
	imwrite("../results/crop.png",crop);
	//imshow("Cropped image",crop);
	//waitKey(0);
	return 0;
}
