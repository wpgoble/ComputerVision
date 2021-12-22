#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat img, gry, pyr, pyr2, cny;

	img = imread(argv[1]);

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Pyramid", WINDOW_AUTOSIZE);
	namedWindow("Pyramid2", WINDOW_AUTOSIZE);
	namedWindow("First", WINDOW_AUTOSIZE);
	namedWindow("Second", WINDOW_AUTOSIZE);

	int x = 16, y = 32;

	Vec3b intensity = img.at<Vec3b>(y, x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	imshow("Original", img);

	cvtColor(img, gry, COLOR_BGR2GRAY);
	pyrDown(gry, pyr);
	pyrDown(pyr, pyr2);
	Canny(pyr2, cny, 10, 100, 3, true);

	imshow("Pyramid", pyr);
	imshow("Pyramid2", pyr2);

	printf("At (%d, %d): (blue, green, red) = (%d, %d, %d)\n", 
		x, y, (unsigned int)blue, (unsigned int)green, 
		(unsigned int)red);

	printf("Gray pixel there is: %d\n", 
		(unsigned int)gry.at<uchar>(y, x));

	x /= 4;
	y /= 4;

	printf("Pyramid2 pixel there is: %d\n",
		(unsigned int)pyr2.at<uchar>(y, x));

	imshow("First", cny);

	cny.at<uchar>(x, y) = 128;

	imshow("Second", cny);

	waitKey(0);

	return 0;
}