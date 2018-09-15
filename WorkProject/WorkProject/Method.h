#pragma once
#include <vector>
#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
ref class Method
{
public:
	Method();
	~Method();
	//顯示的圖
	Bitmap ^ image1; 
	Imaging::BitmapData ^ image1_Data;

	void OpenImage(void);
	void RGBtoGray(void);
	void Reduction(void);
	void ZoomImage(float scale);
	void ZoomOutImage(float scale);
	void TwoZoomImage(double scale);
	void TwoZoomOutImage(double scale);
	void SaltPepperNoise(int number);
	void Gaussian_Noise(double mean, double std);
	void Mean_Filter(void);
	void Median_Blur(void);
	void Gaussian_Blur(void);
	void Histogram_Shrink(int minvalue, int maxvalue);
	void Histogram_Stretch(int minvalue, int maxvalue);
	void Histogram_Equalization(void);
	void Erode(void);
	void Dilate(void);
	void Sobel(void);
	void Haar_Wavelet(int pass);
	void Rgb_Hsi_convert(void);
	void Cale_Histogram(int * color,int channel);
	void Hough_Transform(void);
	void Prewitt(void);
	void Laplacian(void);
private:

	//宣告圖像區域(設定為欲讀取、欲修正的圖像區域)
	Rectangle rect;

	//宣告指標
	Byte * p;
	Byte * q;
	Byte * r;
	IntPtr image_Ptr;
	IntPtr temp_Ptr;

	//保存原圖
	Bitmap ^ original_Image;
	Imaging::BitmapData ^ original_ImageData;

	//圖片處理暫存空間
	Bitmap ^ temp_Image; 
	Imaging::BitmapData ^ temp_Image_Data;

	//搬移圖片
	void copytoImage1(IntPtr aPtr, IntPtr bPtr);

protected:

};

