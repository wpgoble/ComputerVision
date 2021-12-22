#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		cout << "Usage: load_img_std.x img_to_display\n";
		return -1;
	}

	Mat img = imread(argv[1], -1);

	if(img.empty())
		return -1;

	namedWindow("Example 1 std", WINDOW_AUTOSIZE);
	imshow("Example 1 std", img);
	waitKey(0);
	destroyWindow("Example 1 std");

	return 0;
}