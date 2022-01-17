#pragma once
#include<Windows.h>
#include<string>


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

};

class Background
{

private:
	BitMap* m_listImage;
	float m_time;
	int MoveBackground;
	int MovePlayer;
	

public:
	void Init(BitMap* listimage);
	void Draw(HDC hdc, int height, int width);
	void Update(float time);
};

