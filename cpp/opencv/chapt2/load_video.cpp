#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: load_video.x video_to_display\n");
		return -1;
	}

	namedWindow("Example 3", WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(String(argv[1]));

	Mat frame;
	for(;;)
	{
		cap >> frame;
		if(frame.empty())
			break;
		imshow("Example 3", frame);

		if(waitKey(33) >= 0)
			break;
	}

	return 0;
}