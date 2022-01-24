#include "GameObject.h"
#include "BitMapManager.h"


void GameObject::init(BitMap* listimage)
{
	m_listImage = listimage;
	flowObject = 500;
	count = 0;
}

void GameObject::Draw(HDC hdc, int height, int width)
{
	
	 // fire size x50 y 50
	for (count = 0; count < 100; count++)
	{
		m_listImage[GameObjectImage_RING_1].SizeUpDraw(hdc, flowObject + width * (.9f+0.5f* count), height * 0.4f, 1.5f, 1.5f);
		m_listImage[GameObjectImage_RING_2].SizeUpDraw(hdc, flowObject + width * (.9f + 0.5f * count) + 20, height * 0.4f, 1.5f, 1.5f);
	}



}


bool GameObject::Update(float time, float moveSpeed)
{
	/*if (flowWall < 0)
		flowObject -= 5;*/

	
	if (moveSpeed<0)
	{
		flowObject -= 500 * time;
	}
	else
		flowObject -= (500 + moveSpeed) * time;

	

	

	return true;
}

