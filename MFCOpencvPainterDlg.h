
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
	CStatic m_point_coord;
	CButton m_btn_line;

	CPoint *m_pos_old;
	CPoint *m_pos_new;
	CMFCColorButton m_color1;
	CMFCColorButton m_color_fill;
	void ResetPos();
	int print_out(int x, int y);
	afx_msg void OnBnClickedNewPage();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	Mat m_mat_img;
	cv::Scalar pen_color;
	cv::Scalar bg_color;
	string m_shape_mode;
	void DisplayImage(cv::Mat& _targetMat);
	void DrawShapeLine(CPoint point1, CPoint point2);
	void DrawShapeRect(CPoint point1, CPoint point2);
	void DrawShapeCircle(CPoint point1, CPoint point2);
	afx_msg void OnBnClickedBtnLine();
	afx_msg void OnBnClickedBtnRect();
	afx_msg void OnBnClickedBtnCircle();
	Scalar convertColor(COLORREF color);
	afx_msg void OnBnClickedBtnDilate();
	afx_msg void OnBnClickedBtnErode();
	afx_msg void OnBnClickedBtnSobel();
	afx_msg void OnBnClickedBtnCanny();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedBtnBlur();
	afx_msg void OnBnClickedImageSave();
};

