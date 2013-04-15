#include "stdafx.h"
#include "ControlCenter.h"

/********************************************************************************************
static data define
*********************************************************************************************/
template<> CControlCenter* CSGESingleton<CControlCenter>::m_singleton = NULL;

/********************************************************************************************
CLASS
*********************************************************************************************/
void CControlCenter::Create(LPDIRECT3DDEVICE9 pD3DDevice9)
{
	new CControlCenter(pD3DDevice9);
}