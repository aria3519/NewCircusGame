#pragma once

#include"Character.h"
#include"Background.h"
#include "GameObject.h"


class PlayGame
{

private:
	Character m_Character;
	Background m_Background;
	GameObject m_GameObject;

	float playerSpeed;
	bool playerLive;
	float totalDistance;


public:
	void Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage,float endingWindowSize);
	void Draw(HDC hdc, int height, int width);
	bool Update(float time);

	void Reset();

};

