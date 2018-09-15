#define _USE_MATH_DEFINES
#include "Method.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

using namespace std;

Method::Method()
{

}

Method::~Method()
{
	
}

void Method::OpenImage(void)
{
	//new一個新的openFileDialog1開啟檔案
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	//設定Filter，用以限定使用者開啟的檔案
	openFileDialog1->Filter = "點陣圖 (*.bmp)| *.bmp| All files (*.*)| *.*";
	//預設檔案名稱為空值
	openFileDialog1->FileName = "";
	//設定跳出選擇視窗的標題名稱
	openFileDialog1->Title = "載入影像";
	//設定Filter選擇模式(依照Filter數，如本例選擇1表示起始出現的為點陣圖，選擇2表示All filts)
	openFileDialog1->FilterIndex = 2;


	//跳出檔案選擇視窗(ShowDialog)，並且如果使用者點選檔案，並且檔案名稱超過0個字元，則判斷是為True，進入處理程序
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName->Length > 0)
	{
		//將選取的檔案讀取並且存至Image1
		image1 = safe_cast<Bitmap^>(Image::FromFile(openFileDialog1->FileName));
		//設定圖像大咬
		rect = Rectangle(0, 0, image1->Width, image1->Height);
		//取得圖像格式
		System::Drawing::Imaging::PixelFormat format = image1->PixelFormat;
		//複製原圖儲存
		original_Image = image1->Clone(rect, format);
	}
}

void Method::copytoImage1(IntPtr aPtr, IntPtr bPtr)
{
	p = (Byte*)((Void*)image_Ptr); //設定指標
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	// 瀏覽所有像素點複製到image1
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			for (int z = 0; z < 3; z++)
			{
				int temp = q[z];
				p[z] = q[z];
			}
			p += 3;
			q += 3;
		}
	}
}

void Method::Reduction(void)
{
	//取得圖像格式
	System::Drawing::Imaging::PixelFormat format = original_Image->PixelFormat;
	//複製原圖儲存
	image1 = original_Image->Clone(rect, format);
}

void Method::RGBtoGray(void)
{	
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標
	
	////原圖空間
	image1_Data= image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標
	

	//瀏覽所有像素點，將像素除三轉灰階
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{	
			int pixel = (p[0] + p[1] + p[2]) / 3;

			q[0] = pixel;
			q[1] = pixel;
			q[2] = pixel;

			q += 3;
			p += 3;		
		}
	}
	
	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
	
}

void Method::ZoomImage(float scale)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			//將影像寬度及高度放大scale倍  +0.5 取整數
			int xx = x / scale + 0.5;
			int yy = y / scale + 0.5;

			//算出目前指標與目標像素的差
			int a = (xx - x) + ((yy - y)*image1->Width);

			for (int z = 0; z < 2; z++)
			{
				//指向目標像素
				r = p + a * 3;

				//取出目標像素放入目前像素
				q[0] = r[0];
				q[1] = r[1];
				q[2] = r[2];
			}
			p += 3;
			q += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::ZoomOutImage(float scale)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			//將圖像放大2倍 +0.5取整數
			int xx = x / scale + 0.5;
			int yy = y / scale + 0.5;

			//算出目前指標與目標位址的差
			int a = (xx - x) + ((yy - y)*image1->Width);

			//指向目標位址
			r = q + a * 3;

			//將目前像素放入目標位址
			r[0] = p[0];
			r[1] = p[1];
			r[2] = p[2];
	
			p += 3;
			q += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::TwoZoomImage(double scale)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			//縮放比例
			double dstx = ((double)x) / scale;
			double dsty = ((double)y) / scale;

			//取得四點座標
			int x1 = (int)dstx;
			int y1 = (int)dsty;
			int x2 = x1 + 1;
			int y2 = y1 + 1;

			double u = dstx - x1;
			double v = dsty - y1;

			double s1 = (1.0 - u)*(1.0 - v);
			double s2 = u * (1.0 - v);
			double s3 = (1.0 - u)*v;
			double s4 = u * v;

			//左上點像素比例
			int a = (x - x1) + ((y - y1)*image1->Width);

			r = p - a * 3;

			int m, n, o = 0;
			m += r[0] * s1;
			n += r[1] * s1;
			o += r[2] * s1;

			//右上點像素比例
			a = (x - x2) + ((y - y1)*image1->Width);

			r = p - a * 3;
			m += r[0] * s2;
			n += r[1] * s2;
			o += r[2] * s2;

			//左下點像素比例
			a = (x - x1) + ((y - y2)*image1->Width);

			r = p - a * 3;
			m += r[0] * s3;
			n += r[1] * s3;
			o += r[2] * s3;

			//右下點像素比例
			a = (x - x2) + ((y - y2)*image1->Width);

			r = p - a * 3;
			m += r[0] * s4;
			n += r[1] * s4;
			o += r[2] * s4;

			q[0] = m;
			q[1] = n;
			q[2] = o;

			m = 0;
			n = 0;
			o = 0;

			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::TwoZoomOutImage(double scale)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

								  ////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

								   //瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			//縮放比例
			double dstx = ((double)x) / scale;
			double dsty = ((double)y) / scale;

			//取得四點座標
			int x1 = (int)dstx;
			int y1 = (int)dsty;
			int x2 = x1 + 1;
			int y2 = y1 + 1;

			double u = dstx - x1;
			double v = dsty - y1;

			double s1 = (1.0 - u)*(1.0 - v);
			double s2 = u * (1.0 - v);
			double s3 = (1.0 - u)*v;
			double s4 = u * v;

			//左上點像素比例
			int a = (x - x1) + ((y - y1)*image1->Width);

			r = q - a * 3;

			int m, n, o = 0;
			m += p[0] * s1;
			n += p[1] * s1;
			o += p[2] * s1;

			//右上點像素比例
			a = (x - x2) + ((y - y1)*image1->Width);

			r = q - a * 3;
			m += p[0] * s2;
			n += p[1] * s2;
			o += p[2] * s2;

			//左下點像素比例
			a = (x - x1) + ((y - y2)*image1->Width);

			r = q - a * 3;
			m += p[0] * s3;
			n += p[1] * s3;
			o += p[2] * s3;

			//右下點像素比例
			a = (x - x2) + ((y - y2)*image1->Width);

			r = q - a * 3;
			m += p[0] * s4;
			n += p[1] * s4;
			o += p[2] * s4;

			r[0] = m;
			r[1] = n;
			r[2] = o;

			m = 0;
			n = 0;
			o = 0;

			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::SaltPepperNoise(int number)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	double mean = 0;//期望值
	double std = 1;//標準差
	double u, v;//均勻分布數值
	double X;//常態分佈數值

	long int total = 0;
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			u = rand() / (double)RAND_MAX;//RAND_MAX=32767
			v = rand() / (double)RAND_MAX;

			X = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v) * std + mean;//M_PI=3.14159

			if (X > 2 || X < -2)
			{
				if (X > 2)
				{
					q[0] = 255;
					q[1] = 255;
					q[2] = 255;
					total++;
				}
				else if (X < -2)
				{
					q[0] = 0;
					q[1] = 0;
					q[2] = 0;
					total++;
				}
			}
			else
			{
				//拷貝原圖像素
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}

			q += 3;
			p += 3;
		}
	}

	double len, Percentage;
	len = image1->Height * image1->Width;
	Percentage = total / len *100;
	cout << "Noise_total:" << total << " " << "Pixel_total: " << len << "  Percentage: " << Percentage << endl;

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);
	
	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
	
}

void Method::Gaussian_Noise(double mean, double std)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	int temp;
	double u, v;//uniform distribution
	double m = 0;//normal distribution

	//宣告一個亂數產生器
	Random^ Rand = gcnew Random();
	const double max = 32767;

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			u = Rand->Next(0, max) / max; //RAND_MAX=32767
			v = Rand->Next(0, max) / max;
			m = (sqrt(-2 * log(u)) * cos(2 * M_PI * v) * std) + mean;//M_PI=3.14159
															
			for (int i = 0; i < 3; i++)
			{
				temp = p[i] + (int)m;
				if (temp > 255)
					temp = 255;
				if (temp < 0)
					temp = 0;
				q[i] = temp;
			}

			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Mean_Filter(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			int sum[3] = {0};
			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						sum[0] += r[0];
						sum[1] += r[1];
						sum[2] += r[2];
					}
				}

				for (int k = 0; k < 3; k++)
				{
					sum[k] = sum[k] / 9;
					q[k] = (Byte)sum[k];
				}
			}
			else
			{
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Median_Blur(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//宣告陣列存放3X3矩陣R,G,B數值
	int Array[3][9] = {0};
	int temp[3];
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						Array[0][Masksize] = r[0];
						Array[1][Masksize] = r[1];
						Array[2][Masksize] = r[2];
						Masksize++;
					}
				}

				int min[3] = { 0 };
				for (int m = 0; m < 3; m++)
				{
					for (int n = 0; n < 5; ++n)
					{
						min[m] = n;
						for (int o = n+1; o < 9; ++o)
						{
							if (Array[m][o] < Array[m][min[m]])
								min[m] = o;
						}
						temp[m] = Array[m][n];
						Array[m][n] = Array[m][min[m]];
						Array[m][min[m]] = temp[m];

						q[m] = (Byte)Array[m][4];
					}
				}
			}
			else
			{
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Gaussian_Blur(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//遮罩
	int gaussian[9] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	int sum[3];

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						sum[0] += r[0] * gaussian[Masksize];
						sum[1] += r[1] * gaussian[Masksize];
						sum[2] += r[2] * gaussian[Masksize];
						Masksize++;
					}
				}

				for (int k = 0; k < 3; k++)
				{
					sum[k] = sum[k] / 16;
					if (sum[k] > 255)
						sum[k] = 255;
					else if (sum[k] < 0)
						sum[k] = 0;
				}
				q[0] = sum[0];
				q[1] = sum[1];
				q[2] = sum[2];
			}
			else
			{
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Histogram_Shrink(int minvalue, int maxvalue)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//找出像素最大與最小值
	double max = 0;
	double min = 255;

	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			if (p[0] > max)
				max = p[0];
			if (p[0] < min)
				min = p[0];
			p += 3;
		}
	}

	//直方圖縮減公式
	p = (Byte*)((Void*)image_Ptr);

	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			int pixel = (p[0] * (maxvalue - minvalue) / (max - min)) + minvalue;

			pixel > 255 ? (pixel = 255) : (pixel < 0) ? (pixel = 0) : (pixel = pixel);
			/*
			if (pixel > 255)
				pixel = 255;
			if (pixel < 0)
				pixel = 0;
				*/
			q[0] = pixel;
			q[1] = pixel;
			q[2] = pixel;
			p += 3;
			q += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Histogram_Stretch(int minvalue, int maxvalue)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	double Max = 0;
	double Min = 255;

	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			if (p[0] > Max)
				Max = p[0];
			if (p[0] < Min)
				Min = p[0];
			p += 3;
		}
	}

	//直方圖擴展公式
	p = (Byte*)((Void*)image_Ptr);
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			double pixel = ((p[0] - Min) / (Max - Min)) * (maxvalue - minvalue);

			if (pixel > 255)
				pixel = 255;
			if (pixel < 0)
				pixel = 0;

			q[0] = (Byte)pixel;
			q[1] = (Byte)pixel;
			q[2] = (Byte)pixel;
			p += 3;
			q += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Histogram_Equalization(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	int Graycount[256] = { 0 };
	double fpGraycount[256] = { 0 };
	double totaltemp[256] = { 0 };
	double eqtotaltemp[256] = { 0 };

	//統計直方圖
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			int value = p[0];
			Graycount[value]++;
			p += 3;
		}
	}

	for (int i = 0; i < 256; i++)
	{
		//計算像素在整張圖的分佈密度
		fpGraycount[i] = (float)Graycount[i] / (float)(image1->Height * (float)image1->Width);

		//陣列初始化
		totaltemp[i] = 0;

		//計算累積直方圖分佈				
		totaltemp[i] = totaltemp[i - 1] + fpGraycount[i];

		//累積直方圖分佈取整數 並將機率映射到灰階像素0~255
		eqtotaltemp[i] = (int)(255 * totaltemp[i] + 0.5);
	}

	//p指向image1原點
	p = (Byte*)((Void*)image_Ptr);

	//直方圖均衡化
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			int value = p[0];
			if (value > 255) value = 255;
			if (value < 0) value = 0;
			q[0] = (unsigned char)eqtotaltemp[value];
			q[1] = (unsigned char)eqtotaltemp[value];
			q[2] = (unsigned char)eqtotaltemp[value];
			p += 3;
			q += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Erode(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	int Array[9];
	int ArraySize = 9;
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						Array[Masksize] = r[0] + r[1] + r[2];
						Masksize++;
					}
				}

				//掃描3X3矩陣
				for (int k = 0; k < ArraySize; k++)
				{
					//若3X3矩陣中有黑點 則將目前像素設為黑點,若無則設為白點
					if (Array[k] == 0)
					{
						q[0] = 0;
						q[1] = 0;
						q[2] = 0;
						break;
					}
					else if (k == ArraySize - 1)
					{
						q[0] = 255;
						q[1] = 255;
						q[2] = 255;
					}
				}
			}
			else
			{
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Dilate(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	int Array[9];
	int ArraySize = 9;
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						Array[Masksize] = r[0] + r[1] + r[2];
						Masksize++;
					}
				}

				//掃描5X5矩陣
				for (int k = 0; k < ArraySize; k++)
				{
					//若5X5矩陣當中有白點 則目前像素設為白點,若無則設為黑點
					if (Array[k] != 0)
					{
						q[0] = 255;
						q[1] = 255;
						q[2] = 255;
						break;
					}
					else if (k == ArraySize - 1)
					{
						q[0] = 0;
						q[1] = 0;
						q[2] = 0;
					}
				}
			}
			else
			{
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[2];
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Sobel(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//垂直與水平遮罩
	int Gx[9] = { 1, 0, -1,
		2, 0, -2,
		1, 0, -1 };
	int Gy[9] = { -1, -2, -1,
		0, 0, 0,
		1, 2, 1 };

	int m, n, G;

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			m = 0, n = 0;
			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						m += ((r[0] + r[1] + r[2])/3) * Gx[Masksize];
						n += ((r[0] + r[1] + r[2])/3) * Gy[Masksize];
						Masksize++;
					}
				}

				G = abs(m) + abs(n);
				//G = sqrt(pow(m,2)+ pow(n,2));
				q[0] = G;
				q[1] = G;
				q[2] = G;
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Haar_Wavelet(int pass)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

	//存放目前像素及下一個像素
	int nowp, nextp, pp;
	int passWidth = image1->Width;
	int passHeight = image1->Height;
	float temp;

	for (int i = 0; i < pass; i++)
	{
		//指標指向圖像起始位置
		temp_Ptr = temp_Image_Data->Scan0;  
		q = (Byte*)((Void*)temp_Ptr); 
		image_Ptr = image1_Data->Scan0; 
		p = (Byte*)((Void*)image_Ptr); 

		//設定圖片像素寬度
		passWidth = passWidth / 2;

		//指向水平高頻區域
		r = q + passWidth * 3;

		//瀏覽所有像素點做水平小波轉換
		for (int y = 0; y < passHeight; y++) {
			for (int x = 0; x < passWidth; x++) {
				//取得目前像素
				nowp = p[0];

				//移到下一個像素
				p += 3;

				//取得下一個像素
				nextp = p[0];

				//計算低頻像素
				temp = nowp + nextp;
				pp = temp / 2 + 0.5;

				//放置低頻像素
				q[0] = pp;
				q[1] = pp;
				q[2] = pp;

				//計算高頻像素
				pp = (nowp - nextp) / 2;

				if (pp < 0)
					pp = 0;

				pp += 128;

				if (pp > 255)
					pp = 255;

				//放置高頻向素
				r[0] = pp;
				r[1] = pp;
				r[2] = pp;

				//往下一列
				q += 3;
				p += 3;
				r += 3;
			}

			//往下一行起始點
			q += (image1->Width * 3) - (passWidth * 3);
			r += (image1->Width * 3) - (passWidth * 3);

			if (i >= 1)
			{
				p += (image1->Width * 3) - (passWidth * 2 * 3);
			}
		}

		//指標指向圖像起始位置
		temp_Ptr = image1_Data->Scan0;  
		q = (Byte*)((Void*)temp_Ptr); 
		image_Ptr = temp_Image_Data->Scan0; 
		p = (Byte*)((Void*)image_Ptr); 

		//設定圖片像素高度
		passHeight = passHeight / 2;

		//指向垂直小波高頻區域
		r = q + (passHeight *image1->Width) * 3;

		//瀏覽所有像素點做垂直小波轉換
		for (int y = 0; y < passWidth * 2; y++) {
			for (int x = 0; x < passHeight; x++) {

				//取得目前像素
				nowp = p[0];

				//往下一行
				p += image1->Width * 3;

				//取得下一個像素
				nextp = p[0];

				//計算低頻像素
				temp = nowp + nextp;
				pp = temp / 2 + 0.5;

				//放置低頻像素
				q[0] = pp;
				q[1] = pp;
				q[2] = pp;

				//計算高頻像素
				pp = (nowp - nextp) / 2;
				if (pp < 0)
					pp = 0;

				pp += 128;

				if (pp > 255)
					pp = 255;

				//放置高頻像素
				r[0] = pp;
				r[1] = pp;
				r[2] = pp;

				//往下一列
				q += image1->Width * 3;
				p += image1->Width * 3;
				r += image1->Width * 3;
			}
			//往上至起始點
			q = q - (passHeight * image1->Width) * 3 + 3;
			r = r - (passHeight * image1->Width) * 3 + 3;
			p = p - ((passHeight * 2) * image1->Width) * 3 + 3;
		}

		//指標指向圖像起始位置
		temp_Ptr = image1_Data->Scan0;  
		image_Ptr = temp_Image_Data->Scan0; 

		//將處理完的圖複製到temp
		copytoImage1(temp_Ptr, image_Ptr);
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Rgb_Hsi_convert(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	//宣告動態陣列
	double  *Ha = new double[image1->Height * image1->Width];
	double  *Sa = new double[image1->Height * image1->Width];
	double  *Ia = new double[image1->Height * image1->Width];

	long int count = 0;
	double  H, S, I;

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			double rr = p[2];
			double gg = p[1];
			double bb = p[0];


			float min, max; /* minimum and maximum RGB values */
			float angle; /* temp variable used to compute Hue */

			if ((rr <= gg) && (rr <= bb))
				min = rr;
			else if ((gg <= rr) && (gg <= bb))
				min = gg;
			else
				min = bb;

			/* compute intensity */
			I = (rr + gg + bb) / 3.0;

			/* compute hue and saturation */
			if ((rr == gg) && (gg == bb)) /* gray-scale */
			{
				S = 0.0;
				H = 0.0;
			}
			else
			{
				S = 1.0 - (3.0 / (rr + gg + bb)) * min;
				angle = (rr - 0.5 * gg - 0.5 * bb) /
					sqrt((rr - gg) * (rr - gg) + (rr - bb) * (gg - bb));
				H = acos(angle);
				H *= 57.29577951; /* convert to degrees */
			}
			if (bb>gg)
				H = 360.0 - H;

			
			Ha[count] = H;
			Sa[count] = S;
			Ia[count] = I;

			count++;
			p += 3;
		}
	}

	//直方圖均恆
	int Graycount[256] = { 0 };
	double fpGraycount[256] = { 0 };
	double totaltemp[256] = { 0 };
	double eqtotaltemp[256] = { 0 };


	count = 0;
	//統計直方圖
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			int value = Ia[count];
			Graycount[value]++;
			count++;
		}
	}

	for (int i = 0; i < 256; i++)
	{
		//計算像素在整張圖的分佈密度
		fpGraycount[i] = (float)Graycount[i] / (float)(image1->Height * (float)image1->Width);

		//陣列初始化
		totaltemp[i] = 0;

		//計算累積直方圖分佈				
		totaltemp[i] = totaltemp[i - 1] + fpGraycount[i];

		//累積直方圖分佈取整數 並將機率映射到灰階像素0~255
		eqtotaltemp[i] = (int)(255 * totaltemp[i] + 0.5);
	}

	count = 0;
	//直方圖均衡化
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			int value = Ia[count];
			if (value > 255) value = 255;
			if (value < 0) value = 0;
			Ia[count] = (double)eqtotaltemp[value];
			count++;
		}
	}

	////暫存圖空間
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

	double r, b, g;
	count = 0;
	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {

			H = Ha[count];
			S = Sa[count];
			I = Ia[count];

			float angle1, angle2, scale, temp, denom; /* temp variables */

			if (I == 0.0) /* BLACK */
			{
				r = 0.0;
				g = 0.0;
				b = 0.0;
				//return;
			}
			if (S == 0.0) /* gray-scale H is undefined*/
			{
				r = I;
				g = I;
				b = I;
				//return;
			}
			if (H<0.0)
				H += 360.0;

			scale = 3.0 * I;

			if (H <= 120.0)
			{
				angle1 = H * 0.017453293; /* convert to radians - mul by pi/180 */
				angle2 = (60.0 - H)*0.017453293;

				b = (1.0 - S) / 3.0;
				r = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				g = 1.0 - r - b;
				b *= scale;
				r *= scale;
				g *= scale;
			}
			else if ((H>120.0) && (H <= 240.0))
			{
				H -= 120.0;
				angle1 = H * 0.017453293; /* convert to radians - mul by pi/180 */
				angle2 = (60.0 - H)*0.017453293;

				r = (1.0 - S) / 3.0;
				g = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				b = 1.0 - r - g;
				r *= scale;
				g *= scale;
				b *= scale;
			}
			else
			{
				H -= 240.0;
				angle1 = H * 0.017453293; /* convert to radians - mul by pi/180 */
				angle2 = (60.0 - H)*0.017453293;

				g = (1.0 - S) / 3.0;
				b = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				r = 1.0 - g - b;
				r *= scale;
				g *= scale;
				b *= scale;
			}

			if (b > 255) b = 255;
			if (g > 255) g = 255;
			if (r > 255) r = 255;
			if (b < 0) b = 0;
			if (g < 0) g = 0;
			if (r < 0) r = 0;
			q[0] = (Byte)b;
			q[1] = (Byte)g;
			q[2] = (Byte)r;
			count++;
			q += 3;
		}
	}
	
	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
	
	delete []Ha;
	delete []Sa;
	delete []Ia;
}

void Method::Cale_Histogram(int * color,int channel)
{
	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標


	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			int value = p[channel];	
			color[value]++;
			p += 3;
		}
	}
	image1->UnlockBits(image1_Data);
}

void Method::Hough_Transform(void)
{
	double START, END;
	START = clock();

	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

	////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

								   //儲存Sin Cos角度
	float sintab[180], costab[180];

	float theta;
	//因為cos算出來的是弧度 所以先將弧度轉換為角度
	for (int angle = 0; angle < 180; angle++)
	{
		theta = angle * M_PI / 180.0;
		sintab[angle] = sin(theta);
		costab[angle] = cos(theta);
	}

	float rmax = sqrt(image1->Height * image1->Height + image1->Width * image1->Width);
	//rmax *= 2;
	//宣告動態一維陣列
	float **hough_Array;
	hough_Array = new float*[(int)rmax * 2];
	cout << rmax << endl;

	//宣告動態二維陣列
	for (int k = 0; k < rmax * 2; k++)
	{
		hough_Array[k] = new float[180];
	}

	//清空陣列
	for (int k = 0; k < rmax * 2; k++)
	{
		for (int n = 0; n < 180; n++)
		{
			hough_Array[k][n] = 0;
		}
	}

	float r;
	int nr, angle;
	//將座標轉換成霍夫空間
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			//如果點是白色(邊緣)
			if (p[0] > 191)
			{
				//角度0~180
				for (int angle = 0; angle < 180; angle++)
				{
					r = y * sintab[angle] + x * costab[angle];
					nr = (int)(r + rmax);
					hough_Array[nr][angle]++;
				}
			}
			p += 3;
		}
	}

	//計算有多少個點重疊數大於設定值
	int point_Number = 0;
	int hough_value = 108;
	for (int k = 0; k < rmax * 2; k++)
	{
		for (int n = 0; n < 180; n++)
		{
			if (hough_Array[k][n] > hough_value)
			{
				point_Number++;
			}
		}
	}
	cout << point_Number << endl;

	//紀錄重疊數大於設定值的r與angle
	int *r_Array = new int[point_Number];
	int *angle_Array = new int[point_Number];
	int count = 0;
	for (int k = 0; k < rmax * 2; k++)
	{
		for (int n = 0; n < 180; n++)
		{
			if (hough_Array[k][n] > hough_value)
			{
				r_Array[count] = k;
				angle_Array[count] = n;
				count++;
			}
		}
	}

	/////////////////////霍夫空間
	//新增一個空間放置中值濾波影像
	Bitmap^ hough_TransformImage;
	Imaging::BitmapData^ hough_TransformImageData;
	hough_TransformImage = gcnew Bitmap(180, rmax * 2);
	Rectangle hough_Rect;
	hough_Rect = Rectangle(0, 0, 180, rmax * 2);
	hough_TransformImageData = hough_TransformImage->LockBits(hough_Rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

	//指標指向圖像起始位置
	IntPtr ResultPtr;
	Byte * R;
	ResultPtr = hough_TransformImageData->Scan0;
	R = (Byte*)((Void*)ResultPtr);

	//畫出霍夫空間
	for (int k = 0; k < rmax * 2; k++)
	{
		for (int n = 0; n < 180; n++)
		{
			if (hough_Array[k][n] > 0)
			{
				int point = hough_Array[k][n];
				if (point > 255) point = 255;
				if (point < 0) point = 0;
				R[0] = (Byte)point;
				R[1] = (Byte)point;
				R[2] = (Byte)point;
			}
			R += 3;
		}
	}

	//新增一個空間放置中值濾波影像
	Bitmap^ lineImage;
	Imaging::BitmapData^ lineImageData;
	lineImage = gcnew Bitmap(image1->Width, image1->Height);
	lineImageData = lineImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

	//指標指向圖像起始位置
	ResultPtr = lineImageData->Scan0;
	R = (Byte*)((Void*)ResultPtr);

	IntPtr ptr;
	ptr = image1_Data->Scan0;
	p = (Byte*)((Void*)ptr);
	//劃出直線
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			for (int i = 0; i < point_Number; i++)
			{
				if (x == (int)round(((r_Array[i] - rmax) - y * sintab[(int)angle_Array[i]]) / (costab[(int)angle_Array[i]])))
				{
					R[0] = 0;
					R[1] = 0;
					R[2] = 255;
				}
			}
			p += 3;
			R += 3;
		}
	}

	ptr = image1_Data->Scan0;
	p = (Byte*)((Void*)ptr);
	ResultPtr = lineImageData->Scan0;
	R = (Byte*)((Void*)ResultPtr);

	//將紅線覆蓋到原圖
	for (int y = 0; y < image1->Height; y++)
	{
		for (int x = 0; x < image1->Width; x++)
		{
			if (R[2] == 255)
			{
				p[0] = 0;
				p[1] = 0;
				p[2] = 255;
			}
			p += 3;
			R += 3;
		}
	}

	lineImage->UnlockBits(lineImageData);
	hough_TransformImage->UnlockBits(hough_TransformImageData);

	//將處理完的圖複製到image1
//	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
	END = clock();
	cout << endl << "程式執行所花費：" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
}

void Method::Prewitt(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

								  ////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

								   //垂直與水平遮罩
	int Gx[9] = { 1, 1, 1,
		0, 0, 0,
		-1, -1, -1 };
	int Gy[9] = { 1, 0, -1,
		1, 0, -1,
		1, 0, -1 };

	int m, n, G;

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			m = 0, n = 0;
			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						m += ((r[0] + r[1] + r[2]) / 3) * Gx[Masksize];
						n += ((r[0] + r[1] + r[2]) / 3) * Gy[Masksize];
						Masksize++;
					}
				}
				G = abs(m) + abs(n);
				//G = sqrt(pow(m,2) + pow(n,2));

				q[0] = G;
				q[1] = G;
				q[2] = G;
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}

void Method::Laplacian(void)
{
	////暫存圖空間
	temp_Image = gcnew Bitmap(image1->Width, image1->Height); //生成一張長寬跟image一樣的Bitmap
	temp_Image_Data = temp_Image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	temp_Ptr = temp_Image_Data->Scan0;  //將int指標指向Image像素資料的最前面位置
	q = (Byte*)((Void*)temp_Ptr); //設定指標

								  ////原圖空間
	image1_Data = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
	image_Ptr = image1_Data->Scan0; //將int指標指向Image像素資料的最前面位置
	p = (Byte*)((Void*)image_Ptr); //設定指標

								   //垂直與水平遮罩
	int Gx[9] = { 0, 1, 0,
		1, -4, 1,
		0, 1, 0};
	int Gy[9] = { 0, 1, 0,
		1, -4, 1,
		0, 1, 0 };

	int m, n, G;

	//瀏覽所有像素點，取用像素，處理像素區域
	for (int y = 0; y < image1->Height; y++) {
		for (int x = 0; x < image1->Width; x++) {
			m = 0, n = 0;
			if (y > 0 && x > 0 && y < image1->Height-1 && x < image1->Width-1)
			{
				int Masksize = 0;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -3; j <= 3; j += 3)
					{
						r = (Byte*)(Void*)p + i * image1->Width * 3 + j;
						m += ((r[0] + r[1] + r[2]) / 3) * Gx[Masksize];
						n += ((r[0] + r[1] + r[2]) / 3) * Gy[Masksize];
						Masksize++;
					}
				}
				G = abs(m) + abs(n);
				//G = sqrt(pow(m, 2) + pow(n, 2));

				q[0] = G;
				q[1] = G;
				q[2] = G;
			}
			q += 3;
			p += 3;
		}
	}

	//將處理完的圖複製到image1
	copytoImage1(image_Ptr, temp_Ptr);

	//解鎖圖像記憶體空間
	image1->UnlockBits(image1_Data);
	temp_Image->UnlockBits(temp_Image_Data);
}