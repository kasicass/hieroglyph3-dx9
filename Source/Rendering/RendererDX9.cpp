#include "RendererDX9.h"

#include "Log.h"

using namespace Glyph3;

RendererDX9::RendererDX9()
{
	m_pD3D = NULL;
	m_pD3DDevice9 = NULL;
}

RendererDX9::~RendererDX9()
{
}

bool RendererDX9::Initialize( int w, int h, bool windowed, HWND hwnd )
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!m_pD3D)
	{
		Log::Get().Write(L"Direct3DCreate9() failed");
		return false;
	}

	m_d3dPP.BackBufferWidth            = 0;
	m_d3dPP.BackBufferHeight           = 0;
	m_d3dPP.BackBufferFormat           = D3DFMT_UNKNOWN;
	m_d3dPP.BackBufferCount            = 1;
	m_d3dPP.MultiSampleType            = D3DMULTISAMPLE_NONE;
	m_d3dPP.MultiSampleQuality         = 0;
	m_d3dPP.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
	m_d3dPP.hDeviceWindow              = hwnd;
	m_d3dPP.Windowed                   = windowed;
	m_d3dPP.EnableAutoDepthStencil     = true;
	m_d3dPP.AutoDepthStencilFormat     = D3DFMT_D24S8;
	m_d3dPP.Flags                      = 0;
	m_d3dPP.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	m_d3dPP.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	DWORD devBehaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	D3DDEVTYPE devType = D3DDEVTYPE_HAL;
		
	HRESULT hr = m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, // primay adapter
		devType,            // device type
		hwnd,               // window associated with device
		devBehaviorFlags,   // vertex processing
		&m_d3dPP,           // present parameters
		&m_pD3DDevice9);    // return created device
	return SUCCEEDED(hr);
}

void RendererDX9::Shutdown()
{
	SAFE_RELEASE(m_pD3DDevice9);
	SAFE_RELEASE(m_pD3D);
}

void RendererDX9::Clear()
{
	m_pD3DDevice9->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,0,0), 1.0f, 0);
}

void RendererDX9::Present()
{
	m_pD3DDevice9->Present(0, 0, 0, 0);
}