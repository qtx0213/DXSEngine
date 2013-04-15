#include "DxHeader.h"
#include "SGESingleton.h"
class CControlCenter: public CSGESingleton<CControlCenter>
{
private:
	CControlCenter(LPDIRECT3DDEVICE9 pD3DDevice9)
	{
		m_pD3DDev9 = pD3DDevice9;
	};

	~CControlCenter(){};

private:
	LPDIRECT3DDEVICE9	m_pD3DDev9;
public:
	static void Create(LPDIRECT3DDEVICE9 pD3DDevice9);

};