#pragma once
#include<Windows.h>
#include<string>
#pragma comment(lib, "msimg32.lib") 


class BitMap
{
private:
	HDC MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE m_Size;
public:
	void Init(HDC hdc,char* FileName);
	void Draw(HDC hdc, int x, int y);
	void SizeUpDraw(HDC hdc, int x, int y,int sizex, int sizey);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};

