#include "Background.h"
#include "BitMapManager.h"


void Background::Init(BitMap* listimage)
{
	m_listImage = listimage;
	MoveBackground = BackImage_Back3;
	MovePlayer = 1;
	
}


void Background::Draw(HDC hdc, int height, int width)
{
	// back 0~3 4
	// back0 Xsize 67 Ysize 183
	 
	// 거리 표시 
	m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc,height*0.5f, 0,2,2);
	/*TextOutA(hdc, height * 0.5f, 0, "10", strlen("10"));*/

	for(int i=0;i<22;i++)// floor
		m_listImage[BackImage_Back1].SizeUpDraw(hdc, i*67  , height - 183*2 , 1, 2); 
	// Back 2 x 66 y 67
	m_listImage[BackImage_Back2].SizeUpDraw(hdc, 0 + MovePlayer, height - 183 * 2 - 67 * 3, 3, 3);

	MoveBackground = BackImage_Back3;

	for (int i=1;i<100 ;i++)
	{
		// Back 3 x65 y 64
		// Back 4 x65 y 64

		if (MoveBackground > BackImage_Back4) MoveBackground = BackImage_Back3;
		 if (i == 1)
		{
			m_listImage[MoveBackground].SizeUpDraw(hdc,66 * 3 + MovePlayer, height - 183 * 2 - 64 * 3, 3, 3);
		}
		else if(i%2==0)
		{
			int a= i - 2;
			m_listImage[MoveBackground].SizeUpDraw(hdc, a * 65*3 + 66*3 + MovePlayer, height - 183 * 2 - 64*3 ,3,3);
		}
		else
		{
			int a = i - 2;
			m_listImage[MoveBackground].SizeUpDraw(hdc, a * 65*3 + 66*3 + MovePlayer, height - 183 * 2 - 64*3, 3,3);
		}
		 MoveBackground++;
	}
	
	

}


void Background::Update(float time)
{
	m_time += time;
	if (0.02f <= m_time)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			MovePlayer -= 10;
		}
	}

}