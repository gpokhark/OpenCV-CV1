#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(void)
{
        string imagePath = DATA_PATH + "/images/number_zero.jpg";

        // Read image in Grayscale format
        Mat testImage = imread(imagePath,0);

	cout << (int)testImage.at<uchar>(0,0);

	testImage.at<uchar>(0,0)=200;

	cout << testImage;
	
	return 0;
}
