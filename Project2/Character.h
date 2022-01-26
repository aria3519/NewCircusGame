#pragma once
#include<Windows.h>
#include<string>


class BitMap;

enum CharImage
{
	CharImage_PLAYER_1,
	CharImage_PLAYER_2,
	CharImage_PLAYER_3,
	CharImage_PLAYER_4,
	CharImage_PLAYER_5,
	CharImage_PLAYER_6,

};

class Character
{

private:
	BitMap* m_listImage;
	float m_time;
	int MovingPlayer;
	int PlayerY;

	int jampState;
	float moveSpeed;

	int goCharacter;
	int m_totalX;

public:
	void Init(BitMap* listimage);
	void Draw(HDC hdc, int height, int width);
	float Update(float time , int totalX);
	void Reset();

	void Jamp(float time);
	int GetgoCharacter()
	{
		return goCharacter;
	}
	int GetJampState()
	{
		return jampState;
	}

};

