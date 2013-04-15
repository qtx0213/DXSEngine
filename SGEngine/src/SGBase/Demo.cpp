#include "StdAfx.h"
#include "Demo.h"

/********************************************************************************************
	static data define
*********************************************************************************************/
template<> CDemo* CSGESingleton<CDemo>::m_singleton = NULL;


/********************************************************************************************
	class data
*********************************************************************************************/
CDemo::CDemo(void)
{
}

CDemo::~CDemo(void)
{
}

//-------------------------------------------------------------------------//
bool CDemo::initDirectx9(HWND hwnd)
{
	IDirect3D9 *pD3D9;
	LPDIRECT3DDEVICE9 pD3DDEV9;
	D3DCAPS9 caps9;

	int vertexp = 0;

	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	pD3D9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps9);

	if(caps9.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vertexp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		vertexp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DDISPLAYMODE d3ddm;
	if( FAILED( pD3D9->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpparam;
	ZeroMemory( &d3dpparam, sizeof(d3dpparam) );
	d3dpparam.Windowed = TRUE;						// 窗口模式
	d3dpparam.SwapEffect = D3DSWAPEFFECT_DISCARD;// 设置交换模式
	d3dpparam.BackBufferFormat = d3ddm.Format;		// 设置背景缓冲区格式为当前左面格式
	pD3D9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpparam,
		&pD3DDEV9);

	m_hwnd = hwnd;
	m_pD3DDeviec9 = pD3DDEV9;
	return true;
}

//-------------------------------------------------------------------------//
void CDemo::render()
{
	m_pD3DDeviec9->Clear(0, 0, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0xff, 0, 0), 1.0f, 0);
	m_pD3DDeviec9->Present(0, 0, 0, 0);
}

//-------------------------------------------------------------------------//
void CDemo::Create()
{
	new CDemo();

}