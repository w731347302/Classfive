#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Scalar skin_l = Scalar(0, 30, 60);
Scalar skin_h = Scalar(20, 150, 255);

int main()
{
	VideoCapture cap;
	cap.open(0);

	while (1)
	{
		Mat frame;
		cap.read(frame);
		/*			//Á·Ï°1~4
		Mat miblur;
		medianBlur(frame, miblur, 3);
		Mat gblur;
		GaussianBlur(frame, gblur, Size(3, 3), 1);
		Mat bblur;
		blur(frame, bblur, Size(3, 3));
		Mat sob_x, sob_y;
		Sobel(frame, sob_x, CV_16SC1, 1, 0, 3);
		Sobel(frame, sob_y, CV_16SC1, 0, 1, 3);
		Mat abs_sob_x, abs_sob_y;
		convertScaleAbs(sob_x, abs_sob_x);
		convertScaleAbs(sob_y, abs_sob_y);

		imshow("mblur", miblur);
		imshow("gblur", gblur);
		imshow("blur", bblur);
		imshow("sob_x", abs_sob_x);
		imshow("sob_y", abs_sob_y);
		*/

		Mat hsv_img, mask, res;
		cvtColor(frame, hsv_img, COLOR_BGR2HSV);
		inRange(hsv_img, skin_l, skin_h, mask);
		//bitwise_and(frame, frame, dst, mask);

		Mat m_blur;
		medianBlur(frame, m_blur, 5);
		blur(m_blur, m_blur, Size(3, 3));
		frame.copyTo(res);
		m_blur.copyTo(res, mask);
		
		imshow("frame", frame);
		imshow("mask", mask);
		imshow("res", res);



		waitKey(15);
	}
	return 0;
}