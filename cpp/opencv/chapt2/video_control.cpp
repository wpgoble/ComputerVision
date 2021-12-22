#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;
VideoCapture g_cap;

void onTrackbarSlide(int, void*);

int main(int argc, char** argv)
{
	namedWindow("Example 2.4", WINDOW_AUTOSIZE);
	g_cap.open(String(argv[1]));

	int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmp_width = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmp_height = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);

	cout << "Video has " << frames << " frames of dimensions(" 
		<< tmp_width << ", " << tmp_height << ").\n";

	createTrackbar("Position", "Example 2.4", &g_slider_position, 
		frames, onTrackbarSlide);

	Mat frame;
	
	for(;;)
	{
		if(g_run != 0)
		{
			g_cap >> frame;
			if(frame.empty())
				break;

			int current_pos = (int) g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;

			setTrackbarPos("Position", "Example 2.4", current_pos);
			imshow("Example 2.4", frame);
			
			g_run -= 1;	
		}

		char c = (char) waitKey(10);
		if(c == 's')
		{
			g_run = 1;
			cout << "Single step, run = " << g_run << endl;
		}
		if(c == 'r')
		{
			g_run = -1;
			cout << "Run mode, run = " << g_run << endl;
		}
		if(c == 27)
		{
			break;
		}
	}

	return 0;
}

void onTrackbarSlide(int pos, void*)
{
	g_cap.set(CAP_PROP_POS_FRAMES, pos);

	if(!g_dontset)
		g_run = 1;

	g_dontset = 0;
}