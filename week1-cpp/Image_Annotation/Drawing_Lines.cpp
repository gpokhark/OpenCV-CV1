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
	// Draw a line
	Mat imageLine = image.clone();

	// The line starts from (322,179) and ends at (400,183)
	// The color of the line is RED (Recall that OpenCV uses BGR format)
	// Thickness of line is 5px
	// Linetype is LINE_AA

	line(imageLine, Point(200, 80), Point(280, 80), Scalar(0, 255, 0), 3, LINE_AA);
	
	imwrite("../results/line.jpg",imageLine);
	
	//imshow("Image line",imageLine);
	//waitKey(0);
	
	return 0;
}
