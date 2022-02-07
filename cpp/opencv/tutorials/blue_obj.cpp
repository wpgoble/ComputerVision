#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0);		// grabs the video from the webcam

	if(!cap.isOpened())
	{
		cout << "Cannot open webcame.\n";
		return -1;
	}

	const char* ctrl = "Control";

	namedWindow(ctrl, WINDOW_AUTOSIZE);

	// Hue
	int iLowH = 0;
	int iHighH = 179;

	// Saturation
	int iLowS = 0;
	int iHighS = 255;

	// Value
	int iLowV = 0;
	int iHighV = 240;

	createTrackbar("LowH", ctrl, &iLowH, 179);
	createTrackbar("HighH", ctrl, &iHighH, 179);

	createTrackbar("LowS", ctrl, &iLowS, 255);
	createTrackbar("HighS", ctrl, &iHighS, 255);

	createTrackbar("LowV", ctrl, &iLowV, 255);
	createTrackbar("HighV", ctrl, &iHighV, 255);

	while (true)
	{
		Mat original;
		bool bSuccess = cap.read(original);

		if(!bSuccess)
		{
			cout << "Cannot read a frame from the video stream.\n";
			break;
		}

		Mat imgHSV;
		cvtColor(original, imgHSV, COLOR_BGR2HLS);		// converts from BGR to HSV
		Mat imgThreshold;
		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThreshold);

		// morpholocail opening
		// removes small objects from the foreground
		erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );
		dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );

		// morphological closing
		// fill in the small holes in the foreground
		dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );
		erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)) );

		flip(imgThreshold, imgThreshold, 1);
		flip(original, original, 1);
		imshow("Thresholded Image", imgThreshold);
		imshow("Original", original);

		if(waitKey(30) == 27)
		{
			cout << "Esc. key is pressed by user.\n";
			break;
		}
	}

	return 0;
}
