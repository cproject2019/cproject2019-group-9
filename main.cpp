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
#include<mmsystem.h>    //播放校歌
#include<easyx.h>
//#include 含有最短路径算法的头文件

#pragma comment(lib, "winmm.lib")


void main()
{
	PlaySound(TEXT("D:\\JDXG.wav"), NULL, SND_ASYNC | SND_NODEFAULT);//放校歌

	initgraph(1048, 640);//初始化窗口
	inputPicture1();//插入第一张图片

	cleardevice();

	inputPicture2();//插入第二张图片
	selectFunction();//用鼠标进行选择

	MOUSEMSG m;//定义鼠标选择
	while (1) 
	{
		m = GetMouseMsg();
		
		if (m.mkLButton)//判断鼠标左键点击范围
		{
			if (m.x > 170 && m.x < 370 && m.y>150 && m.y < 250)//查询信息
			{
				cleardevice();
				inputPicture3();

				Information1();
				
			}

			else if (m.x > 470 && m.x < 670 && m.y>150 && m.y < 250)//最短路径
			{
				cleardevice();
				inputPicture3();

				Path1();

				
			}

			else if (m.x > 170 && m.x < 370 && m.y>450 && m.y < 550)//修改信息
			{
				cleardevice();
				

				LOGFONT f;
				gettextstyle(&f);//获取当前字体设置
				f.lfHeight = 44;//字号
				settextcolor(WHITE);//字的颜色
				settextstyle(&f);
				TCHAR s38[] = _T("Please input the passport：");
				outtextxy(100, 100, s38);

				LOGFONT g;
				gettextstyle(&g);//获取当前字体设置
				g.lfHeight = 54;//字号
				settextcolor(WHITE);//字的颜色
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
					gettextstyle(&h);//获取当前字体设置
					h.lfHeight = 34;//字号
					settextcolor(BLACK);//字的颜色
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

			else if (m.x > 470 && m.x < 670 && m.y>450 && m.y < 550)//浏览所有建筑名称
			{
				cleardevice();
				inputPicture3();

				Scan();
				
			}
			break;
		}
	}
}