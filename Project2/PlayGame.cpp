#include "PlayGame.h"



#define MAXBACKGROUND 3

void PlayGame::Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage)
{
	playerLive = true;
	totalDistance = 0;
	m_timer = 0;
	m_Score = 0;
	
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

	// 점수 표시
	auto distStr = std::to_string((m_Score));
	SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
	TextOutA(hdc, 150, 20, distStr.c_str(), distStr.length());

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
		// 상호 작용 체크 
		playerLive = InteractCheck();

		
		
	}	
	
	return playerLive;
}




void PlayGame::Reset()
{
	m_timer = 0;
	playerLive = true;
	m_Background.Reset();
	m_Character.Reset();
	m_Score = 0;
	
	
}


bool PlayGame::InteractCheck()
{
	m_Character.GetRect();

	RECT temp;
	RECT charRect = m_Character.GetRect();
	RECT CheckRect = m_GameObject.GetRectScore();
	// Score 
	if (IntersectRect(&temp, &charRect, &CheckRect))
	{
		m_Score += 100;
	}
	CheckRect = m_GameObject.GetRectKill();
	// kill
	if (IntersectRect(&temp, &charRect, &CheckRect))
	{
		return false;
	}
	for (int i=0;i<10;i++)
	{
		CheckRect = m_Background.GetRectKill(i);
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			return false;
		}
	}



	return true;
}