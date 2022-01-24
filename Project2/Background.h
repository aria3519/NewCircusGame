#pragma once
#include "GameObject.h"
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
	GameObject m_gm;
	float m_time;
	float flowWall;
	
	int ShowendingX;
	int totalEndingX;

	int m_count;
	
	
	

public:
	void Init(BitMap* listimage);
	void Draw(HDC hdc, int height, int width);
	int Update(float time ,float speed, float totalX);

	void Reset();
};

