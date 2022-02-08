 #include "Background.h"
#include "BitMapManager.h"


#define MAXBACKGROUND 2

void Background::Init(BitMap* listimage)
{
	m_listImage = listimage;
	m_UIImage[0] = BitMapManager::GetInstance()->GetImage(IMAGE_INTERFACE_1);
	m_UIImage[1] = BitMapManager::GetInstance()->GetImage(IMAGE_INTERFACE_2);
	m_UIImage[2] = BitMapManager::GetInstance()->GetImage(IMAGE_INTERFACE_3);
	flowWall = 1;
	
	m_Background = BackImage_Back3;
	m_fireObject = BackImage_FIRE_1;

	totalEndingX = 10;
	m_count = 0;
	m_ReachEnd = false;
	m_time = 0;
	m_timefire = 0;

	for (int i = 0; i < 10; i++)
		m_fire[i].init();
	m_height = 0;
	
}


void Background::Draw(HDC hdc, int height, int width)
{
	// back 0~3 4
	// back0 Xsize 67 Ysize 183
	 
	
	m_height = height;
	m_UIImage[0]->SizeUpDraw(hdc, 100, 0, 1, 1);
	
	for(int i=0;i<22;i++)// floor
		m_listImage[BackImage_Back1].SizeUpDraw(hdc, i*67  , height - 183*2 , 1, 2); 
	int j = 0;
	if (m_count < MAXBACKGROUND) // ����� �带 ��� 
	{
		j = 0;
		for (int i = 0; i < 22 ; i++) //background
		{
			// Back 2 x 66 y 67
			// Back 3 x65 y 64
			// Back 4 x65 y 64


			if (i % 7 == 0) // �ڳ��� 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
				// ��ֹ� 
				if (i % 2 == 0)
				{
					
					//m_fire[j].update(i, height, flowWall);
					m_fire[j].draw(hdc, height, flowWall, i + 1);
					j++;
					
				}
			}
		}
		// �ؿ� �Ÿ� ǥ�� ��� 
		m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc, width * 1.1f + flowWall, height - 100, 2, 2);
		auto distStr = std::to_string((totalEndingX - m_count) * 100);// �Ÿ� ǥ�� 
		SetTextColor(hdc, RGB(255, 0, 0)); // ���� ���� ���������� ����.
		TextOutA(hdc, width * 1.1f + flowWall + 30, height - 80, distStr.c_str(), distStr.length());
	}
	else if (m_count == MAXBACKGROUND)
	{
		j = 0;
		for (int i = 0; i < 22; i++) //background
		{
			// Back 2 x 66 y 67
			// Back 3 x65 y 64
			// Back 4 x65 y 64


			if (i % 7 == 0) // �ڳ��� 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3 + flowWall, height - 183 * 2 - 64 * 3, 3, 3);
				
				if (i % 2 == 0 && i < 14)
				{
					
					//m_fire[j].update(i, height, flowWall);
					m_fire[j].draw(hdc, height, flowWall, i + 1);
					j++;
				}
			}
		}

		m_listImage[BackImage_INTERFACE_3].SizeUpDraw(hdc, width * 1.0f + flowWall, height - 100, 2, 2);
		auto distStr = std::to_string((totalEndingX - m_count) * 100);// �Ÿ� ǥ�� 
		SetTextColor(hdc, RGB(255, 0, 0)); // ���� ���� ���������� ����.
		TextOutA(hdc, width * 1.0f + flowWall + 30, height - 80, distStr.c_str(), distStr.length());
		
	}
	else // ���������� �� ��� 
	{
		for (int i = 0; i < 14; i++) //background
		{
			if (i % 7 == 0) // �ڳ��� 
			{
				m_listImage[BackImage_Back2].SizeUpDraw(hdc, i * 65 * 3, height - 183 * 2 - 64 * 3, 3, 3);
			}
			else
			{
				m_listImage[m_Background].SizeUpDraw(hdc, i * 65 * 3, height - 183 * 2 - 64 * 3, 3, 3);
			}
		}
		m_listImage[BackImage_GOAL].SizeUpDraw(hdc, width * .85f+30 , height - 220, 2, 2);
	}


}


int Background::Update(float time, float speed, float totalx)
{
	m_time += time;
	
	flowWall -= speed * time;

	for (int i = 0; i < 10; i++)
	{
		m_fire[i].update(time);
		
	}

	//if (0.05f <= m_timefire) // ȭ����ֹ� ������ �ð�����
	//{
	//	m_timefire = 0;
	//	
	//}

	// �� ��ũ�Ѹ� 
	if (flowWall < -(65 * 3 * 14))
	{
		flowWall += (65 * 3 * 14);
		
		
		m_count++;
		
	}
	if (flowWall > 0 && m_count>0)
	{
		flowWall -= (65 * 3 * 14);
		m_count--;
	
	}
	
	if (flowWall > 0 ) // �� �������� 
	{
		flowWall = 1;
		
	}
	if (m_ReachEnd) // ���� ���� ������ 
	{
		if (0.05f <= m_time)
		{
			m_time = 0;
			m_Background++;
	
			if (m_Background > BackImage_Back4)
				m_Background = BackImage_Back3;
		}

	}
	
	
	
	return m_count;
	
}



void Background::Reset()
{

	flowWall = 1;
	m_Background = BackImage_Back3;
	totalEndingX = 10;
	m_count = 0;
	m_ReachEnd = false;
	m_time = 0;
	
	

}


