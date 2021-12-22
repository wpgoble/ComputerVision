#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat img1, img2;

	namedWindow("Example 1", cv::WINDOW_AUTOSIZE);
	namedWindow("Example 2", cv::WINDOW_AUTOSIZE);

	img1 = imread(argv[1]);
	imshow("Example 1", img1);

	// now lets trim this in half
	pyrDown(img1, img2);
	imshow("Example 2", img2);

	waitKey(0);

	return EXIT_SUCCESS;
}
