#include "stdafx.h"
#include "SGRenderEngineDX11.h"

//
//
//



CSGRenderEngineDX11::CSGRenderEngineDX11()
{
	m_p11Device = NULL;
	m_p11DeviceContext = NULL;
	m_p11SwapChain = NULL;
	m_p11TargetView = NULL;
}

//
CSGRenderEngineDX11::~CSGRenderEngineDX11()
{
	//D3DXVECTOR3
}

//
BOOL CSGRenderEngineDX11::InitDevice(HWND hWnd,int nDeviceWidth,int nDeviceHeight)
{
	HRESULT hr = S_OK;
	UINT nCreateDeviceFlags = 0;
#ifdef _DEBUG
	nCreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG; 
#endif
	D3D_DRIVER_TYPE eDriveType[] = 
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_SOFTWARE,
		D3D_DRIVER_TYPE_REFERENCE
	};

	UINT nDriverTypeNum = ARRAYSIZE(eDriveType);

	D3D_FEATURE_LEVEL eFeatureLevel[] =
	{
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_11_0
	};

	UINT nFeatureNum = ARRAYSIZE(eFeatureLevel);

	DXGI_SWAP_CHAIN_DESC swapchainDesc;
	ZeroMemory(&swapchainDesc,sizeof(swapchainDesc));
	swapchainDesc.BufferCount = 1;
	swapchainDesc.BufferDesc.Width = nDeviceWidth;
	swapchainDesc.BufferDesc.Height = nDeviceHeight;
	swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapchainDesc.SampleDesc.Count = 1;
	swapchainDesc.SampleDesc.Quality = 0;
	swapchainDesc.OutputWindow = hWnd;
	swapchainDesc.Windowed = TRUE;
	for(int i = 0; i< nDriverTypeNum; i++)
	{
		D3D_DRIVER_TYPE eType = eDriveType[i];
		D3D_FEATURE_LEVEL eLevel;
		hr = D3D11CreateDeviceAndSwapChain(NULL,eType,
										   NULL,nCreateDeviceFlags,
										   eFeatureLevel,nFeatureNum,
										   D3D11_SDK_VERSION,&swapchainDesc,
										   &m_p11SwapChain,&m_p11Device,
										   &eLevel,&m_p11DeviceContext);
		if(SUCCEEDED(hr))
			break;
	}
	if(FAILED(hr))
		return FALSE;
	// RenderTargetView
	ID3D11Texture2D* p2DTexBuffer = NULL;
	m_p11SwapChain->GetBuffer(0,__uuidof(ID3D11Texture2D),(void**)&p2DTexBuffer);

	hr = m_p11Device->CreateRenderTargetView((ID3D11Resource*)p2DTexBuffer,NULL,&m_p11TargetView);
	p2DTexBuffer->Release();
	if(FAILED(hr))
		return FALSE;
	m_p11DeviceContext->OMSetRenderTargets(1,&m_p11TargetView,NULL);
	
	D3D11_VIEWPORT vpD3D11;
	vpD3D11.TopLeftX = 0.f;
	vpD3D11.TopLeftY = 0.f;
	vpD3D11.Width = nDeviceWidth;
	vpD3D11.Height = nDeviceHeight;
	vpD3D11.MinDepth = 0.f;
	vpD3D11.MaxDepth = 1.f;
	m_p11DeviceContext->RSSetViewports(1,&vpD3D11);

	return TRUE;
}

//
void CSGRenderEngineDX11::ClearRenderTarget(float* pfColor)
{
	m_p11DeviceContext->ClearRenderTargetView(m_p11TargetView,pfColor);
}

bool CSGRenderEngineDX11::Present(RECT* rtSrc,RECT* rtDst)
{
	m_p11SwapChain->Present(0,0);

	return true;
}