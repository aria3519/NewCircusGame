#pragma once
//#include <windows.h>
#include "MainMenu.h"
#include"BitMapManager.h"


class GameManager
{
	// �̱���,
	// �ʱ�ȭ(),
	// ������Ʈ(),
	// ��ο�(),
	// ������(),
private:
	static GameManager* m_instance;
	HWND m_hWnd;
	HDC m_hdc;
	MainMenu m_Main;
	BitMap* m_listImage;
	HDC m_BackDC;
<<<<<<< HEAD
	PlayGame m_playGame;

=======
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba

	int height;
	int width;
	bool playing; 

private:
	GameManager() {}


public:
	 static GameManager* instance()
	{
		if (m_instance == NULL)
		{
			m_instance = new GameManager();
		}
		return m_instance;
	}
public:
	void Init(HWND hWnd);

	void Update(float time); // ������ ������Ʈ 
	void Draw();
	void Release();

	
	HBITMAP CreateDIBSectionRe(HDC hdc, int width, int height);


	BitMap* SetMainMenu();
<<<<<<< HEAD
	BitMap* SetPlayGame();

	void SetPlayGameImage();
=======
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba
	
};



#define GameMgr GameManager::instance() 
