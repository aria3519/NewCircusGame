#include "MainMenu.h"
#include "BitMapManager.h"


#define HEIGHT 17
#define WIDTH 7

void MainMenu::Init(BitMap* listimage)
{
	m_listImage = listimage;
<<<<<<< HEAD
	pointY = 1;
	m_time = 0;
	starIndex = MainImage_title2;
	
=======
	pointY = 0;
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba
}

void MainMenu::Draw(HDC hdc,int height, int width)
{
	// 0~4 menu , 5 point ,6~9 title
	/*for(int i=0;i<10;i++)
		m_listImage[i].Draw(hdc,0,i*30);*/

	m_listImage[MainImage_title1].Draw(hdc,width/2,0 + 50); // title draw
	// Rect Drawc 18 x 8
	
<<<<<<< HEAD
	int x = 0;
	int y = 0;
	bool count = true;
	for (x = 1;x< HEIGHT; x++) // top , bottom
=======
	for (int y = 0; y < 8; y++) // height
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba
	{
		if (MainImage_title4 < starIndex) starIndex = MainImage_title2;

		m_listImage[starIndex].Draw(hdc, width * 0.5f - 126 + 14 * x, 20 + 12 * (y + 1));
		starIndex++;

		if (x == HEIGHT - 1 && count == true)
		{
<<<<<<< HEAD
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

=======
			// 126 = 14*9 
			if(x==0||x==17) //  side
				m_listImage[MainImage_title2].Draw(hdc, width / 2 - 126 + 14 * x, 20 + 12 * (y + 1));

			if(y==0||y==7) // top , bottom
				m_listImage[MainImage_title2].Draw(hdc, width / 2 - 126 +14*x, 20+12*(y+1));
			
		}
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba
	}
	
	for (int i = MainImage_menu1; MainImage_menu5 >= i; i++)
	{
		if(i==0)
			m_listImage[i].Draw(hdc, width / 2, height / 2 - 30);
		else
			m_listImage[i].Draw(hdc, width / 2, height / 2 + i * 30);
	}
	
	m_listImage[MainImage_point].Draw(hdc, width / 2 - 200, height / 2 +30 + pointY);

}

void MainMenu::Update(float time)
{
<<<<<<< HEAD
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

			return pointY;
		}
	}
=======
	
	
	/*case VK_DOWN:
		if(pointY<=90)
			pointY += 10;
		
		break;
	case VK_UP:
		if(pointY>=0)
			pointY -= 10;
		break;*/
	
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba


} 