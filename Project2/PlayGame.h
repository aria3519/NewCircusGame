#pragma once

#include"Character.h"
#include"Background.h"


class PlayGame
{

private:
	Character m_Character;
	Background m_Background;


public:
	void Init(BitMap* BackIamge, BitMap* CharImage);
	void Draw(HDC hdc, int height, int width);
	void Update(float time);

};

