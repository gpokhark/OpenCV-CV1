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

	// Create an empty image of same size as the original
	Mat mask1 = Mat::zeros(image.size(), image.type());
	imwrite("../results/mask1.png",mask1);
	//imshow("Mask 1",mask1);
	//waitKey(0);

	mask1(Range(50,200),Range(170,320)).setTo(255);
	imwrite("../results/mask1Revised.png",mask1);
	//imshow("Mask 1 Revised",mask1);
	//waitKey(0);

	Mat mask2;
	inRange(image, Scalar(0,0,150), Scalar(100,100,255), mask2);
	imwrite("../results/mask2.png",mask2);
	//imshow("Mask 2",mask2);
	//waitKey(0);

	return 0;
}
