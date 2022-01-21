#include "GameObject.h"
#include "BitMapManager.h"


void GameObject::init(BitMap* listimage)
{
	m_listImage = listimage;
	flowObject = 1;
}

void GameObject::Draw(HDC hdc, int height, int width)
{
	
	 // fire size x50 y 50
	
	m_listImage[GameObjectImage_RING_1].SizeUpDraw(hdc, flowObject+width*.9f, height*0.4f  , 1.5f, 1.5f);
	m_listImage[GameObjectImage_RING_2].SizeUpDraw(hdc, flowObject+width*.9f+20, height * 0.4f, 1.5f, 1.5f);



}


bool GameObject::Update(float time, float moveSpeed)
{
	/*if (flowWall < 0)
		flowObject -= 5;*/

	flowObject -= (500 + moveSpeed) * time;

	return true;
}

