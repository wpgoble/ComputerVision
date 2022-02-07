#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0);

	if(!cap.isOpened())
	{
		// if this is not successful, then we do not have a
		// working video camera stream
		cout << "ERROR: Cannot open the webcam.\n";
		return -1;
	}

	const char* ctrl = "Control";
	namedWindow(ctrl, WINDOW_AUTOSIZE);

	int lowHue = 170;
	int highHue = 179;
	int lowSat = 150;
	int highSat = 255;
	int lowVal = 60;
	int highVal = 255;

	// Create Trackbars in control window
	createTrackbar("Low Hue", ctrl, &lowHue, 179);	//hue between 0 - 179
	createTrackbar("High Hue", ctrl, &highHue, 179);

	createTrackbar("Low Sat", ctrl, &lowSat, 255);	// saturation 0 - 255
	createTrackbar("High sat", ctrl, &highSat, 255);

	createTrackbar("Low Val", ctrl, &lowVal, 255);	// value 0 - 255
	createTrackbar("High Val", ctrl, &highVal, 255);

	int lastX = -1;
	int lastY = -1;

	Mat temp;
	cap.read(temp);

	Mat imgLines = Mat::zeros(temp.size(), CV_8UC3);

	while(true)
	{
		Mat original;
		bool bSuccess = cap.read(original);		// read a new frame from video
		if (!bSuccess)
		{
			cout << "ERROR: Cannot read new frame from webcam!\n";
			break;
		}

		Mat imgHSV;
		cvtColor(original, imgHSV, COLOR_BGR2HSV);

		Mat thresholded;
		inRange(imgHSV, Scalar(lowHue, lowSat, lowVal),
					Scalar(highHue, highSat, highVal), thresholded);

		erode(  thresholded, thresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );
		dilate( thresholded, thresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );
		dilate( thresholded, thresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );
		erode(  thresholded, thresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );

		Moments oMoments = moments(thresholded);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		if(dArea > 10000)
		{
			int posX = dM10 / dArea;
			int posY = dM01 / dArea;

			if(lastX >= 0 && lastY >= 0 && posX >= 0 && posY >= 0)
			{
				line(imgLines, Point(posX, posY), Point(lastX, lastY), Scalar(0, 0, 255), 2);
			}

			lastX = posX;
			lastY = posY;
		}

		flip(thresholded, thresholded, 1);
		imshow("Thresholded Image", thresholded);
		original = original + imgLines;
		flip(original, original, 1);
		imshow("Original", original);

		if ( waitKey(30) == 27)
		{
			cout << "ESC key is pressed by used.\n";
			break;
		}
	}

	return 0;
}

