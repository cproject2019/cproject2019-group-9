#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include"Operation.h"
#include"paint.h"
#include"write.h"
#include<windows.h>
#include<mmsystem.h>    //����У��
#include<easyx.h>
//#include �������·���㷨��ͷ�ļ�

#pragma comment(lib, "winmm.lib")


void main()
{
	PlaySound(TEXT("D:\\JDXG.wav"), NULL, SND_ASYNC | SND_NODEFAULT);//��У��

	initgraph(1048, 640);//��ʼ������
	inputPicture1();//�����һ��ͼƬ

	cleardevice();

	inputPicture2();//����ڶ���ͼƬ
	selectFunction();//��������ѡ��

	MOUSEMSG m;//�������ѡ��
	while (1) 
	{
		m = GetMouseMsg();
		
		if (m.mkLButton)//�ж������������Χ
		{
			if (m.x > 170 && m.x < 370 && m.y>150 && m.y < 250)//��ѯ��Ϣ
			{
				cleardevice();
				inputPicture3();

				Information1();
				
			}

			else if (m.x > 470 && m.x < 670 && m.y>150 && m.y < 250)//���·��
			{
				cleardevice();
				inputPicture3();

				Path1();

				
			}

			else if (m.x > 170 && m.x < 370 && m.y>450 && m.y < 550)//�޸���Ϣ
			{
				cleardevice();
				

				LOGFONT f;
				gettextstyle(&f);//��ȡ��ǰ��������
				f.lfHeight = 44;//�ֺ�
				settextcolor(WHITE);//�ֵ���ɫ
				settextstyle(&f);
				TCHAR s38[] = _T("Please input the passport��");
				outtextxy(100, 100, s38);

				LOGFONT g;
				gettextstyle(&g);//��ȡ��ǰ��������
				g.lfHeight = 54;//�ֺ�
				settextcolor(WHITE);//�ֵ���ɫ
				settextstyle(&g);

				int i[20];
				int m = 0;
				while (1)
				{
					int e = _getch();
					outtextxy(300 + 30 * m, 380, e);
					if (e == 13)
						break;
					outtextxy(300 + 30 * m, 380, e);
					i[m] = e;
					m++;
				}
				i[m] = 13;

				if (i[0] == 'z'&&i[1] == 'l'&&i[2] == 'l'&&i[3] == 'b'&&i[4] == 'z'&&i[5] == 'c'&&i[6] == 'd'&&i[7] == 'x')
				{
					cleardevice();
					inputPicture3();
					LOGFONT h;
					gettextstyle(&h);//��ȡ��ǰ��������
					h.lfHeight = 34;//�ֺ�
					settextcolor(BLACK);//�ֵ���ɫ
					settextstyle(&h);
					Modify();
				}

				else
				{
					cleardevice();
					TCHAR s40[] = _T("Sorry,you cannot add it.");
					outtextxy(200, 100, s40);
				}
				getchar();
			}

			else if (m.x > 470 && m.x < 670 && m.y>450 && m.y < 550)//������н�������
			{
				cleardevice();
				inputPicture3();

				Scan();
				
			}
			break;
		}
	}
}