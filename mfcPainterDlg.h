//
// mfcPainterDlg.h : header file
//

#pragma once
#include "Shape.h"

// CmfcPainterDlg dialog
class CmfcPainterDlg : public CDialogEx
{
	enum SHAPES{RECTANGLE, CIRCLE, ELLIPSE, FLOWER, SQUARE};
	SHAPES futureShape;

	COLORREF curColor;

	Shape* s;
	CTypedPtrArray<CObArray, Shape*> shapeArr;
	CTypedPtrArray<CObArray, Shape*> oldshapeArr;

	bool isPressed;
	CPoint startP;
	CPoint endP;

// Construction
public:
	CmfcPainterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCPAINTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton12();
};
