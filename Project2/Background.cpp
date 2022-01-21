#include "Background.h"
#include "BitMapManager.h"


void Background::Init(BitMap* listimage)
{
	m_listImage = listimage;
	flowWall = 1;
	
	

	totalEndingX = 10;
	m_count = 0;
	
}


void Background::Draw(HDC hdc, int height, int width)
{
	// back 0~3 4
	// back0 Xsize 67 Ysize 183
	 
	
	
	/*TextOutA(hdc, height * 0.5f, 0, "10", strlen("10"));*/

	for(int i=0;i<22;i++)// floor
		m_listImage[BackImage_Back1].SizeUpDraw(hdc, i*67  , height - 183*2 , 1, 2); 
	

	for (int i=0;i<14 * 2 ;i++) //background
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
			m_listImage[BackImage_Back3].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64*3, 3,3);
		}
	}

	
	
	// 장애물 
	m_listImage[BackImage_FIRE_1].SizeUpDraw(hdc, width * 1.1f + flowWall, height * 0.7f, 2, 2);
	
	m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc, width*1.1f + flowWall, height - 100, 2, 2);
	auto distStr = std::to_string((totalEndingX - m_count)*100);// 거리 표시 
	SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
	TextOutA(hdc, width*1.1f  + flowWall+ 30, height - 80, distStr.c_str(), distStr.length());

}


int Background::Update(float time, float speed, float totalx)
{

	flowWall -= speed * time;

	// 벽 스크롤링 
	if (flowWall < -(65 * 3 * 14))
	{
		flowWall += (65 * 3 * 14);
		
		endingX -= totalx;
		m_count++;
		/*ShowendingX = (endingX / totalEndingX) * 100;*/
	}
	if (flowWall > 0 && m_count>0)
	{
		flowWall -= (65 * 3 * 14);
		m_count--;
	/*	endingX += totalx;*/
	}
	
	if (flowWall > 0 && m_count == 0) // 뒤 못가게함 
	{
		flowWall = 1;
	}
	
	return m_count;
	
}



void Background::Reset()
{
	
	flowWall = 1;
	endingX = totalEndingX;
	

}