#include "ObjectFire.h"


void ObjectFire::init()
{
	m_Fire = 0;
	m_listImage[0] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_1);
	m_listImage[1] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_2);
	m_time = 0;
	x = 0;
	y = 0;
	
	
}

void ObjectFire::draw(HDC hdc, int height, float flowWall, int i)
{
	x = i * 65 * 3 + flowWall;
	y = height * 0.7f;

	m_listImage[m_Fire]->SizeUpDraw(hdc, x, y, 2, 2);

	
	rect = { (LONG)(x + 20), (LONG)y,  (LONG)(x)+80/*이미지 사이즈*/, (LONG)y + 100 };
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);//사각형 영역 그리기 
}


void ObjectFire::update(float time)
{
	
	if (0.1f <= m_time)
	{
		m_time = 0;
		m_Fire++;
	}

	if (m_Fire >= 2)
		m_Fire = 0;

	
	
}

