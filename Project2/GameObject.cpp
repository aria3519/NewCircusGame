#include "GameObject.h"
#include "BitMapManager.h"


void GameObject::init(BitMap* listimage)
{
	m_listImage = listimage;
	m_cashImage = BitMapManager::GetInstance()->GetImage(IMAGE_CASH);
	flowObject = 0;
	count = 0;
	m_timeRing = 0;
	m_RingImage1 = GameObjectImage_RING_1;
	m_RingImage2 = GameObjectImage_RING_2;
	flowWall = 0;
	m_speed = 500;
	m_size = 1.5f;
	addx =0;
	check = false;
}

void GameObject::Draw(HDC hdc, int height, int width,int i)
{
	
	 // fire size x50 y 50
	m_x = flowObject + width * (.9f + 1.5f * i+1);
	m_y = height * 0.4f;
	m_listImage[m_RingImage1].SizeUpDraw(hdc, m_x + addx, m_y, m_size, m_size);
	m_listImage[m_RingImage2].SizeUpDraw(hdc, m_x + addx + 20, m_y, m_size, m_size);

	// 게임 오브젝트 히트 박스 
	m_ScoreRect = { (LONG)(m_x + addx), (LONG)m_y,(LONG)(m_x + addx) + 50/*이미지 사이즈*/, (LONG)m_y + 140 }; // 그려줄 상자 세팅 
	m_killRect = { (LONG)(m_x + addx), (LONG)m_y + 150,(LONG)(m_x + addx) + 50/*이미지 사이즈*/, (LONG)m_y + 50 + 150 }; // 그려줄 상자 세팅 

	//Rectangle(hdc, m_ScoreRect.left, m_ScoreRect.top, m_ScoreRect.right, m_ScoreRect.bottom);//사각형 영역 그리기 
	//Rectangle(hdc, m_killRect.left, m_killRect.top, m_killRect.right, m_killRect.bottom);//사각형 영역 그리기 
	if (check)
		m_cashImage->SizeUpDraw(hdc, m_x + addx, m_y + 80, 1.8f, 1.8f);


	
	
}

void GameObject::Reset()
{
	flowObject = 0;
	count = 0;
	m_timeRing = 0;
	m_RingImage1 = GameObjectImage_RING_1;
	m_RingImage2 = GameObjectImage_RING_2;
	flowWall = 0;
	m_speed = 500;
	m_size = 1.5f;
	addx = 0;
	check = false;
}


bool GameObject::Update(float time, float moveSpeed)
{
	m_timeRing += time;
	flowWall -= moveSpeed * time;

	if (0.1f <= m_timeRing)
	{
		m_timeRing = 0;
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
	

	flowObject -= (m_speed + moveSpeed) * time;
	

	return true;
}





void GameObject2::init(BitMap* listimage)
{
	GameObject::init(listimage);
	
	m_speed = 700;
	m_size = 1.4f;
	addx = -300.0f;
	check = true;
}
	
	
	


void GameObject2::Draw(HDC hdc, int height, int width,int i)
{
	
	GameObject::Draw(hdc, height, width,i);
	
}


void GameObject2::Reset()
{
	GameObject::Reset();
	m_speed = 700;
	m_size = 1.4f;
	addx = -300.0f;
	check = true;
}

