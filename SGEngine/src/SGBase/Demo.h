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

	// Draw cubic test
	IDirect3DVertexBuffer9 *m_pVertexBuff; //顶点数据
	IDirect3DIndexBuffer9 *m_pIndexBuff; //索引数据

	const int m_width = 800;
	const int m_height = 600;

	struct vertex
	{
		vertex(){};
		vertex(float x, float y, float z)
		{
			_x=x;
			_y=y;
			_z=z;
		};
		float _x, _y, _z;
		static const DWORD FVF;
	};

	void drawCubic();
	/*************** Draw cubic test over***********************/

public:
	static void Create();
	bool	initDirectx9(HWND hwnd);
	void	render();
	void	clear();
};
