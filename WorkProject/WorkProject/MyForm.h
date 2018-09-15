#pragma once
#include "Method.h"
#include <iostream>


namespace WorkProject {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (!test)
			{
				delete test;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  檔案ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  OpenFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ReductionToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  影像縮放ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ZoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  zoomScale;
	private: System::Windows::Forms::ToolStripMenuItem^  ZoomOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  zoomOutScale;
	private: System::Windows::Forms::ToolStripMenuItem^  TwoZoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  twoZoomScale;
	private: System::Windows::Forms::ToolStripMenuItem^  雜訊產生ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Salt_Pepper_NoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Gaussian_NoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  回復原圖ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  濾波器ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Mean_FilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Median_BlurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Gaussian_BlurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  色彩ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RgbtoGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  直方圖ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Histogram_ShrinkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Histogram_StretchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Histogram_EqualizationToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^  影像壓縮ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Haar_WaveletToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  型態學ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ErodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  DilateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  特徵提取ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SobelToolStripMenuItem;
	private: System::Windows::Forms::Label^  image1Size;
	private: System::Windows::Forms::ToolStripMenuItem^  TwoZoomOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  twoZoomOutScale;
	private: System::Windows::Forms::ToolStripTextBox^  passNumber;
	private: System::Windows::Forms::ToolStripMenuItem^  hSIToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartB;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartG;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartR;
	private: System::Windows::Forms::ToolStripMenuItem^  houghTransformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prewittToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  laplacianToolStripMenuItem;











	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea8 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea9 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->回復原圖ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReductionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->色彩ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RgbtoGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hSIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->影像縮放ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ZoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomScale = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->ZoomOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomOutScale = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->TwoZoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->twoZoomScale = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->TwoZoomOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->twoZoomOutScale = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->雜訊產生ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Salt_Pepper_NoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Gaussian_NoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->濾波器ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Mean_FilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Median_BlurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Gaussian_BlurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->直方圖ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Histogram_ShrinkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Histogram_StretchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Histogram_EqualizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->影像壓縮ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Haar_WaveletToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->passNumber = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->特徵提取ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SobelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->houghTransformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prewittToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laplacianToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->型態學ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ErodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DilateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image1Size = (gcnew System::Windows::Forms::Label());
			this->chartB = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartG = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartR = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartR))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(17, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(670, 677);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->檔案ToolStripMenuItem,
					this->色彩ToolStripMenuItem, this->影像縮放ToolStripMenuItem, this->雜訊產生ToolStripMenuItem, this->濾波器ToolStripMenuItem, this->直方圖ToolStripMenuItem,
					this->影像壓縮ToolStripMenuItem, this->特徵提取ToolStripMenuItem, this->型態學ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1136, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->OpenFileToolStripMenuItem,
					this->回復原圖ToolStripMenuItem, this->ReductionToolStripMenuItem
			});
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->檔案ToolStripMenuItem->Text = L"檔案";
			// 
			// OpenFileToolStripMenuItem
			// 
			this->OpenFileToolStripMenuItem->Name = L"OpenFileToolStripMenuItem";
			this->OpenFileToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->OpenFileToolStripMenuItem->Text = L"開啟圖片";
			this->OpenFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenFileToolStripMenuItem_Click);
			// 
			// 回復原圖ToolStripMenuItem
			// 
			this->回復原圖ToolStripMenuItem->Name = L"回復原圖ToolStripMenuItem";
			this->回復原圖ToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->回復原圖ToolStripMenuItem->Text = L"回復原圖";
			this->回復原圖ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::回復原圖ToolStripMenuItem_Click);
			// 
			// ReductionToolStripMenuItem
			// 
			this->ReductionToolStripMenuItem->Name = L"ReductionToolStripMenuItem";
			this->ReductionToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->ReductionToolStripMenuItem->Text = L"另存新檔";
			this->ReductionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SaveAsToolStripMenuItem_Click);
			// 
			// 色彩ToolStripMenuItem
			// 
			this->色彩ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->RgbtoGrayToolStripMenuItem,
					this->hSIToolStripMenuItem
			});
			this->色彩ToolStripMenuItem->Name = L"色彩ToolStripMenuItem";
			this->色彩ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->色彩ToolStripMenuItem->Text = L"色彩";
			// 
			// RgbtoGrayToolStripMenuItem
			// 
			this->RgbtoGrayToolStripMenuItem->Name = L"RgbtoGrayToolStripMenuItem";
			this->RgbtoGrayToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->RgbtoGrayToolStripMenuItem->Text = L"RgbtoGray";
			this->RgbtoGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::RgbtoGrayToolStripMenuItem_Click);
			// 
			// hSIToolStripMenuItem
			// 
			this->hSIToolStripMenuItem->Name = L"hSIToolStripMenuItem";
			this->hSIToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->hSIToolStripMenuItem->Text = L"RgbtoHsi";
			this->hSIToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::hSIToolStripMenuItem_Click);
			// 
			// 影像縮放ToolStripMenuItem
			// 
			this->影像縮放ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ZoomToolStripMenuItem,
					this->ZoomOutToolStripMenuItem, this->TwoZoomToolStripMenuItem, this->TwoZoomOutToolStripMenuItem
			});
			this->影像縮放ToolStripMenuItem->Name = L"影像縮放ToolStripMenuItem";
			this->影像縮放ToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->影像縮放ToolStripMenuItem->Text = L"影像縮放";
			// 
			// ZoomToolStripMenuItem
			// 
			this->ZoomToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->zoomScale });
			this->ZoomToolStripMenuItem->Name = L"ZoomToolStripMenuItem";
			this->ZoomToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ZoomToolStripMenuItem->Text = L"放大";
			this->ZoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ZoomToolStripMenuItem_Click);
			// 
			// zoomScale
			// 
			this->zoomScale->Name = L"zoomScale";
			this->zoomScale->Size = System::Drawing::Size(100, 23);
			this->zoomScale->Text = L"1";
			// 
			// ZoomOutToolStripMenuItem
			// 
			this->ZoomOutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->zoomOutScale });
			this->ZoomOutToolStripMenuItem->Name = L"ZoomOutToolStripMenuItem";
			this->ZoomOutToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ZoomOutToolStripMenuItem->Text = L"縮小";
			this->ZoomOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ZoomOutToolStripMenuItem_Click);
			// 
			// zoomOutScale
			// 
			this->zoomOutScale->Name = L"zoomOutScale";
			this->zoomOutScale->Size = System::Drawing::Size(100, 23);
			this->zoomOutScale->Text = L"1";
			// 
			// TwoZoomToolStripMenuItem
			// 
			this->TwoZoomToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->twoZoomScale });
			this->TwoZoomToolStripMenuItem->Name = L"TwoZoomToolStripMenuItem";
			this->TwoZoomToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->TwoZoomToolStripMenuItem->Text = L"放大(雙線性插值)";
			this->TwoZoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::TwoZoomToolStripMenuItem_Click);
			// 
			// twoZoomScale
			// 
			this->twoZoomScale->Name = L"twoZoomScale";
			this->twoZoomScale->Size = System::Drawing::Size(100, 23);
			this->twoZoomScale->Text = L"1";
			// 
			// TwoZoomOutToolStripMenuItem
			// 
			this->TwoZoomOutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->twoZoomOutScale });
			this->TwoZoomOutToolStripMenuItem->Name = L"TwoZoomOutToolStripMenuItem";
			this->TwoZoomOutToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->TwoZoomOutToolStripMenuItem->Text = L"縮小(雙線性插值)";
			this->TwoZoomOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::TwoZoomOutToolStripMenuItem_Click);
			// 
			// twoZoomOutScale
			// 
			this->twoZoomOutScale->Name = L"twoZoomOutScale";
			this->twoZoomOutScale->Size = System::Drawing::Size(100, 23);
			this->twoZoomOutScale->Text = L"1";
			// 
			// 雜訊產生ToolStripMenuItem
			// 
			this->雜訊產生ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Salt_Pepper_NoiseToolStripMenuItem,
					this->Gaussian_NoiseToolStripMenuItem
			});
			this->雜訊產生ToolStripMenuItem->Name = L"雜訊產生ToolStripMenuItem";
			this->雜訊產生ToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->雜訊產生ToolStripMenuItem->Text = L"雜訊產生";
			// 
			// Salt_Pepper_NoiseToolStripMenuItem
			// 
			this->Salt_Pepper_NoiseToolStripMenuItem->Name = L"Salt_Pepper_NoiseToolStripMenuItem";
			this->Salt_Pepper_NoiseToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->Salt_Pepper_NoiseToolStripMenuItem->Text = L"椒鹽雜訊";
			this->Salt_Pepper_NoiseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Salt_Pepper_NoiseToolStripMenuItem_Click);
			// 
			// Gaussian_NoiseToolStripMenuItem
			// 
			this->Gaussian_NoiseToolStripMenuItem->Name = L"Gaussian_NoiseToolStripMenuItem";
			this->Gaussian_NoiseToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->Gaussian_NoiseToolStripMenuItem->Text = L"高斯雜訊";
			this->Gaussian_NoiseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Gaussian_NoiseToolStripMenuItem_Click);
			// 
			// 濾波器ToolStripMenuItem
			// 
			this->濾波器ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Mean_FilterToolStripMenuItem,
					this->Median_BlurToolStripMenuItem, this->Gaussian_BlurToolStripMenuItem
			});
			this->濾波器ToolStripMenuItem->Name = L"濾波器ToolStripMenuItem";
			this->濾波器ToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->濾波器ToolStripMenuItem->Text = L"濾波器";
			// 
			// Mean_FilterToolStripMenuItem
			// 
			this->Mean_FilterToolStripMenuItem->Name = L"Mean_FilterToolStripMenuItem";
			this->Mean_FilterToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->Mean_FilterToolStripMenuItem->Text = L"均值濾波";
			this->Mean_FilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Mean_FilterToolStripMenuItem_Click);
			// 
			// Median_BlurToolStripMenuItem
			// 
			this->Median_BlurToolStripMenuItem->Name = L"Median_BlurToolStripMenuItem";
			this->Median_BlurToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->Median_BlurToolStripMenuItem->Text = L"中值濾波";
			this->Median_BlurToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Median_BlurToolStripMenuItem_Click);
			// 
			// Gaussian_BlurToolStripMenuItem
			// 
			this->Gaussian_BlurToolStripMenuItem->Name = L"Gaussian_BlurToolStripMenuItem";
			this->Gaussian_BlurToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->Gaussian_BlurToolStripMenuItem->Text = L"高斯模糊";
			this->Gaussian_BlurToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Gaussian_BlurToolStripMenuItem_Click);
			// 
			// 直方圖ToolStripMenuItem
			// 
			this->直方圖ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Histogram_ShrinkToolStripMenuItem,
					this->Histogram_StretchToolStripMenuItem, this->Histogram_EqualizationToolStripMenuItem
			});
			this->直方圖ToolStripMenuItem->Name = L"直方圖ToolStripMenuItem";
			this->直方圖ToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->直方圖ToolStripMenuItem->Text = L"直方圖";
			// 
			// Histogram_ShrinkToolStripMenuItem
			// 
			this->Histogram_ShrinkToolStripMenuItem->Name = L"Histogram_ShrinkToolStripMenuItem";
			this->Histogram_ShrinkToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->Histogram_ShrinkToolStripMenuItem->Text = L"直方圖縮減";
			this->Histogram_ShrinkToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Histogram_ShrinkToolStripMenuItem_Click);
			// 
			// Histogram_StretchToolStripMenuItem
			// 
			this->Histogram_StretchToolStripMenuItem->Name = L"Histogram_StretchToolStripMenuItem";
			this->Histogram_StretchToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->Histogram_StretchToolStripMenuItem->Text = L"直方圖擴展";
			this->Histogram_StretchToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Histogram_StretchToolStripMenuItem_Click);
			// 
			// Histogram_EqualizationToolStripMenuItem
			// 
			this->Histogram_EqualizationToolStripMenuItem->Name = L"Histogram_EqualizationToolStripMenuItem";
			this->Histogram_EqualizationToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->Histogram_EqualizationToolStripMenuItem->Text = L"直方圖均等";
			this->Histogram_EqualizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Histogram_EqualizationToolStripMenuItem_Click);
			// 
			// 影像壓縮ToolStripMenuItem
			// 
			this->影像壓縮ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Haar_WaveletToolStripMenuItem });
			this->影像壓縮ToolStripMenuItem->Name = L"影像壓縮ToolStripMenuItem";
			this->影像壓縮ToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->影像壓縮ToolStripMenuItem->Text = L"影像壓縮";
			// 
			// Haar_WaveletToolStripMenuItem
			// 
			this->Haar_WaveletToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->passNumber });
			this->Haar_WaveletToolStripMenuItem->Name = L"Haar_WaveletToolStripMenuItem";
			this->Haar_WaveletToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->Haar_WaveletToolStripMenuItem->Text = L"Haar小波轉換";
			this->Haar_WaveletToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Haar_WaveletToolStripMenuItem_Click);
			// 
			// passNumber
			// 
			this->passNumber->Name = L"passNumber";
			this->passNumber->Size = System::Drawing::Size(100, 23);
			this->passNumber->Text = L"1";
			// 
			// 特徵提取ToolStripMenuItem
			// 
			this->特徵提取ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->SobelToolStripMenuItem,
					this->houghTransformToolStripMenuItem, this->prewittToolStripMenuItem, this->laplacianToolStripMenuItem
			});
			this->特徵提取ToolStripMenuItem->Name = L"特徵提取ToolStripMenuItem";
			this->特徵提取ToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->特徵提取ToolStripMenuItem->Text = L"特徵提取";
			// 
			// SobelToolStripMenuItem
			// 
			this->SobelToolStripMenuItem->Name = L"SobelToolStripMenuItem";
			this->SobelToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->SobelToolStripMenuItem->Text = L"Sobel邊緣偵測";
			this->SobelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SobelToolStripMenuItem_Click);
			// 
			// houghTransformToolStripMenuItem
			// 
			this->houghTransformToolStripMenuItem->Name = L"houghTransformToolStripMenuItem";
			this->houghTransformToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->houghTransformToolStripMenuItem->Text = L"Hough_Transform";
			this->houghTransformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::houghTransformToolStripMenuItem_Click);
			// 
			// prewittToolStripMenuItem
			// 
			this->prewittToolStripMenuItem->Name = L"prewittToolStripMenuItem";
			this->prewittToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->prewittToolStripMenuItem->Text = L"Prewitt邊緣偵測";
			this->prewittToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::prewittToolStripMenuItem_Click);
			// 
			// laplacianToolStripMenuItem
			// 
			this->laplacianToolStripMenuItem->Name = L"laplacianToolStripMenuItem";
			this->laplacianToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->laplacianToolStripMenuItem->Text = L"Laplacian邊緣偵測";
			this->laplacianToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::laplacianToolStripMenuItem_Click);
			// 
			// 型態學ToolStripMenuItem
			// 
			this->型態學ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ErodeToolStripMenuItem,
					this->DilateToolStripMenuItem
			});
			this->型態學ToolStripMenuItem->Name = L"型態學ToolStripMenuItem";
			this->型態學ToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->型態學ToolStripMenuItem->Text = L"型態學";
			// 
			// ErodeToolStripMenuItem
			// 
			this->ErodeToolStripMenuItem->Name = L"ErodeToolStripMenuItem";
			this->ErodeToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->ErodeToolStripMenuItem->Text = L"侵蝕";
			this->ErodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ErodeToolStripMenuItem_Click);
			// 
			// DilateToolStripMenuItem
			// 
			this->DilateToolStripMenuItem->Name = L"DilateToolStripMenuItem";
			this->DilateToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->DilateToolStripMenuItem->Text = L"膨脹";
			this->DilateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::DilateToolStripMenuItem_Click);
			// 
			// image1Size
			// 
			this->image1Size->AutoSize = true;
			this->image1Size->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->image1Size->Location = System::Drawing::Point(566, 724);
			this->image1Size->Name = L"image1Size";
			this->image1Size->Size = System::Drawing::Size(0, 16);
			this->image1Size->TabIndex = 6;
			// 
			// chartB
			// 
			this->chartB->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			chartArea7->AxisX->LineWidth = 0;
			chartArea7->AxisX->MajorGrid->LineWidth = 0;
			chartArea7->AxisY->LineWidth = 0;
			chartArea7->AxisY->MajorGrid->LineWidth = 0;
			chartArea7->Name = L"ChartArea1";
			this->chartB->ChartAreas->Add(chartArea7);
			this->chartB->Cursor = System::Windows::Forms::Cursors::Default;
			this->chartB->Location = System::Drawing::Point(718, 35);
			this->chartB->Name = L"chartB";
			this->chartB->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series7->Name = L"Series1";
			this->chartB->Series->Add(series7);
			this->chartB->Size = System::Drawing::Size(376, 210);
			this->chartB->TabIndex = 7;
			this->chartB->Text = L"chart1";
			title7->Name = L"Title1";
			title7->Text = L"B";
			this->chartB->Titles->Add(title7);
			// 
			// chartG
			// 
			chartArea8->AxisX->LineWidth = 0;
			chartArea8->AxisX->MajorGrid->LineWidth = 0;
			chartArea8->AxisY->LineWidth = 0;
			chartArea8->AxisY->MajorGrid->LineWidth = 0;
			chartArea8->Name = L"ChartArea1";
			this->chartG->ChartAreas->Add(chartArea8);
			this->chartG->Location = System::Drawing::Point(718, 268);
			this->chartG->Name = L"chartG";
			this->chartG->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series8->Name = L"Series1";
			this->chartG->Series->Add(series8);
			this->chartG->Size = System::Drawing::Size(376, 210);
			this->chartG->TabIndex = 8;
			this->chartG->Text = L"chart2";
			title8->Name = L"Title1";
			title8->Text = L"G";
			this->chartG->Titles->Add(title8);
			// 
			// chartR
			// 
			chartArea9->AxisX->LineWidth = 0;
			chartArea9->AxisX->MajorGrid->LineWidth = 0;
			chartArea9->AxisY->LineWidth = 0;
			chartArea9->AxisY->MajorGrid->LineWidth = 0;
			chartArea9->Name = L"ChartArea1";
			this->chartR->ChartAreas->Add(chartArea9);
			this->chartR->Location = System::Drawing::Point(718, 502);
			this->chartR->Name = L"chartR";
			this->chartR->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series9->Name = L"Series1";
			this->chartR->Series->Add(series9);
			this->chartR->Size = System::Drawing::Size(376, 210);
			this->chartR->TabIndex = 9;
			this->chartR->Text = L"chart3";
			title9->Name = L"Title1";
			title9->Text = L"R";
			this->chartR->Titles->Add(title9);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1136, 749);
			this->Controls->Add(this->chartR);
			this->Controls->Add(this->chartG);
			this->Controls->Add(this->chartB);
			this->Controls->Add(this->image1Size);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartR))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		Method ^ test;
#pragma endregion


	private: System::Void OpenFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		test = gcnew Method;
		try
		{
			test->OpenImage();
			pictureBox1->Image = test->image1;
			image1Size->Text = test->image1->Height + " x " + test->image1->Width + " pixel";
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void SaveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->Filter = "點陣圖 (*.bmp)| *.bmp| All files (*.*)| *.*";
			saveFileDialog1->FileName = "";
			saveFileDialog1->Title = "儲存影像";
			saveFileDialog1->FilterIndex = 1;

			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && saveFileDialog1->FileName != "")
			{
				//儲存image1
				test->image1->Save(saveFileDialog1->FileName);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}

	private: System::Void ZoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->ZoomImage(Convert::ToSingle(zoomScale->Text));
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void ZoomOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->ZoomOutImage(Convert::ToSingle(zoomOutScale->Text));
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void TwoZoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->TwoZoomImage(Convert::ToSingle(twoZoomScale->Text));
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void TwoZoomOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->TwoZoomOutImage(Convert::ToSingle(twoZoomOutScale->Text));
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Salt_Pepper_NoiseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->SaltPepperNoise(0);
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Gaussian_NoiseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Gaussian_Noise(0,25);
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void 回復原圖ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Reduction();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Mean_FilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Mean_Filter();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Median_BlurToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Median_Blur();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Gaussian_BlurToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Gaussian_Blur();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void RgbtoGrayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->RGBtoGray();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Histogram_ShrinkToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Histogram_Shrink(100,150);
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Histogram_StretchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Histogram_Stretch(0, 255);
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Histogram_EqualizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Histogram_Equalization();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void Haar_WaveletToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Haar_Wavelet(Convert::ToSingle(passNumber->Text));
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void ErodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Erode();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void DilateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Dilate();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void SobelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Sobel();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void hSIToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Rgb_Hsi_convert();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	private: void Draw_Histogram(void)
	{
		chartB->Series[0]->Points->Clear();
		chartG->Series[0]->Points->Clear();
		chartR->Series[0]->Points->Clear();
		int B[256] = { 0 };
		int G[256] = { 0 };
		int R[256] = { 0 };
		test->Cale_Histogram(B, 0);
		test->Cale_Histogram(G, 1);
		test->Cale_Histogram(R, 2);
		for (int i = 0; i < 256; i++)
		{
			chartB->Series[0]->Points->AddXY(i, B[i]);
			chartG->Series[0]->Points->AddXY(i, G[i]);
			chartR->Series[0]->Points->AddXY(i, R[i]);
		}
	}

	private: System::Void houghTransformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Hough_Transform();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void prewittToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Prewitt();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void laplacianToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			test->Laplacian();
			pictureBox1->Image = test->image1;
			Draw_Histogram();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
};
}
