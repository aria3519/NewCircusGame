#pragma once

#include"Character.h"
#include"Background.h"
#include "GameObject.h"
#include "ObjectFire.h"


class PlayGame
{

private:
	Character m_Character;
	Background m_Background;
	GameObject m_GameObject;
	GameObject2 m_GameObject2;
	

	float playerSpeed;
	bool playerLive;
	int totalDistance;

	float m_timer;
	int m_Score;
	




public:
	void Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage);
	void Draw(HDC hdc, int height, int width);
	bool Update(float time);

	void Reset();
	bool InteractCheck();
	

};

