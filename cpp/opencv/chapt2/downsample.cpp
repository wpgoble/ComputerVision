#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{

	Mat img1, img2;

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("pyrDown", WINDOW_AUTOSIZE);

	img1 = imread(argv[1]);

	imshow("Original", img1);

	pyrDown(img1, img2);
	imshow("pyrDown", img2);

	waitKey(0);

	return 0;
}