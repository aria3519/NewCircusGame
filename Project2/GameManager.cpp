#include"GameManager.h"


GameManager* GameManager::m_instance = NULL;

void GameManager::Init(HWND hWnd)
{
	
	m_hWnd = hWnd;
	m_hdc = GetDC(m_hWnd);
	m_listImage = BitMapManager::GetInstance()->Init(m_hdc); // 모든 리소스 파일 로드 
	m_Main.Init(SetMainMenu()); // 메인메뉴 셋 리소스 
	SetPlayGameImage(); // playgame image set
	
	


	RECT windowRect;
	GetWindowRect(m_hWnd, &windowRect);
	// window_size
	height = windowRect.bottom - windowRect.top;
	width = windowRect.right - windowRect.left;

	m_BackDC = CreateCompatibleDC(m_hdc);
	
}

void GameManager::Update(float time)
{
	//게임 중이냐 아니냐 switch문 
	switch (playing)
	{
	case false: // 메인 메뉴
		if (m_Main.Update(time) == -1)playing = true;
		break;
	case true: // 게임 플레이 
		if (!m_playGame.Update(time))
		{
			playing = false;
			m_playGame.Reset();
		}
		break;
	}
}

void GameManager::Draw()
{
	HBITMAP backBitmap = CreateDIBSectionRe(m_hdc, width,height);
	HBITMAP oldBack = (HBITMAP)SelectObject(m_BackDC, backBitmap);


	// 업데이트한 내용 대로 backDC에 그리고 적용시키기
	//게임 중이냐 아니냐 switch문 
	switch (playing)
	{
	case false: // 메인 메뉴
		m_Main.Draw(m_BackDC, height, width);
		break;
	case true: // 게임 플레이 
		m_playGame.Draw(m_BackDC, height, width);
		break;
	}


	BitBlt(m_hdc, 0, 0, width, height, m_BackDC, 0, 0, SRCCOPY);
	SelectObject(m_BackDC, oldBack);
	DeleteObject(backBitmap);
}


void GameManager::Release()
{
	DeleteObject(m_BackDC);
	ReleaseDC(m_hWnd, m_hdc);
}



HBITMAP GameManager::CreateDIBSectionRe(HDC hdc, int width, int height) // BackDC 생성 
{
	BITMAPINFO bm_info;
	ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
	bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bm_info.bmiHeader.biBitCount = 24; // 컬러 수(color bits) : 1, 4, 8, 16, 24, 31
	bm_info.bmiHeader.biWidth = width; // 너비.
	bm_info.bmiHeader.biHeight = height;// 높이.
	bm_info.bmiHeader.biPlanes = 1;
	LPVOID pBits;
	return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
}


BitMap* GameManager::SetMainMenu()
{
	// manu 14~18 5
	// point 25
	// point 30~33 4

	int num=0;
	BitMap* tempList = new BitMap[10];
	// manu 14~18 
	for (int i = IMAGE_MENU_1; IMAGE_MENU_5 >= i; i++)
	{
		tempList[num] = m_listImage[i];
		num++;
	}
	// point 25
	tempList[num] = m_listImage[IMAGE_POINT];
	num++;

	// point 30~33
	for (int i = IMAGE_TITLE_1; IMAGE_TITLE_4 >= i; i++)
	{
		tempList[num] = m_listImage[i];
		num++;
	}
	return tempList;
}



void GameManager::SetPlayGameImage()
{
	// back 0~3 4
	// character 19~24 6
	int num = 0;
	BitMap* backList = new BitMap[10];
	BitMap* charList = new BitMap[10];
	BitMap* GMList = new BitMap[10];
	// back 0~3 
	for (int i = IMAGE_BACK_1; IMAGE_BACK_4 >= i; i++)
	{
		backList[num] = m_listImage[i];
		num++;
	}
	// backIMAGE_INTERFACE 9~11 3
	for (int i = IMAGE_INTERFACE_1;IMAGE_INTERFACE_3 >= i; i++)
	{
		backList[num] = m_listImage[i];
		num++;
	}
	// back goal 1
	backList[num] = m_listImage[IMAGE_GOAL];


	num = 0;
	// character 19~24
	for (int i = IMAGE_PLAYER_1; IMAGE_PLAYER_6 >= i; i++)
	{
		charList[num] = m_listImage[i];
		num++;
	}



	// GameObject 6~7 2 , 12~13 2 ,26~29 4
	num = 0;
	for (int i = IMAGE_FIRE_1; IMAGE_FIRE_2 >= i; i++)
	{
		GMList[num] = m_listImage[i];
		num++;
	}
	for (int i = IMAGE_LITTLERING_1; IMAGE_LITTLERING_2 >= i; i++)
	{
		GMList[num] = m_listImage[i];
		num++;
	}
	for (int i = IMAGE_RING_1; IMAGE_RING_4 >= i; i++)
	{
		GMList[num] = m_listImage[i];
		num++;
	}
	m_playGame.Init(backList, charList, GMList);
	
}




