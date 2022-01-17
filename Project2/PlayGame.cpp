#include "PlayGame.h"





void PlayGame::Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage)
{
	m_Character.Init(CharImage);
	m_Background.Init(BackIamge);
	m_GameObject.init(GMImage);
}

void PlayGame::Draw(HDC hdc, int height, int width)
{
	m_Background.Draw(hdc, height, width);
	m_Character.Draw(hdc, height, width);
	m_GameObject.Draw(hdc, height, width);

}


bool PlayGame::Update(float time)
{
	if (playerLive)
	{
		MovePlayer = m_Background.Update(time);
		m_Character.Update(time);
	}
	
	playerLive = m_GameObject.Update(MovePlayer);
	return playerLive;
}


void PlayGame::Reset()
{
	playerLive = true;
	m_Background.Reset();
	m_Character.Reset();
}
