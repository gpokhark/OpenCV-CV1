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
	// Draw a circle
	Mat imageCircle = image.clone();

	circle(imageCircle, Point(250, 125), 100, Scalar(0, 0, 255), 5, LINE_AA);

	imwrite("../results/circle.jpg",imageCircle);
	//imshow("Draw circle on image",imageCircle);
	//waitKey(0);
	
	// Draw a filled circle
	Mat imageFilledCircle = image.clone();

	circle(imageFilledCircle, Point(250, 125), 100, Scalar(0, 0, 255), -1, LINE_AA);

	imwrite("../results/filledCircle.jpg",imageFilledCircle);
	//imshow("Filled circle",imageFilledCircle);
	//waitKey(0);
	return 0;
}

