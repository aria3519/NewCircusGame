#pragma once
#include<Windows.h>
#include<string>

class BitMap;

enum MainImage
{
	MainImage_menu1,
	MainImage_menu2,
	MainImage_menu3,
	MainImage_menu4,
	MainImage_menu5,
	MainImage_point,
	MainImage_title1,
	MainImage_title2,
	MainImage_title3,
	MainImage_title4,

};



class MainMenu
{

private:
	/*BitMap* menu[5];
	BitMap* point;
	BitMap* title[4];*/
	// 0~4 menu , 5 point ,6~9 title
	BitMap* m_listImage;
	int pointY;
<<<<<<< HEAD
	float m_time;
	int starIndex;
	
=======
>>>>>>> 4aeb8e3c8212f80ddb854419eaa85ac7a8f2a9ba

public:
	void Init(BitMap* listimage);
	void Draw(HDC hdc,int height, int width);
	void Update(float time);
};

