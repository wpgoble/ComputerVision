#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	namedWindow("Camera Input", WINDOW_AUTOSIZE);
	VideoCapture cap;

	// if no argument is given, then use the first 
	// camera, else use the video the user supplies
	if(argc == 1)
		cap.open(0);
	else
		cap.open(argv[1]);

	if(!cap.isOpened())
	{
		cerr << "Couldn't open capture.\n";
		return -1;
	}

	Mat frame;
	for(;;)
	{
		cap >> frame;
		if(frame.empty())
			break;
		imshow("Camera Input", frame);

		if(waitKey(33) >= 0)
			break;
	}

	return 0;
}