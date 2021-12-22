#include <opencv2/opencv.hpp>

void example2_5(const cv::Mat& image)
{
	cv::namedWindow("Example 2.5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example 2.5-out", cv::WINDOW_AUTOSIZE);

	cv::imshow("Example 2.5-in", image);
	cv::waitKey(0);
	cv::destroyWindow("Example 2.5-in");
	
	cv::Mat out;

	// Here is where we smooth out the image
	cv::GaussianBlur(image, out, cv::Size(5,5), 3, 3);
	cv::GaussianBlur(  out, out, cv::Size(5,5), 3, 3);

	cv::imshow("Example 2.5-out", out);
	cv::waitKey(0);
	cv::destroyWindow("Example 2.5-out");
}

int main(int argc, char** argv)
{
	cv::Mat img = cv::imread(argv[1], -1);

	example2_5(img);

	return EXIT_SUCCESS;
}
