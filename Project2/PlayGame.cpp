#include "PlayGame.h"





void PlayGame::Init(BitMap* BackIamge, BitMap* CharImage)
{
	m_Character.Init(CharImage);
	m_Background.Init(BackIamge);
}

void PlayGame::Draw(HDC hdc, int height, int width)
{
	m_Background.Draw(hdc, height, width);
	m_Character.Draw(hdc, height, width);

}


void PlayGame::Update(float time)
{
	m_Background.Update(time);
	m_Character.Update(time);
}

