#include "PlayGame.h"



#define MAXBACKGROUND 3

void PlayGame::Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage)
{
	playerLive = true;
	totalDistance = 0;
	m_timer = 0;
	
	m_Character.Init(CharImage);
	m_Background.Init(BackIamge);
	m_GameObject.init(GMImage);
	m_GameObject2.init(GMImage);
	
}

void PlayGame::Draw(HDC hdc, int height, int width)
{
	m_Background.Draw(hdc, height, width);
	m_Character.Draw(hdc, height, width);
	m_GameObject.Draw(hdc, height, width);
	m_GameObject2.Draw(hdc, height, width);


}


bool PlayGame::Update(float time)
{
	if (playerLive)
	{
		playerSpeed = m_Character.Update(time, totalDistance);
		totalDistance = m_Background.Update(time, playerSpeed, totalDistance);
		
		if (m_Character.GetgoCharacter() >= 1200 && m_Character.GetJampState()==3)
		{
			
			m_Background.TrueRachEnd();
			m_timer += time;

			if (3.0f <= m_timer)
			{
				Reset();
				return false;
			}
			
		}
		else
		{
			m_GameObject.Update(time, playerSpeed);
			m_GameObject2.Update(time, playerSpeed);

		}
	}	
	
	return playerLive;
}




void PlayGame::Reset()
{
	m_timer = 0;
	playerLive = true;
	m_Background.Reset();
	m_Character.Reset();
	
}
