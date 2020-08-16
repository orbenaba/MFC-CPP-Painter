//
// mfcPainterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfcPainter.h"
#include "mfcPainterDlg.h"
#include "afxdialogex.h"
#include "Square.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Flower.h"
#include "Rectangle1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcPainterDlg dialog




CmfcPainterDlg::CmfcPainterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcPainterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	futureShape = FLOWER;
	s = NULL;
	isPressed = false;

	curColor = RGB(255,255,255);
}

void CmfcPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcPainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CmfcPainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CmfcPainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &CmfcPainterDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CmfcPainterDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CmfcPainterDlg::OnBnClickedButton2)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON5, &CmfcPainterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CmfcPainterDlg::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON6, &CmfcPainterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CmfcPainterDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CmfcPainterDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON12, &CmfcPainterDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CmfcPainterDlg message handlers

BOOL CmfcPainterDlg::OnInitDialog()//פונקצית איתחול
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	
	HBITMAP bmp = LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP_Painter));//תמונת רקע
	SetBackgroundImage(bmp,BACKGR_TOPLEFT);


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmfcPainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmfcPainterDlg::OnPaint()
{
	CPaintDC dc(this); 
	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
	for(int i = 0; i < shapeArr.GetSize(); i++)
	{
		CBrush myBrush;
		myBrush.CreateSolidBrush((*shapeArr[i]).getBgColor());
        dc.SelectObject(&myBrush);

		//(dc).SetDCPenColor((*shapeArr[i]).bgColor);
		(*shapeArr[i]).Draw(&dc);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmfcPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcPainterDlg::OnBnClickedButton4()//SQUARE
{
	futureShape = SQUARE;
}


void CmfcPainterDlg::OnBnClickedButton3()//RECTANGLE
{
	futureShape = RECTANGLE;
}




void CmfcPainterDlg::OnBnClickedButton2()//CIRCLE
{
	futureShape = CIRCLE;
}


void CmfcPainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(isPressed)
	{
		endP = point;
		isPressed = false;


		switch(futureShape)
		{
			case RECTANGLE:
				shapeArr.Add(new Rectangle1(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case ELLIPSE:
				shapeArr.Add(new Ellipse1(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case CIRCLE:
				shapeArr.Add(new Circle(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case FLOWER:
				shapeArr.Add(new Flower(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case SQUARE:
				shapeArr.Add(new Square(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
		}
		if (!oldshapeArr.IsEmpty())
			oldshapeArr.RemoveAll();
		Invalidate();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmfcPainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(isPressed)
	{
		CClientDC dc(this);

		CBrush myBrush, *oldBrush;
		myBrush.CreateSolidBrush(RGB(255,255,255));
		oldBrush = dc.SelectObject(&myBrush);

		CPen myPen1(PS_SOLID, 1, RGB(0,0,0));

		CPen *oldPen;
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);

		dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
		endP = point;
		dc.Rectangle(startP.x, startP.y, endP.x, endP.y);

		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);

		dc.SelectObject(oldBrush);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CmfcPainterDlg::OnBnClickedButton5()//FLOWER
{
	futureShape = FLOWER;
}


void CmfcPainterDlg::OnBnClickedButton1()//ELLIPSE
{
	futureShape = ELLIPSE;

}


void CmfcPainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	endP = startP = point;
	isPressed = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}



void CmfcPainterDlg::OnBnClickedButton8()//save
{
	CFile file(_T("File.$$"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	shapeArr.Serialize(ar);
	ar.Close();
	file.Close();
}

void CmfcPainterDlg::OnBnClickedButton7() //open
{
	
	CFile file(_T("File.$$"), CFile::modeRead);
	CArchive ar (&file, CArchive::load);
    shapeArr.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
}



void CmfcPainterDlg::OnBnClickedButton6() //new
{
	shapeArr.RemoveAll();
	Invalidate();

	isPressed=false;

	UpdateData(true);
	curColor=RGB(255,255,255);

}


void CmfcPainterDlg::OnBnClickedButton10() // undo
{
	if(!shapeArr.IsEmpty())
	{
		oldshapeArr.Add(shapeArr[shapeArr.GetSize()-1]);
		shapeArr.RemoveAt(shapeArr.GetSize()-1);
		Invalidate();
	}
	
}


void CmfcPainterDlg::OnBnClickedButton9()//redo
{
	if(!oldshapeArr.IsEmpty())
	{
		shapeArr.Add(oldshapeArr[oldshapeArr.GetSize()-1]);
		oldshapeArr.RemoveAt(oldshapeArr.GetSize()-1);
		Invalidate();
	}

}



void CmfcPainterDlg::OnBnClickedButton12()//colors
{
 CMFCColorDialog CMFC;
 CMFC.DoModal();
 curColor = CMFC.GetColor();
}
