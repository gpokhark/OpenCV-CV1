#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main(void){
	// Load the Face Image
	string faceImagePath = DATA_PATH + "/images/musk.jpg";

	Mat faceImage = imread(faceImagePath);
	// Load the Sunglass image with Alpha channel
	// (http://pluspng.com/sunglass-png-1104.html)
	string glassimagePath = DATA_PATH + "/images/sunglass.png";
	
	// Read the image
	Mat glassPNG = imread(glassimagePath,-1);
	// Resize the image to fit over the eye region
	resize(glassPNG,glassPNG, Size(300,100));

	cout << "Image Dimension = " << glassPNG.size() << endl;
	cout << "Number of channels = " << glassPNG.channels();

	// Separate the Color and alpha channels
	Mat glassRGBAChannels[4];
	Mat glassRGBChannels[3];
	split(glassPNG, glassRGBAChannels);

	for (int i = 0; i < 3; i++){
	    // Copy R,G,B channel from RGBA to RGB
	    glassRGBChannels[i] = glassRGBAChannels[i];
	}

	Mat glassBGR, glassMask1;
	// Prepare BGR Image
	merge(glassRGBChannels,3,glassBGR);
	// Alpha channel is the 4th channel in RGBA Image
	glassMask1 = glassRGBAChannels[3];

	imwrite("../results/sunglassRGB.png",glassBGR);
	imwrite("../results/sunglassAlpha.png",glassMask1);

	return 0;
}
