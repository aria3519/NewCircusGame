#include "BitMapManager.h"

BitMapManager* BitMapManager::m_hThis = NULL;

BitMapManager::BitMapManager()
{
	m_parrBitMap = new BitMap[IMAGE_END];
}


BitMap* BitMapManager::Init(HDC hdc)
{
	char buf[256];
	
	for (int i = IMAGE_BACK_1; i < IMAGE_END; i++)
	{
		sprintf_s(buf, "RES//0%d.bmp", i);
		m_parrBitMap[i].Init(hdc,buf);
	}
	return m_parrBitMap;
}

BitMapManager::~BitMapManager()
{
	delete[] m_parrBitMap;
}
