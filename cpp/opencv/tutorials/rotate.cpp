#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv)
{
	if(argc < 1)
	{
		std::cout << "Usage: ./rotate path/to/img.png\n";
		return -1;
	}

	// load image
	Mat imgOriginal = imread(argv[1], 1);

	// show the original image
	const char* pzOriginalImage = "Original";
	namedWindow(pzOriginalImage, WINDOW_AUTOSIZE);

	imshow(pzOriginalImage, imgOriginal);

	const char* pzRotatedImage = "Rotated Image";
	namedWindow(pzRotatedImage, WINDOW_AUTOSIZE);

	int iAngle = 180;
	createTrackbar("Angle", pzRotatedImage, &iAngle, 360);

	int iImageHeight = imgOriginal.rows/2;
	int iImageWidth = imgOriginal.cols/2;

	while(true)
	{
		Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHeight), (iAngle - 180), 1 );

		Mat imgRotated;
		warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());

		imshow(pzRotatedImage, imgRotated);

		int iRet = waitKey(30);
		if (iRet == 27)
			break;
	}

	return 0;
}

