#include "GameObject.h"
#include "BitMapManager.h"


void GameObject::init(BitMap* listimage)
{
	m_listImage = listimage;
	flowObject = 500;
	count = 0;
	m_timeRing = 0;
	m_RingImage1 = GameObjectImage_RING_1;
	m_RingImage2 = GameObjectImage_RING_2;
	flowWall = 0;
}

void GameObject::Draw(HDC hdc, int height, int width)
{
	
	 // fire size x50 y 50
	for (count = 0; count < 20; count++)
	{
		m_listImage[m_RingImage1].SizeUpDraw(hdc, flowObject + width * (.9f+1.5f* count), height * 0.4f, 1.5f, 1.5f);
		m_listImage[m_RingImage2].SizeUpDraw(hdc, flowObject + width * (.9f + 1.5f * count) + 20, height * 0.4f, 1.5f, 1.5f);
	}



}


bool GameObject::Update(float time, float moveSpeed)
{
	m_timeRing += time;
	flowWall -= moveSpeed * time;

	if (.5f <= m_timeRing)
	{
		if (m_RingImage1 == GameObjectImage_RING_1)
		{
			m_RingImage1 = GameObjectImage_RING_3;
			m_RingImage2 = GameObjectImage_RING_4;
		}
		else
		{
			m_RingImage1 = GameObjectImage_RING_1;
			m_RingImage2 = GameObjectImage_RING_2;
		}
	}

	if (flowWall > 0) // 뒤 못가게함 
	{
		moveSpeed = 0;

	}
	

	flowObject -= (500 + moveSpeed) * time;


	return true;
}

