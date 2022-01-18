#include "GameObject.h"
#include "BitMapManager.h"


void GameObject::init(BitMap* listimage)
{
	m_listImage = listimage;
}

void GameObject::Draw(HDC hdc, int height, int width)
{
	
	 // fire size x50 y 50
	m_listImage[GameObjectImage_FIRE_1].SizeUpDraw(hdc, 500- m_MovePlayerX +50, height -50*2 -100 , 2, 2);



}

bool GameObject::Update(int MovePlayer)
{
	m_MovePlayerX = MovePlayer;


	return true;
}