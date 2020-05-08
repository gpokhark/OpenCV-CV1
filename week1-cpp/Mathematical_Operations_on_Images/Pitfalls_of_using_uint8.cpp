// Include libraries
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	uint8_t data[] = {100,110,120,130};
	Mat a(2,2,CV_8UC1,data);

	cout << a << endl;

	cout << a + 130 << endl;

	uint8_t scalar = 130;
	cout << a - scalar << endl;

	Mat addition;
	add(a,Scalar(130),addition);
	cout << addition << endl;

	int dataInt[] = {100,110,120,130};
	Mat b(2,2,CV_32SC1,dataInt);
	b = b + 130;
	cout << b << endl;

	b.convertTo(b,CV_8UC1);

	cout << b << endl;

	Mat a_float32;
	a.convertTo(a_float32,CV_32F,1.0/255.0,0);
	a_float32 = a_float32 + 130.0/255.0;
	cout << a_float32 << endl;

	Mat c;
	a_float32.convertTo(c,CV_32F,255.0,0.0);
	cout << c << endl;
	// Clipped output
	Mat b_uint8;
	c.convertTo(b_uint8,CV_8UC1);
	cout << b_uint8 << endl;

	return 0;
}
