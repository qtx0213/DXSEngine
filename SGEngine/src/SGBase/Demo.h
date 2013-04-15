#pragma once
#include "DxHeader.h"
#include "SGESingleton.h"
class CDemo:public CSGESingleton<CDemo>
{
private:
	CDemo(void);
	~CDemo(void);
private:
	HWND				m_hwnd;
	LPDIRECT3DDEVICE9	m_pD3DDeviec9;
public:
	static void Create();
	bool	initDirectx9(HWND hwnd);
	void	render();
	void	clear();
};
