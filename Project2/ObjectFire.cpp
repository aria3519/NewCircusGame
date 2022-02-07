#include "ObjectFire.h"


void ObjectFire::init()
{
	m_Fire = 0;
	m_listImage[0] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_1);
	m_listImage[1] = BitMapManager::GetInstance()->GetImage(IMAGE_FIRE_2);
	m_time = 0;
}

void ObjectFire::draw(HDC hdc, int height, float flowWall)
{
	
	m_listImage[m_Fire]->SizeUpDraw(hdc, x, y, 2, 2);

	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);//�簢�� ���� �׸��� 
}


void ObjectFire::update(int i, float height,float flowWall)
{
	x = i * 65 * 3 + flowWall;
	y = height * 0.7f;
	
	
	if (0.1f <= m_time)
	{
		m_time = 0;
		m_Fire++;
	}

	if (m_Fire >= 2)
		m_Fire = 0;

	rect = { (LONG)(x+20), (LONG)y,  (LONG)(x) + 80/*�̹��� ������*/, (LONG)y + 100};
}

void ObjectFire::Checktime(float time)
{
	m_time += time;

}