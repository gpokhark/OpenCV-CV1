// Include libraries
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}


int main(void){
    // Read image
    Mat image = imread(DATA_PATH+"images/boy.jpg");
	Mat contrastHigh = imread("../results/highContrast.png");

	int brightnessOffset = 50;

	// Add the offset for increasing brightness
	Mat brightHigh = image;
	Mat brightHighChannels[3];
	split(brightHigh, brightHighChannels);

	for (int i=0; i < 3; i++){
	    add(brightHighChannels[i],brightnessOffset,brightHighChannels[i]);
	}

	merge(brightHighChannels,3,brightHigh);
	imwrite("../results/highBrightness.png",brightHigh);

	//imshow("High Brightness", brightHigh);
	//waitKey(0);
	
	double min, max;
	cout << "Original Image Datatype : " << type2str(image.type()) << endl;
	cout << "Contrast Image Datatype : " << type2str(contrastHigh.type()) << endl;
	cout << "Brightness Image Datatype : " << type2str(brightHigh.type()) << endl;

	minMaxLoc(image, &min, &max);
	cout << "Original Image Highest Pixel Intensity : " << max << endl;
	minMaxLoc(contrastHigh, &min, &max);
	cout << "Contrast Image Highest Pixel Intensity : " << max << endl;
	minMaxLoc(brightHigh, &min, &max);
	cout << "Brightness Image Highest Pixel Intensity : " << max << endl;


	return 0;
}
