// SGWnd.cpp : implementation file
//

#include "stdafx.h"
#include "SGRenderEngineDX11.h"
#include "SGWnd.h"


// CSGWnd

IMPLEMENT_DYNAMIC(CSGWnd, CWnd)

CSGWnd::CSGWnd()
{
	m_pRenderEngine11 = new CSGRenderEngineDX11();
}

CSGWnd::~CSGWnd()
{
}


BEGIN_MESSAGE_MAP(CSGWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CSGWnd message handlers



int CSGWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	int nDeviceWidth = lpCreateStruct->cx;
	int nDeviceHeight = lpCreateStruct->cy;
	m_pRenderEngine11->InitDevice(m_hWnd,nDeviceWidth,nDeviceHeight);
	
	SetTimer(1,40,NULL);

	return 0;
}

void CSGWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	float fColor[] = {0.f,0.125f,0.3f,1.f};
	m_pRenderEngine11->ClearRenderTarget(fColor);
	m_pRenderEngine11->Present(NULL,NULL);

	CWnd::OnTimer(nIDEvent);
}
