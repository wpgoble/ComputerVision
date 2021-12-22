#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	// read image from command line
	cv::Mat img = cv::imread(argv[1], -1);

	// if there isn't an image, then program fails
	if(img.empty())
		return -1;

	cv::namedWindow("Example 1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example 1", img);
	cv::waitKey(0);						// this asks the program to stop and wait for a keystroke
										// if 0, then wait indef, if a non-zero number then it 
										// waits that many milliseconds
	cv::destroyWindow("Example 1");

	return 0;
}