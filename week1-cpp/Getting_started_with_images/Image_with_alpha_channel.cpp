#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main(void){
	string // Path of the PNG image to be loaded
	imagePath = DATA_PATH + "/images/panther.png";

	// Read the image
	// Note that we are passing flag = -1 while reading the image ( it will read the image as is)
	Mat imgPNG = imread(imagePath,-1);
	cout << "image size = " << imgPNG.size() << endl;
	cout << "number of channels = " << imgPNG.channels() << endl;

	Mat imgBGR;
	Mat imgPNGChannels[4];
	split(imgPNG,imgPNGChannels);

	merge(imgPNGChannels,3,imgBGR);

	Mat imgMask = imgPNGChannels[3];

	//imshow("Color Channels",imgBGR);
	//imshow("Alpha Channel",imgMask);
	//waitKey(0);
	imwrite("../results/colorChannels.png",imgBGR);
	imwrite("../results/alphaChannel.png",imgMask);

	return 0;
}
