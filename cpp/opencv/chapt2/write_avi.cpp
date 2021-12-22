#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("Original Video", WINDOW_AUTOSIZE);
	namedWindow("Log Polar", WINDOW_AUTOSIZE);

	VideoCapture capture(argv[1]);

	double fps = capture.get(CAP_PROP_FPS);
	Size size(
		(int)capture.get(CAP_PROP_FRAME_WIDTH),
		(int)capture.get(CAP_PROP_FRAME_HEIGHT)
	);

	VideoWriter writer;
	writer.open(argv[2], VideoWriter::fourcc('M', 'J', 'P', 'G'),
		fps, size);

	Mat log_polar_frame, bgr_frame;

	for(;;)
	{
		capture >> bgr_frame;
		if(bgr_frame.empty())
			break;

		imshow("Original Video", bgr_frame);

		logPolar(
			bgr_frame,
			log_polar_frame,
			Point2f(
				bgr_frame.cols/2,
				bgr_frame.rows/2
			),
			40,
			WARP_FILL_OUTLIERS
		);

		imshow("Log Polar", log_polar_frame);
		writer << log_polar_frame;

		char c = waitKey(10);
		if(c == 27)
			break;
	}

	capture.release();

	return 0;
}