#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

// Globals
int ANGLE = 180;
int SCALE = 50;
int BORDERMODE = 0;
Mat ORIGINAL;
int IMG_CENTER_X = 0;
int IMG_CENTER_Y = 0;
const char* ROTATED = "Rotated Image";

void CallbackForTrackBar(int, void*);

int main(int argc, char** argv)
{
	// check if usage is done properly
	if (argc < 1)
	{
		std::cout << "Usage: ./rotate_advanced.exe path/to/img.png\n";
		return -1;
	}

	ORIGINAL = imread(argv[1], 1);
	IMG_CENTER_X = ORIGINAL.rows / 2;
	IMG_CENTER_Y = ORIGINAL.cols / 2;

	// lets see this image...
	const char* original_win = "Original Image.";
	namedWindow(original_win, WINDOW_AUTOSIZE);
	imshow(original_win, ORIGINAL);

	// Create the "Rotated Image" window and 3 trackbars
	namedWindow(ROTATED, WINDOW_AUTOSIZE);
	createTrackbar("Angle", ROTATED, &ANGLE, 260, CallbackForTrackBar);
	createTrackbar("Scale", ROTATED, &SCALE, 100, CallbackForTrackBar);
	createTrackbar("Border Mode", ROTATED, &BORDERMODE, 5, CallbackForTrackBar);

	int dummy = 0;

	CallbackForTrackBar(dummy, &dummy);

	waitKey(0);

	return 0;
}

void CallbackForTrackBar(int, void*)
{
	Mat matRotation = getRotationMatrix2D(Point(IMG_CENTER_X, IMG_CENTER_Y), (ANGLE - 180), SCALE/50.0);

	// Now actually rotate the image
	Mat imgRotate;
	warpAffine(ORIGINAL, imgRotate, matRotation, ORIGINAL.size(), INTER_LINEAR, BORDERMODE, Scalar());

	imshow(ROTATED, imgRotate);
 }

