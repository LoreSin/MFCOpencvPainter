﻿
// MFCOpencvPainterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCOpencvPainter.h"
#include "MFCOpencvPainterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCOpencvPainterDlg 대화 상자



CMFCOpencvPainterDlg::CMFCOpencvPainterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCOPENCVPAINTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCOpencvPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAT_VIEW, m_pic);
	DDX_Control(pDX, IDC_STATIC_POINT, m_point_coord);
	DDX_Control(pDX, IDC_LINE_COLOR, m_color1);
}

BEGIN_MESSAGE_MAP(CMFCOpencvPainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCOpencvPainterDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_IMAGE_OPEN, &CMFCOpencvPainterDlg::OnBnClickedImageOpen)
	ON_BN_CLICKED(IDC_NEW_PAGE, &CMFCOpencvPainterDlg::OnBnClickedNewPage)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CMFCOpencvPainterDlg 메시지 처리기

BOOL CMFCOpencvPainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	OnBnClickedNewPage();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCOpencvPainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCOpencvPainterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCOpencvPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCOpencvPainterDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}



void CMFCOpencvPainterDlg::OnBnClickedImageOpen()
{
	// 이미지 불러오는 다이얼로그
	CString szFilter = L"Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_READONLY, szFilter, AfxGetMainWnd());
	if (dlg.DoModal() == IDOK)
	{
		CString path = dlg.GetPathName();

		CT2CA pszString(path);

		Mat src = imread(string(pszString), IMREAD_UNCHANGED);
		DisplayImage(src);

	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCOpencvPainterDlg::DisplayImage(cv::Mat& _targetMat)
{
	//pDC = m_pic.GetDC();
	CClientDC dc(GetDlgItem(IDC_MAT_VIEW));

	Mat tempImg;
	resize(_targetMat, tempImg, Size(_targetMat.cols * 1, _targetMat.rows * 1));

	BITMAPINFO* bitmapInfo;

	if (_targetMat.channels() == 1)
		bitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		bitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo->bmiHeader.biPlanes = 1;
	bitmapInfo->bmiHeader.biBitCount = _targetMat.channels() * 8;
	bitmapInfo->bmiHeader.biCompression = BI_RGB;
	bitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	bitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	bitmapInfo->bmiHeader.biWidth = tempImg.cols;
	bitmapInfo->bmiHeader.biHeight = -tempImg.rows;
	bitmapInfo->bmiHeader.biClrImportant = 0;
	bitmapInfo->bmiHeader.biClrUsed = 0;
	bitmapInfo->bmiHeader.biSizeImage = 0;

	if (bitmapInfo->bmiHeader.biBitCount == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			bitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			bitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			bitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			bitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	

	CRect rect;
	GetDlgItem(IDC_MAT_VIEW)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, tempImg.cols, tempImg.rows, tempImg.data, bitmapInfo, DIB_RGB_COLORS, SRCCOPY);


	tempImg.release();
}


void CMFCOpencvPainterDlg::OnBnClickedNewPage()
{
	m_mat_img = Mat(600,600,CV_8UC3, Scalar(0,0,0));
	pen_color = Scalar(255, 255, 255);
	DisplayImage(m_mat_img);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CMFCOpencvPainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	line(m_mat_img, Point(200, 200), Point(point.x, point.y), pen_color);
	DisplayImage(m_mat_img);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialogEx::OnMouseMove(nFlags, point);
	print_out(point.x, point.y);

	CRect rect;
	m_pic.GetClientRect(&rect);
	m_pic.MoveWindow(0, 0, 400, 400);
	//print_out(rect.bottom, rect.right);
}


int CMFCOpencvPainterDlg::print_out(int x, int y)
{
	CString q;
	q.Format(L"%d %d", x, y);
	SetDlgItemTextW(IDC_STATIC_POINT, q);

	COLORREF color(m_color1.GetColor());
	int red, green, blue;
	red = color & 0x0000ff;
	green= (color & 0x00ff00) >> 8;
	blue = (color & 0xff0000) >> 16;
	pen_color = Scalar(blue, green, red);
	q.Format(L"%d %d %d", red, green, blue);
	SetDlgItemTextW(IDC_STATIC_POINT, q);


	// TODO: 여기에 구현 코드 추가.
	return 0;
}
