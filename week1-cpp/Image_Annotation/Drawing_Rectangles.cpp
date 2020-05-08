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

	// Draw a rectangle (thickness is a positive integer)
	Mat imageRectangle = image.clone();
	rectangle(imageRectangle, Point(170, 50), Point(300, 200),
          Scalar(255, 0, 255), 5, LINE_8);

	imwrite("../results/rectangle.jpg",imageRectangle);

	//imshow("Draw rectangle on image",imageRectangle);
	//waitKey(0);
	return 0;
}
