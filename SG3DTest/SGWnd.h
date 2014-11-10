#pragma once


// CSGWnd
class CSGRenderEngineDX11;
class CSGWnd : public CWnd
{
	DECLARE_DYNAMIC(CSGWnd)

public:
	CSGWnd();
	virtual ~CSGWnd();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CSGRenderEngineDX11*           m_pRenderEngine11;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


