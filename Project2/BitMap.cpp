#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc,char* FileName)
{
	MemDC = CreateCompatibleDC(hdc);
	m_BitMap = (HBITMAP)LoadImageA(NULL, FileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);
	BITMAP BitMap_Info;
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info);
	m_Size.cx = BitMap_Info.bmWidth;
	m_Size.cy = BitMap_Info.bmHeight;
}
void BitMap::Draw(HDC hdc, int x, int y)
{
	/*StretchBlt(hdc, x, y, m_Size.cx, m_Size.cy, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);*/

	TransparentBlt(hdc, x, y, m_Size.cx, m_Size.cy, MemDC, 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
}

void BitMap::SizeUpDraw(HDC hdc, int x, int y, int sizex, int sizey)
{
	TransparentBlt(hdc, x, y, m_Size.cx * sizex, m_Size.cy* sizey, MemDC, 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
}

BitMap::~BitMap()
{
	SelectObject(MemDC, m_OldBitMap);
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
