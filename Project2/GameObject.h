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
	BitMap* m_cashImage;
	float flowObject;
	float flowWall;

	int count;

	float m_timeRing;
	int m_RingImage1;
	int m_RingImage2;
	
	RECT m_ScoreRect;
	RECT m_killRect;
	
	float m_y, m_x;

	


	

protected:
	float m_speed;
	float m_size;
	float addx;
	bool check;
	
public:
	virtual void init(BitMap* listimage);
	virtual void Draw(HDC hdc, int height, int width);
	virtual RECT GetRectScore()
	{
		return m_ScoreRect;
	}
	virtual RECT GetRectKill()
	{
		return m_killRect;
	}
	bool Update(float time, float moveSpeed);



};

class GameObject2 : public GameObject
{
	
	

public:
	virtual void init(BitMap* listimage);
	virtual void Draw(HDC hdc, int height, int width);
	
};