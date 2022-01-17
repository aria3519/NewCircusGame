#include "Background.h"
#include "BitMapManager.h"


void Background::Init(BitMap* listimage)
{
	m_listImage = listimage;
	MovePlayer = 1;
	
}


void Background::Draw(HDC hdc, int height, int width)
{
	// back 0~3 4
	// back0 Xsize 67 Ysize 183
	 
	// 거리 표시 
	m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc, width *0.5f -67, 0,2,2);
	/*TextOutA(hdc, height * 0.5f, 0, "10", strlen("10"));*/

	for(int i=0;i<22;i++)// floor
		m_listImage[BackImage_Back1].SizeUpDraw(hdc, i*67  , height - 183*2 , 1, 2); 
	

	for (int i=0;i<100 ;i++) //background
	{
		// Back 2 x 66 y 67
		// Back 3 x65 y 64
		// Back 4 x65 y 64

		
		 if (i == 0 || i % 7 == 0) // 코끼리 
		{
			 m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3 + MovePlayer, height - 183 * 2 - 64 * 3, 3, 3);
		}
		else
		{
			m_listImage[BackImage_Back3].SizeUpDraw(hdc, i * 65 * 3 + MovePlayer, height - 183 * 2 - 64*3, 3,3);
		}
	}
	
	

}


int Background::Update(float time)
{
	m_time += time;
	if (0.02f <= m_time)
	{
		m_time = 0;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			MovePlayer -= 10;
		}
	}
	return -MovePlayer;
}



void Background::Reset()
{
	MovePlayer = 0;
}