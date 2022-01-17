#include "Character.h"
#include "BitMapManager.h"

void Character::Init(BitMap* listimage)
{
	m_listImage = listimage;
	MovingPlayer = CharImage_PLAYER_1;
	PlayerY = 1;
	UsingJamp = false;
}

void Character::Draw(HDC hdc, int height, int width)
{
	// char x 66 y 63
	if (MovingPlayer > CharImage_PLAYER_3)
	{
		MovingPlayer = CharImage_PLAYER_2;
	}
	m_listImage[MovingPlayer].SizeUpDraw(hdc, 66*1 , height - (63*2)*2 + PlayerY,2,2);

}

void Character::Update(float time)
{
	m_time += time;
	if (0.02f <= m_time)
	{
		m_time = 0;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			MovingPlayer++;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			Jamp(time);
		}
	}
}

void Character::Reset()
{
	PlayerY = 0;
}

void Character::Jamp(float time)
{
	/*if (!UsingJamp)
	{
		UsingJamp = true;
		PlayerY -= 10 * m_time;
	}
	else
		UsingJamp = false;*/


	PlayerY -= 66;
}
