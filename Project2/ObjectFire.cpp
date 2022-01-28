#include "ObjectFire.h"


void ObjectFire::init()
{
	m_Fire = 0;
	m_listImage[0] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_1);
	m_listImage[1] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_2);	
}

void ObjectFire::draw(HDC hdc, int height, int width, int i, float flowWall)
{
	
	m_listImage[m_Fire]->SizeUpDraw(hdc, i * 65 * 3 + flowWall, height * 0.7f, 2, 2);

}


void ObjectFire::update()
{
	m_Fire++;

	if (m_Fire >= 2)
		m_Fire = 0;
}