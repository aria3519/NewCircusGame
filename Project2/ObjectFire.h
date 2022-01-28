#pragma once
#include "BitMapManager.h"


class BitMap;


class ObjectFire
{

private:
	BitMap* m_listImage[2];
	int m_Fire;

public:
	void init();
	void draw(HDC hdc, int height, int width, int i, float flowWall);
	void update();
};

