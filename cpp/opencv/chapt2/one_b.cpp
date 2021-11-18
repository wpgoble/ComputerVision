#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);
	if(img.empty())
		return -1;
	namedWindow("Example 1b", cv::WINDOW_AUTOSIZE);
	imshow("Example 1b", img);
	waitKey(0);
	destroyWindow("Example 1b");

	return 1;
}

