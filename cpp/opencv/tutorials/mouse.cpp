#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);

int main(int argc, char** argv)
{
	//if(argc < 1)
	//{
	//	cout << "./mouse.exe path/to/file.png\n";
	//	return -1;
	//}
	// Read image from file
	Mat img = imread("../chapt2/src/profile1.png");

	// if fail to read the image
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}

	// Create a window
	namedWindow("Test Window", -1);

	// set the callback function for any mouse event
	setMouseCallback("Test Window", CallBackFunc, NULL);

	// Show the image
	imshow("Test Window", img);

	// wait until user presses some key
	waitKey(0);

	return 0;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if(event == EVENT_LBUTTONDOWN)
		cout << "Left button of the mouse is clicked - position(" << x << ", " << y << ")\n";
	else if(event == EVENT_RBUTTONDOWN)
		cout << "Right button of the mouse is clicked - position(" << x << ", " << y << ")\n";
	else if(event == EVENT_MBUTTONDOWN)
		cout << "Middle button of the mouse is click - position(" << x << ", " << y << ")\n";
	else if(event == EVENT_MOUSEMOVE)
		cout << "Mouse move over the window - position (" << x << ", " << y << ")\n";
}
