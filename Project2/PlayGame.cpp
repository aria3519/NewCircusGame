#include "PlayGame.h"



#define MAXBACKGROUND 3

void PlayGame::Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage)
{
	playerLive = true;
	totalDistance = 0;
	m_timer = 0;
	m_Score = 0;
	m_interacttTimer = 0;
	m_dieTimer = 0;
	m_BonusTimer = 0;
	m_life = 3;
	m_Bonus = 10000;
	
	m_Character.Init(CharImage);
	m_Background.Init(BackIamge);
	for (int i = 0; i < 20; i++)
	{
		m_GameObject[i].init(GMImage);
		m_GameObject2[i].init(GMImage);
	}
	
}

void PlayGame::Draw(HDC hdc, int height, int width)
{
	m_Background.Draw(hdc, height, width,m_life);
	m_Character.Draw(hdc, height, width);
	for (int i = 0; i < 20; i++)
	{
		m_GameObject[i].Draw(hdc, height, width,i);
		m_GameObject2[i].Draw(hdc, height, width,i);
	}

	// 점수 표시
	auto distStr1 = std::to_string((m_Score));
	SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
	TextOutA(hdc, 250, 20, distStr1.c_str(), distStr1.length());

	

	auto distStr3 = std::to_string((m_Bonus));
	SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
	TextOutA(hdc, 450, 20, distStr3.c_str(), distStr3.length());
	if (m_Character.GetJampState() == 3)
	{
		auto distStr2 = std::to_string((int)(5 - m_timer));
		SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
		TextOutA(hdc, 500, 100, distStr2.c_str(), distStr2.length());

		std::string str = " 초 뒤에메인 메뉴로 넘어갑니다.";
		SetTextColor(hdc, RGB(255, 0, 0)); // 문자 색을 붉은색으로 변경.
		TextOutA(hdc, 550, 100, str.c_str(), str.length());
	}

}


bool PlayGame::Update(float time)
{
	if (playerLive)
	{
		m_BonusTimer += time;
		if (1.0f > m_BonusTimer && m_Character.GetJampState() != 3)
		{
			m_BonusTimer = 0;
			m_Bonus--;
		}
		
		playerSpeed = m_Character.Update(time, totalDistance);
		totalDistance = m_Background.Update(time, playerSpeed, totalDistance);
		
		if (m_Character.GetgoCharacter() >= 1200 && m_Character.GetJampState()==3)
		{
			
			m_Background.TrueRachEnd();
			m_Score += m_Bonus * m_timer/5.0f;
			m_Bonus = m_Bonus - m_Bonus * m_timer / 5.0f;
			m_timer += time;

			if (5.0f <= m_timer)
			{
				Reset();
				return false;
			}
			
		}
		else
		{
			for (int i = 0;i<20; i++)
			{
				m_GameObject[i].Update(time, playerSpeed);
				m_GameObject2[i].Update(time, playerSpeed);
			}

		}

		m_interacttTimer += time;
		if (0.05f <= m_interacttTimer)
		{
			// 상호 작용 체크 
			m_interacttTimer = 0;
			playerLive = InteractCheck();
			
			if (!playerLive)
			{
				m_life--;
				m_Character.Die();
			}
		}

		
		
	}
	else // 캐릭터가 죽은 경우
	{
		m_dieTimer += time;
		if (1.0f <= m_dieTimer)
		{
			m_dieTimer = 0;
			m_Character.Reset();
			m_Background.Reset();
			if (0 < m_life)playerLive = true;
			return playerLive;
		}
	}
	
	return true;
}




void PlayGame::Reset()
{
	m_timer = 0;
	m_interacttTimer = 0;
	m_dieTimer = 0;
	m_BonusTimer = 0;
	playerLive = true;
	m_Background.Reset();
	m_Character.Reset();
	for (int i = 0; i < 20; i++)
	{
		m_GameObject[i].Reset();
		m_GameObject2[i].Reset();
	}
	m_Score = 0;
	m_life = 3;
	m_Bonus = 10000;
	
}


bool PlayGame::InteractCheck()
{
	m_Character.GetRect();

	RECT temp;
	RECT charRect = m_Character.GetRect();
	RECT CheckRect;
	for (int i = 0; i < 20; i++)
	{
		CheckRect = m_GameObject[i].GetRectScore();
		// Score 
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			m_Score += 100;
			break;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		CheckRect = m_GameObject2[i].GetRectScore();
		// Score 
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			m_Score += 500;
			break;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		CheckRect = m_GameObject[i].GetRectKill();
		// kill
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			return false;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		CheckRect = m_GameObject2[i].GetRectKill();
		// kill
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			return false;
		}
	}
	for (int i=0;i<10;i++)
	{
		CheckRect = m_Background.GetRectKill(i);
		if (IntersectRect(&temp, &charRect, &CheckRect))
		{
			return false;
		}
	}
	CheckRect = m_Background.GetRectKill2();
	if (IntersectRect(&temp, &charRect, &CheckRect))
	{
		return false;
	}



	return true;
}

void PlayGame::Die(HDC hdc, int height, int width)
{
	m_Character.Draw(hdc, height, width);
}