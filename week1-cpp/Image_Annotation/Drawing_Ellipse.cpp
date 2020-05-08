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

	// Draw an ellipse
	// Note: Ellipse Centers and Axis lengths must be integers
	Mat imageEllipse = image.clone();

	ellipse(imageEllipse, Point(250, 125), Point(100, 50), 0, 0, 360,
        Scalar(255, 0, 0), 3, LINE_AA);

	ellipse(imageEllipse, Point(250, 125), Point(100, 50), 90, 0, 360,
        Scalar(0, 0, 255), 3, LINE_AA);

	imwrite("../results/ellipse.jpg",imageEllipse);
	//imshow("Draw ellipse on image", imageEllipse);
	//waitKey(0);
	
	// Draw an ellipse
	// Note: Ellipse Centers and Axis lengths must be integers
	imageEllipse = image.clone();

	// Incomplete/Open ellipse
	ellipse(imageEllipse, Point(250, 125), Point(100, 50), 0, 180, 360,
        Scalar(255, 0, 0), 3, LINE_AA);

	// Filled ellipse
	ellipse(imageEllipse, Point(250, 125), Point(100, 50), 0, 0, 180,
        Scalar(0, 0, 255), -2, LINE_AA);

	imwrite("../results/ellipseFilled.jpg",imageEllipse);

	//imshow("Draw filled ellipse",imageEllipse);
	//waitKey(0);
	return 0;
}
