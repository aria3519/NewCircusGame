#include "Character.h"
#include "BitMapManager.h"

void Character::Init(BitMap* listimage)
{
	m_listImage = listimage;
	MovingPlayer = CharImage_PLAYER_1;
	PlayerY = 1;
	jampState = 0;
	moveSpeed = 0;
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

float Character::Update(float time, int totalX)
{

	if (jampState !=0) // 점프 동작 
	{
		MovingPlayer = CharImage_PLAYER_3;
		Jamp(time);
		return moveSpeed;
	}

	m_time += time;
	if (0.02f <= m_time)
	{
		m_time = 0;

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) // 점프 
		{
			jampState = 1;
			return moveSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
		{
			moveSpeed = 1000;
			MovingPlayer++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (totalX <= 0)
				moveSpeed = 0;
			else
			{
				moveSpeed = -1000;
				MovingPlayer++;
			}
		}
		else 
		{
			moveSpeed = 0;
			MovingPlayer = CharImage_PLAYER_1;
		}
	}

	return moveSpeed;
}

void Character::Reset()
{
	PlayerY = 0;
}

void Character::Jamp(float time)
{
	if (jampState == 1)
	{
		if (PlayerY > -(63 * 3)) // 점프시 올라갈때
		{
			PlayerY -= 1000 * time;
		}
		else
			jampState = 2;
	}
	else if(jampState == 2)
	{
		if (PlayerY < 0) // 점프시 내려갈때 
			PlayerY += 1000 * time;
		else
		{
			jampState = 0;
			
		}
	}
	
}
