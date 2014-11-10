
// SG3DTestView.cpp : implementation of the CSG3DTestView class
//

#include "stdafx.h"
#include "SG3DTest.h"

#include "SG3DTestDoc.h"
#include "SG3DTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSG3DTestView

IMPLEMENT_DYNCREATE(CSG3DTestView, CView)

BEGIN_MESSAGE_MAP(CSG3DTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSG3DTestView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSG3DTestView construction/destruction

CSG3DTestView::CSG3DTestView()
{
	// TODO: add construction code here

}

CSG3DTestView::~CSG3DTestView()
{
}

BOOL CSG3DTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSG3DTestView drawing

void CSG3DTestView::OnDraw(CDC* /*pDC*/)
{
	CSG3DTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSG3DTestView printing


void CSG3DTestView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CSG3DTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSG3DTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSG3DTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSG3DTestView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSG3DTestView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CSG3DTestView diagnostics

#ifdef _DEBUG
void CSG3DTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSG3DTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSG3DTestDoc* CSG3DTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSG3DTestDoc)));
	return (CSG3DTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSG3DTestView message handlers
