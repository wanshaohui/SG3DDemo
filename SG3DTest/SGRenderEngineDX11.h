#pragma once

//
// DX11∞Ê±æ‰÷»æ“˝«Ê
//

class CSGRenderEngineDX11
{
public:
	CSGRenderEngineDX11();
	~CSGRenderEngineDX11();

public:
	BOOL                        InitDevice(HWND hWnd,int nDeviceWidth,int nDeviceHeight);
	
	void                        ClearRenderTarget(float* pfColor);

	bool                        Present(RECT* rtSrc,RECT* rtDst);
private:
	ID3D11Device*               m_p11Device;
	ID3D11DeviceContext*        m_p11DeviceContext;
	IDXGISwapChain*             m_p11SwapChain;
	ID3D11RenderTargetView*     m_p11TargetView;


};