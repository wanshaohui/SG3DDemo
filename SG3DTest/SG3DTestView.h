
// SG3DTestView.h : interface of the CSG3DTestView class
//


#pragma once


class CSG3DTestView : public CView
{
protected: // create from serialization only
	CSG3DTestView();
	DECLARE_DYNCREATE(CSG3DTestView)

// Attributes
public:
	CSG3DTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSG3DTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SG3DTestView.cpp
inline CSG3DTestDoc* CSG3DTestView::GetDocument() const
   { return reinterpret_cast<CSG3DTestDoc*>(m_pDocument); }
#endif

