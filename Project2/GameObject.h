#pragma once
#include<Windows.h>
#include<string>


class BitMap;

enum GameObjectImage
{
	GameObjectImage_LITTLERING_1,
	GameObjectImage_LITTLERING_2,
	GameObjectImage_RING_1,
	GameObjectImage_RING_2,
	GameObjectImage_RING_3,
	GameObjectImage_RING_4,
};
class GameObject
{
private:
	BitMap* m_listImage;
	float flowObject;
	float flowWall;

	int count;

	float m_timeRing;
	int m_RingImage1;
	int m_RingImage2;
	

public:
	void init(BitMap* listimage);
	void Draw(HDC hdc, int height, int width);
	bool Update(float time, float moveSpeed);



};

