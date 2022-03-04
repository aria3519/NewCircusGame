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
	GameObject m_GameObject[20];
	GameObject2 m_GameObject2[20];
	

	float playerSpeed;
	bool playerLive;
	int totalDistance;

	float m_timer;
	float m_interacttTimer;
	float m_dieTimer;
	float m_BonusTimer;


	int m_Score;
	int m_Bonus;
	int m_life;
	




public:
	void Init(BitMap* BackIamge, BitMap* CharImage, BitMap* GMImage);
	void Draw(HDC hdc, int height, int width);
	bool Update(float time);

	void Reset();
	bool InteractCheck();
	
	void Die(HDC hdc, int height, int width);
	

};

