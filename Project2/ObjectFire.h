#pragma once
#include "BitMapManager.h"


class BitMap;


class ObjectFire
{

private:
	BitMap* m_listImage[2];
	int m_Fire;
	float m_time;

	float x, y;
	RECT rect;

public:
	void init();
	void draw(HDC hdc, int height, float flowWall);
	void update(int i, float height, float flowWall);
	void Checktime(float time);
};

