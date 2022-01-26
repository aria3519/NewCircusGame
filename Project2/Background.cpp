#include "Background.h"
#include "BitMapManager.h"


#define MAXBACKGROUND 2

void Background::Init(BitMap* listimage)
{
	m_listImage = listimage;
	flowWall = 1;
	
	m_Background = BackImage_Back3;
	m_fireObject = BackImage_FIRE_1;

	totalEndingX = 10;
	m_count = 0;
	m_ReachEnd = false;
	m_time = 0;
	m_timefire = 0;
	
}


void Background::Draw(HDC hdc, int height, int width)
{
	// back 0~3 4
	// back0 Xsize 67 Ysize 183
	 
	
	
	/*TextOutA(hdc, height * 0.5f, 0, "10", strlen("10"));*/

	for(int i=0;i<22;i++)// floor
		m_listImage[BackImage_Back1].SizeUpDraw(hdc, i*67  , height - 183*2 , 1, 2); 
	
	if (m_count < MAXBACKGROUND) // 배경이 흐를 경우 
	{

		for (int i = 0; i < 22 ; i++) //background
		{
			// Back 2 x 66 y 67
			// Back 3 x65 y 64
			// Back 4 x65 y 64


			if (i % 7 == 0) // 코끼리 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
				// 장애물 
				if (i % 2 == 0)
					m_listImage[m_fireObject].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height * 0.7f, 2, 2);
			}
		}
		// 밑에 거리 표시 기능 
		m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc, width * 1.1f + flowWall, height - 100, 2, 2);
		auto distStr = std::to_string((totalEndingX - m_count) * 100);// 거리 표시 
		SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
		TextOutA(hdc, width * 1.1f + flowWall + 30, height - 80, distStr.c_str(), distStr.length());
	}
	else if (m_count == MAXBACKGROUND)
	{
		for (int i = 0; i < 22; i++) //background
		{
			// Back 2 x 66 y 67
			// Back 3 x65 y 64
			// Back 4 x65 y 64


			if (i % 7 == 0) // 코끼리 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
				
				if (i % 2 == 0 && i<14)
					m_listImage[m_fireObject].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height * 0.7f, 2, 2);
			}
		}
	}
	else // 종착지점에 온 경우 
	{
		for (int i = 0; i < 14; i++) //background
		{
			if (i % 7 == 0) // 코끼리 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3, height - 183 * 2 - 64 * 3, 3, 3);
			}
		}
		m_listImage[BackImage_GOAL].SizeUpDraw(hdc, width * .85f+30 , height - 220, 2, 2);
	}


}


int Background::Update(float time, float speed, float totalx)
{
	m_time += time;
	m_timefire += time;
	flowWall -= speed * time;


	if (0.05f <= m_timefire) // 화염장애물 움직임 시간관리
	{
		m_timefire = 0;
		m_fireObject++;
		if (m_fireObject > BackImage_FIRE_2)
			m_fireObject = BackImage_FIRE_1;
	}

	// 벽 스크롤링 
	if (flowWall < -(65 * 3 * 14))
	{
		flowWall += (65 * 3 * 14);
		
		
		m_count++;
		
	}
	if (flowWall > 0 && m_count>0)
	{
		flowWall -= (65 * 3 * 14);
		m_count--;
	
	}
	
	if (flowWall > 0 ) // 뒤 못가게함 
	{
		flowWall = 1;
		
	}
	if (m_ReachEnd) // 끝에 도착 했을때 
	{
		if (0.05f <= m_time)
		{
			m_time = 0;
			m_Background++;
	
			if (m_Background > BackImage_Back4)
				m_Background = BackImage_Back3;
		}

	}
	
	
	return m_count;
	
}



void Background::Reset()
{

	flowWall = 1;
	m_Background = BackImage_Back3;
	totalEndingX = 10;
	m_count = 0;
	m_ReachEnd = false;
	m_time = 0;
	
	

}


