#include <opencv2/opencv.hpp>

using namespace cv;

void example2_5(const Mat&);

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: smooth.x image");
		return -1;
	}

	Mat img = imread(argv[1], -1);

	if(img.empty())
		return -1;

	example2_5(img);
}

void example2_5(const Mat& image)
{
	namedWindow("Example 2.5 in", WINDOW_AUTOSIZE);
	namedWindow("Example 2.5 out", WINDOW_AUTOSIZE);
	namedWindow("Example 2.5 blur", WINDOW_AUTOSIZE);
	namedWindow("Example 2.5 median", WINDOW_AUTOSIZE);

	imshow("Example 2.5 in", image);

	Mat output;
	Mat blur_out;
	Mat median_out;
	// Here is where we smooth out the image
	// We could use Gaussian Blur, blur, medianBlur, or bilateralFilter
	GaussianBlur(image, output, Size(5, 5), 3, 3);
	// GaussianBlur(output, output, Size(5, 5), 3, 3);

	blur(image, blur_out, Size(5, 5));

	// for medianBlur, the ksize needs to be an odd number greater
	// than 1
	medianBlur(image, median_out, 7);

	imshow("Example 2.5 out", output);
	imshow("Example 2.5 blur", blur_out);
	imshow("Example 2.5 median", median_out);

	waitKey(0);
}