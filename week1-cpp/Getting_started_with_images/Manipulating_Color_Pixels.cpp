#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main(void)
{
	string imagePath = DATA_PATH + "/images/number_zero.jpg";

	Mat testImage = imread(imagePath,1);

	cout << testImage.at<Vec3b>(0,0);

	testImage.at<Vec3b>(0,0) = Vec3b(0,255,255);
	imwrite("../results/zero1.png",testImage);
	//imshow("Zero 1",testImage);

	testImage.at<Vec3b>(1,1) = Vec3b(255,255,0);
	imwrite("../results/zero2.png",testImage);
	//imshow("Zero 2",testImage);

	testImage.at<Vec3b>(2,2) = Vec3b(255,0,255);
	imwrite("../results/zero3.png",testImage);
	//imshow("Zero 3",testImage);

	//waitKey(0);
	return 0;
}
