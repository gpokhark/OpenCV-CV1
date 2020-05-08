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
	// First let us create a copy of the original image 
	Mat copiedImage = image.clone();

	Mat copyRoi = image(Range(40,200),Range(180,320));

	// Find height and width of the ROI
	int roiHeight = copyRoi.size().height;
	int roiWidth = copyRoi.size().width;
	
	// Copy to left of Face
	copyRoi.copyTo(copiedImage(Range(40,40+roiHeight),Range(10,10+roiWidth)));
	// Copy to right of Face
	copyRoi.copyTo(copiedImage(Range(40,40+roiHeight),Range(330,330+roiWidth)));

	imwrite("../results/copiedRegions.png",copiedImage);

	//imshow("Output Image",copiedImage);
	//waitKey(0);

	return 0;
}
