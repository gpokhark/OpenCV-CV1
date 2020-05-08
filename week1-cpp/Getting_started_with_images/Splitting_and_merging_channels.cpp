#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main(void)
{
        string imagePath = DATA_PATH + "/images/musk.jpg";
	// Read the image
        Mat img = imread(imagePath);
	// Show the channels
	Mat imgChannels[3];
	split(img, imgChannels);

	// Write the channels
	imwrite("../results/imgBlue.png",imgChannels[0]);
	imwrite("../results/imgGreen.png",imgChannels[1]);
	imwrite("../results/imgRed.png",imgChannels[2]);

	//imshow("Blue Channel",imgChannels[0]);
	//imshow("Green Channel",imgChannels[1]);
	//imshow("Red Channel",imgChannels[2]);
	//waitKey(0);

	return 0;
}
