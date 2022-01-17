#include "MainMenu.h"
#include "BitMapManager.h"


#define HEIGHT 17
#define WIDTH 7

void MainMenu::Init(BitMap* listimage)
{
	m_listImage = listimage;

	pointY = 1;
	m_time = 0;
	starIndex = MainImage_title2;
	
	pointY = 1;
}

void MainMenu::Draw(HDC hdc,int height, int width)
{
	// 0~4 menu , 5 point ,6~9 title
	/*for(int i=0;i<10;i++)
		m_listImage[i].Draw(hdc,0,i*30);*/

	m_listImage[MainImage_title1].Draw(hdc,width/2,0 + 50); // title draw
	// Rect Drawc 18 x 8
	

	int x = 0;
	int y = 0;
	bool count = true;
	for (x = 1;x< HEIGHT; x++) // top , bottom
	{
		if (MainImage_title4 < starIndex) starIndex = MainImage_title2;

		m_listImage[starIndex].Draw(hdc, width * 0.5f - 126 + 14 * x, 20 + 12 * (y + 1));
		starIndex++;

		if (x == HEIGHT - 1 && count == true)
		{

			count = false;
			y = WIDTH;
			x = 0;
		}
	}
	count = true;
	x = 0;
	for (y = 1; y < WIDTH; y++)
	{
		if (MainImage_title4 < starIndex) starIndex = MainImage_title2;

		m_listImage[starIndex].Draw(hdc, width * 0.5f - 126 + 14 * x, 20 + 12 * (y + 1));
		starIndex++;

		if (y == WIDTH - 1 && count == true)
		{
			count = false;
			x = HEIGHT;
			y = 0;
		}

	}
	
	for (int i = MainImage_menu1; MainImage_menu5 >= i; i++)
	{
		if(i==0)
			m_listImage[i].Draw(hdc, width / 2, height / 2 - 30);
		else
			m_listImage[i].Draw(hdc, width / 2, height / 2 + i * 30);
	}
	
	m_listImage[MainImage_point].Draw(hdc, width / 2 - 200, height / 2 + pointY*30);

}

int MainMenu::Update(float time)
{

	m_time += time;
	if (0.02f <= m_time)
	{
		m_time = 0;
		starIndex++;
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (pointY >= 2)
				pointY -= 1;

		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{

			if (pointY <= 3)
				pointY += 1;

		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{

			return -1;
		}
	}
}
