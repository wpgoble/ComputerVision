#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);

	if(img.empty())
		return -1;

	namedWindow("Example 1 std", WINDOW_AUTOSIZE);
	imshow("Example 1 std", img);
	waitKey(0);
	destroyWindow("Example 1 std");

	return 0;
}