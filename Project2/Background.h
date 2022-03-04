#pragma once
#include "GameObject.h"
#include "ObjectFire.h"
//#include<Windows.h>
//#include<string>



class BitMap;

enum BackImage
{
	BackImage_Back1,
	BackImage_Back2,
	BackImage_Back3,
	BackImage_Back4,
	BackImage_INTERFACE_1,
	BackImage_INTERFACE_2,
	BackImage_INTERFACE_3,
	BackImage_GOAL,
	BackImage_FIRE_1,
	BackImage_FIRE_2,

};

class Background
{

private:
	BitMap* m_listImage;
	BitMap* m_UIImage[3];
	float m_time;
	float m_timefire;
	float flowWall;
	
	int ShowendingX;
	int totalEndingX;

	int m_count;
	
	int m_Background;
	bool m_ReachEnd;
	int m_fireObject;

	ObjectFire m_fire[10];
	ObjectFire m_goalfire[1];
	float m_height;

	RECT killBox[10];
	
		
	
	

public:
	void Init(BitMap* listimage);
	void Draw(HDC hdc, int height, int width, int life);
	int Update(float time ,float speed, float totalX);

	void Reset();

	void TrueRachEnd()
	{
		m_ReachEnd = true;

		
	}

	RECT GetRectKill(int i)
	{
		return m_fire[i].GetRect();
	}
	RECT GetRectKill2()
	{
		return m_goalfire[0].GetRect();
	}
	
};

