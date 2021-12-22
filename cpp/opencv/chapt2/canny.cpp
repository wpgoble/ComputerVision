#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat rgb, gry, cny;

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Gray", WINDOW_AUTOSIZE);
	namedWindow("Canny", WINDOW_AUTOSIZE);

	rgb = imread(argv[1]);

	imshow("Original", rgb);

	cvtColor(rgb, gry, COLOR_BGR2GRAY);

	imshow("Gray", gry);

	Canny(gry, cny, 10, 100, 3, true);
	imshow("Canny", cny);

	waitKey(0);

	return 0;
}