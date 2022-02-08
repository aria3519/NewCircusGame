#include "Character.h"
#include "BitMapManager.h"



#define MAXBACKGROUND 2

void Character::Init(BitMap* listimage)
{
	m_listImage = listimage;
	MovingPlayer = CharImage_PLAYER_1;
	PlayerY = 1;
	jampState = 0;
	moveSpeed = 0;
	goCharacter = 66 * 1;
	m_height = 0;
}

void Character::Draw(HDC hdc, int height, int width)
{
	m_height = height;
	if (MovingPlayer == CharImage_PLAYER_5)
	{

		
	}
	// char x 66 y 63
	else if (MovingPlayer > CharImage_PLAYER_3)
	{
		MovingPlayer = CharImage_PLAYER_2;
	}
	m_listImage[MovingPlayer].SizeUpDraw(hdc,goCharacter, height - (63 * 2) * 2 + PlayerY,2,2);
	m_CharRect = { (LONG)(goCharacter+50), (LONG)m_height - (63 * 2) * 2 + PlayerY,  (LONG)(goCharacter + 50)+50/*�̹��� ������*/, (LONG)m_height - (63 * 2) * 2 + PlayerY + 120 }; // �׷��� ���� ���� 
	Rectangle(hdc, m_CharRect.left, m_CharRect.top, m_CharRect.right, m_CharRect.bottom);//�簢�� ���� �׸��� 

}

float Character::Update(float time, int totalX)
{
	
	if (jampState !=0 && jampState !=3) // ���� ���� 
	{
		MovingPlayer = CharImage_PLAYER_3;
		Jamp(time);
		return moveSpeed;
	}
	m_totalX = totalX;
	m_time += time;

	if (jampState == 3)
	{
	
		return 0;
	}

	if (0.02f <= m_time)
	{
		m_time = 0;

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) // ���� 
		{
			jampState = 1;
			return moveSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
		{
			if (m_totalX <= MAXBACKGROUND)
			{
				moveSpeed = 1000;
				
			}
			else
			{
				moveSpeed = 1;
				if(goCharacter <= 1200) // ���̻� ���������� ������
					goCharacter += 1000* time;
			}
			MovingPlayer++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (m_totalX <= MAXBACKGROUND)
			{
				moveSpeed = -1000;
			}
			else 
			{
				moveSpeed = -1;
				goCharacter -= 1000 * time;
				
				if (goCharacter <= 0)
				{
					goCharacter = 0;
					moveSpeed = -1000;
				}


				
			}
			MovingPlayer++;
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
	MovingPlayer = CharImage_PLAYER_1;
	PlayerY = 1;
	jampState = 0;
	moveSpeed = 0;
	goCharacter = 0;
}

void Character::Jamp(float time)
{
	if (jampState == 1)
	{
		
		if (PlayerY > -(63 * 3)) // ������ �ö󰥶�
		{
			PlayerY -= 1000 * time;
		}
		else
			jampState = 2;
	}
	else if(jampState == 2)
	{
		
		if (PlayerY < 0) // ������ �������� 
		{
			
			if (goCharacter >= 1200) // ������ ��� 
			{
				if (PlayerY >= -81 && PlayerY <= -71)
				{
					MovingPlayer = CharImage_PLAYER_5;
					jampState = 3;
					return;
				}
			}
			PlayerY += 1000 * time;
		}
		else
		{
			jampState = 0;
			
		}
	}
	if (m_totalX > MAXBACKGROUND && moveSpeed >0&& goCharacter < 1200)
	{
		goCharacter += 1000 * time;

	}
	if (m_totalX > MAXBACKGROUND && moveSpeed < 0 && goCharacter>0)
	{
		goCharacter -= 1000 * time;

	}

	
}



