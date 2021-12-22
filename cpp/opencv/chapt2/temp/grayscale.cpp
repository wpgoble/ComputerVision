#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat img_rgb, img_gray, img_cny;
	int x = 16, y = 32;	

	namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = imread(argv[1]);
	
	cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);
	imshow("Example Gray", img_gray);
	
	Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	cout << "At (x, y) = (" << x << ", " << y << 

	waitKey(0);
	destroyWindow("Example Gray");

	Canny(img_gray, img_cny, 10, 100, 3, true);
	imshow("Example Canny", img_cny);

	waitKey(0);
	destroyWindow("Example Canny");

	return EXIT_SUCCESS;
}
