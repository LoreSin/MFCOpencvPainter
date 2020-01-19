
// MFCOpencvPainterDlg.h: 헤더 파일
//

#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// CMFCOpencvPainterDlg 대화 상자
class CMFCOpencvPainterDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCOpencvPainterDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCOPENCVPAINTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedImageOpen();
	CStatic m_pic;
	Mat m_mat_img;
	void DisplayImage(cv::Mat& _targetMat);
	afx_msg void OnBnClickedNewPage();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int print_out(int x, int y);
	CStatic m_point_coord;
	CMFCColorButton m_color1;
	cv::Scalar pen_color;
};

