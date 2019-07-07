#pragma once

#define HEIGHT 66
#define WIDTH 83

#include <iostream>  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<graphics.h>
#include<easyx.h>
#include"Paint.h"

void Information1();

//�������ƣ����ţ����
typedef struct
{
	char name[50];
	char code;
	char introduction[200];
}DataType;

DataType Buildinfo[48];

typedef struct tagQNode 
{
	char x, y;
	int Step;//����õ�Ĳ���  
}QNode;



//��ѯ��������Ϣ
void Information(char scenery[])
{
	FILE* fp;
	fp = fopen("Buildinfo.txt", "r");
	rewind(fp);

	int l;
	char c;
	char a;
	char b;
	for (l = 0; !feof(fp); l++) 
	{
		if (feof(fp))
			break;

		fread(&c, 1, 1, fp);
		int i;	
		for (i = 0; c != '|'&&!feof(fp); i++)
		{
			Buildinfo[l].name[i] = c;
			fread(&c, 1, 1, fp);
		}
		
		fread(&a, 1, 1, fp);
		
		Buildinfo[l].code = a;
		

		fread(&b, 1, 1, fp);

		int k;
		for (k = 0; b != '\n'&&!feof(fp); k++)
		{
			fread(&b, 1, 1, fp);
			
			Buildinfo[l].introduction[k] = b;
		}
	}

	fclose(fp);

	int n;
	for (n = 0; n < 48; n++)
	{
		if (strcmp(Buildinfo[n].name , scenery)==0)
		{
			TCHAR s76[] = _T("The name of building you input is:");
			outtextxy(100, 200, s76);

			int j;
			for (j = 0; (Buildinfo[n].name)[j] != '\0'; j++)
				outtextxy(380 + 10 * j, 200, (Buildinfo[n].name)[j]);


			TCHAR s78[] = _T("The introduction of building you input is:");
			outtextxy(100, 250, s78);

			int d;
			for (d = 0; (Buildinfo[n].introduction)[d] != '\0'; d++)
				outtextxy(450 + 10 * d, 250, (Buildinfo[n].introduction)[d]);
			break;
		}
	}

	
	LOGFONT h;
	gettextstyle(&h);//��ȡ��ǰ��������
	h.lfHeight = 44;//�ֺ�
	settextcolor(BLACK);//�ֵ���ɫ
	settextstyle(&h);

	if (strcmp(Buildinfo[n].name, scenery) != 0)
	{
		TCHAR s101[] = _T("Sorry, the name you input maybe wrong.");
		outtextxy(100, 250, s101);

		TCHAR s102[] = _T("Click enter to input again.");
		outtextxy(100, 350, s102);

		getchar();

		cleardevice();
		inputPicture3();

		LOGFONT f;
		gettextstyle(&f);//��ȡ��ǰ��������
		f.lfHeight = 24;//�ֺ�
		settextcolor(BLACK);//�ֵ���ɫ
		settextstyle(&f);

		Information1();

	}

	getchar();
}

//��ѯ������Ϣ�ĺ���
void Information1()
{
	TCHAR s81[] = _T("Please input the building you want to inquire:");
	outtextxy(100, 100, s81);

	char sceneryname[50];
	int i = 0;
	while (1)
	{
		char a = _getch();
		if (a == 13)//�жϻس���
			break;

		else
		{
			outtextxy(480 + 10 * i, 100, a);
			sceneryname[i] = a;
			i++;
		}
	}
	sceneryname[i] = '\0';

	Information(sceneryname);
}


//�޸ľ�����Ϣ�ĺ���
void Modify()
{
	LOGFONT r;
	gettextstyle(&r);//��ȡ��ǰ��������
	r.lfHeight = 44;//�ֺ�
	_tcscpy_s(r.lfFaceName, _T("ink free"));//����
	settextstyle(&r);

	char sceneryname[50];

	TCHAR s83[] = _T("The name of building you want to modify is:");
	outtextxy(50, 100, s83);

	int j = 0;
	while (1)
	{
		char a = _getch();
		if (a == 13)
			break;
		outtextxy(700 + 30 * j, 100, a);
		sceneryname[j] = a;
		j++;
	}
	sceneryname[j] = '\0';

	LOGFONT h;
	gettextstyle(&h);//��ȡ��ǰ��������
	h.lfHeight = 24;//�ֺ�
	_tcscpy_s(h.lfFaceName, _T("ink free"));//����
	h.lfQuality = ANTIALIASED_QUALITY;//���Ч��Ϊ�����
	settextstyle(&h);

	FILE* fp;
	fp = fopen("Buildinfo.txt", "r");
	rewind(fp);

	int l;
	char c;
	char a;
	char b;
	for (l = 0; !feof(fp); l++)
	{
		if (feof(fp))
			break;

		fread(&c, 1, 1, fp);
		int i;
		for (i = 0; c != '|'&&!feof(fp); i++)
		{
			Buildinfo[l].name[i] = c;
			fread(&c, 1, 1, fp);
		}

		fread(&a, 1, 1, fp);

		Buildinfo[l].code = a;


		fread(&b, 1, 1, fp);

		int k;
		for (k = 0; b != '\n'&&!feof(fp); k++)
		{
			fread(&b, 1, 1, fp);

			Buildinfo[l].introduction[k] = b;
		}
	}

	fclose(fp);

	int n;
	for (n = 0; n < 48; n++)
	{
		if (strcmp(Buildinfo[n].name, sceneryname) == 0)
		{
			TCHAR s76[] = _T("The name of building you input is:");
			outtextxy(100, 200, s76);

			int j;
			for (j = 0; (Buildinfo[n].name)[j] != '\0'; j++)
				outtextxy(380 + 10 * j, 200, (Buildinfo[n].name)[j]);

			TCHAR s77[] = _T("The code of building you input is:");
			outtextxy(100, 250, s76);

			outtextxy(380, 250, Buildinfo[n].code);


			TCHAR s78[] = _T("The introduction of building you input is:");
			outtextxy(100, 300, s78);

			int d;
			for (d = 0; (Buildinfo[n].introduction)[d] != '\0'; d++)
				outtextxy(450 + 10 * d, 300, (Buildinfo[n].introduction)[d]);
			break;
		}
	}

	if (strcmp(Buildinfo[n].name, sceneryname) != 0)
	{
		LOGFONT w;
		gettextstyle(&w);//��ȡ��ǰ��������
		w.lfHeight = 44;//�ֺ�
		settextcolor(BLACK);//�ֵ���ɫ
		settextstyle(&w);

		TCHAR s101[] = _T("Sorry, the name you input maybe wrong.");
		outtextxy(100, 250, s101);

		TCHAR s102[] = _T("Click enter to input again.");
		outtextxy(100, 350, s102);

		getchar();

		cleardevice();
		inputPicture3();

		LOGFONT f;
		gettextstyle(&f);//��ȡ��ǰ��������
		f.lfHeight = 24;//�ֺ�
		settextcolor(BLACK);//�ֵ���ɫ
		settextstyle(&f);

		Modify();

	}

	int e;
	for (e = 0; e < 48; e++) 
	{
		if (strcmp(Buildinfo[e].name, sceneryname) == 0)
		{
			TCHAR s84[] = _T("Which kind of information you want to modify�� a,name;b,code;c,information:");
			outtextxy(100, 400, s84);

			char x;
			x = _getch();

			outtextxy(720, 400, x);

			if (x == 'a')
			{
				TCHAR s85[] = _T("Please input the new name��");
				outtextxy(100, 450, s85);

				int k = 0;

				while (1)
				{
					char d;
					d = _getch();

					if (d == 13)
						break;
					outtextxy(340 + 10 * k, 450, d);
					(Buildinfo[e].name)[k] = d;
					k++;
				}
				(Buildinfo[e].name)[k] = '\0';
			}

			if (x == 'b')
			{
				TCHAR s86[] = _T("Please input the new code��");
				outtextxy(100, 450, s86);

				int d = _getch();

				outtextxy(340, 450, d);
				Buildinfo[e].code = d;
			}

			if (x == 'c')
			{
				TCHAR s87[] = _T("Please input the new introduction��");
				outtextxy(100, 450, s87);

				int k = 0;
				while (1)
				{
					char d = _getch();
					if (d == 13)
						break;
					outtextxy(340 + 10 * k, 450, d);
					(Buildinfo[e].introduction)[k] = d;
					k++;
				}
				(Buildinfo[e].introduction[k]) = '\0';
			}
		}
	}

	
	FILE* gp;
	gp = fopen("Buildinfo.txt", "w");
	rewind(gp);

	int w;

	for (w = 0; w < 48; w++) 
	{
		fwrite(&Buildinfo[w].name, sizeof(Buildinfo[w].name), 1, gp); //���ļ���д������
		fprintf(gp, "|");
		fwrite(&Buildinfo[w].code, sizeof(Buildinfo[w].code), 1, gp); //���ļ���д������
		fprintf(gp, "|");
		fwrite(&Buildinfo[w].introduction, sizeof(Buildinfo[w].introduction), 1, gp); //���ļ���д������
		fprintf(gp, "\n");
	}
	fclose(gp);

	cleardevice();
	inputPicture3();

	LOGFONT g;
	gettextstyle(&g);//��ȡ��ǰ��������
	g.lfHeight = 44;//�ֺ�
	_tcscpy_s(g.lfFaceName, _T("ink free"));//����
	g.lfQuality = ANTIALIASED_QUALITY;//���Ч��Ϊ�����
	settextstyle(&g);

	TCHAR s88[] = _T("You have successfully modified the information.");
	outtextxy(150, 300, s88);

	LOGFONT f;
	gettextstyle(&f);//��ȡ��ǰ��������
	f.lfHeight = 24;//�ֺ�
	_tcscpy_s(f.lfFaceName, _T("ink free"));//����
	f.lfQuality = ANTIALIASED_QUALITY;//���Ч��Ϊ�����
	settextstyle(&f);
}


//������о������Ƶĺ���
void Scan()
{
	FILE* fp;
	fp = fopen("Buildinfo.txt", "r");
	rewind(fp);

	int l;
	char c;
	char a;
	char b;
	for (l = 0; !feof(fp); l++)
	{
		if (feof(fp))
			break;

		fread(&c, 1, 1, fp);
		int i;
		for (i = 0; c != '|'&&!feof(fp); i++)
		{
			Buildinfo[l].name[i] = c;
			fread(&c, 1, 1, fp);
		}

		fread(&a, 1, 1, fp);

		Buildinfo[l].code = a;

		fread(&b, 1, 1, fp);
		int k;
		for (k = 0; b != '\n'&&!feof(fp); k++)
		{
			fread(&b, 1, 1, fp);
			Buildinfo[l].introduction[k] = b;
		}
	}

	fclose(fp);

	int n;
	for (n = 0; n<24; n++) 
	{
		int e;
		for (e = 0; (Buildinfo[n].name)[e] != '\0'; e++)
		{
			outtextxy(100+10*e , 80+20*n, (Buildinfo[n].name)[e]);
		}
	}


	int m;
	for (m = 24; m<48; m++)
	{
		int e;
		for (e = 0; (Buildinfo[m].name)[e] != '\0'; e++)
		{
			outtextxy(500 + 10 * e, 80 + 20 * (m-24), (Buildinfo[m].name)[e]);
		}
	}

	getchar();
}



//��ѯ���·��������Ϣ�ĺ���
void Path1()
{
	TCHAR s81[] = _T("Please input the buildings you want to inquire:");//���뽨������
	outtextxy(100, 100, s81);

	char sceneryname[50];
	int i = 0;
	while (1)
	{
		char a = _getch();
		if (a == 13)//�жϻس���
			break;

		else
		{
			outtextxy(490 + 11 * i, 100, a);
			sceneryname[i] = a;
			i++;
		}
	}
	sceneryname[i] = '\0';

	char sceneryname1[50];
	int j = 0;
	while (1)
	{
		char a = _getch();
		if (a == 13)//�жϻس���
			break;

		else
		{
			outtextxy(490 + 11 * j, 150, a);
			sceneryname1[j] = a;
			j++;
		}
	}
	sceneryname1[j] = '\0';


	FILE* fp;//���ļ������ṹ���鸳ֵ
	fp = fopen("Buildinfo.txt", "r");
	rewind(fp);

	int l;
	char c;
	char a;
	char b;
	for (l = 0; !feof(fp); l++)
	{
		if (feof(fp))
			break;

		fread(&c, 1, 1, fp);
		int i;
		for (i = 0; c != '|'&&!feof(fp); i++)
		{
			Buildinfo[l].name[i] = c;
			fread(&c, 1, 1, fp);
		}

		fread(&a, 1, 1, fp);

		Buildinfo[l].code = a;


		fread(&b, 1, 1, fp);//�˴���ȡһ����|��

		int k;
		for (k = 0; b != '\n'&&!feof(fp); k++)
		{
			fread(&b, 1, 1, fp);

			Buildinfo[l].introduction[k] = b;
		}
	}

	fclose(fp);

	//������������code
	int n;
	char code, code1;
	for (n = 0; n < 48; n++)
	{
		if (strcmp(Buildinfo[n].name, sceneryname) == 0)
		{
			code = Buildinfo[n].code;
			break;
		}
	}

	int m;
	for (m = 0; m < 48; m++)
	{
		if (strcmp(Buildinfo[m].name, sceneryname1) == 0)
		{
			code1 = Buildinfo[m].code;
			break;
		}
	}

	if (strcmp(Buildinfo[n].name, sceneryname) != 0 || strcmp(Buildinfo[m].name, sceneryname1) != 0)
	{
		LOGFONT w;
		gettextstyle(&w);//��ȡ��ǰ��������
		w.lfHeight = 44;//�ֺ�
		settextcolor(BLACK);//�ֵ���ɫ
		settextstyle(&w);

		TCHAR s101[] = _T("Sorry, the names you input maybe wrong.");
		outtextxy(100, 250, s101);

		TCHAR s102[] = _T("Click enter to input again.");
		outtextxy(100, 350, s102);

		getchar();

		cleardevice();
		inputPicture3();

		LOGFONT f;
		gettextstyle(&f);//��ȡ��ǰ��������
		f.lfHeight = 24;//�ֺ�
		settextcolor(BLACK);//�ֵ���ɫ
		settextstyle(&f);

		Path1();
	}


	char** map = NULL; 
	FILE* fpR = fopen("map.txt", "r");

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			fscanf(fpR, "%c", &map[i*5][j*5]);
		}
	}

	
	int namex, namey, name1x, name1y;


	for (int k = 0; k < HEIGHT; k++)//�������
	{
		for (int l = 0; l < WIDTH; l++)
		{
			if (map[k*5][l*5] == code)
			{
				namex = k;
				namey = l;
			}
		}
	}

	for (int i = 0; i < HEIGHT; i++)//�����յ�
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i*5][j*5] == code1)
			{
				name1x = i;
				name1y = j;
			}
		}
	}



	const int numDirections = 4;//ÿһ������һ�������ߵķ���4��  

								//�����ƶ�����(���ҡ��ϡ���)��x��y�����Ӱ��  
								//x���꣺��ֱ����y���꣺ˮƽ����  
	const char dx[numDirections] = { 0,0,-1,1 };
	const char dy[numDirections] = { -1,1,0,0 };

	char path[HEIGHT][WIDTH] = { 0 };//��¼·��  

		
		int num = HEIGHT * WIDTH;
		//��������ģ�����  
		QNode *queue = (QNode *)malloc(num * sizeof(QNode));
		//��ʼ����"�������"  
		queue[0].x = namex;
		queue[0].y = namey;
		queue[0].Step = -1;//�����ʼ��  

		int front = 0, rear = 1;//front-���߲���(��ͷ) rear-�ܹ���·������ (��β)
		while (front != rear)//���в�Ϊ��  
		{
			for (int i = 0; i < numDirections; ++i)
			{
				char nextX, nextY;//��һ��������  
				nextX = queue[front].x + dx[i];
				nextY = queue[front].y + dy[i];
				//�ж���һ���ڵ�ķ�λ
				if (nextX >= 0 && nextX < HEIGHT && nextY >= 0 && nextY < WIDTH && 1 != map[nextX][nextY] && 2 != map[nextX][nextY] && 3 != map[nextX][nextY])
				{
					//Ѱ�ҵ�Ŀ���  
					if (nextX == name1x && nextY == name1y)
					{
						//��ӡ·��  
						path[nextX][nextY] = 6;
						int tempStep = front;
						while (tempStep != -1)//����ͨ��-1�ж���ʼ��
						{
							path[queue[tempStep].x][queue[tempStep].y] = 6;
							tempStep = queue[tempStep].Step;
						}

						

						cleardevice();


						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == 3)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\Red.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}

						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == 2)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\Blue.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}

						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == 0)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\Gray.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}

						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == -1)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\dot.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}

						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == 1)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\Green.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}

						for (int k = 0; k < HEIGHT; k++)
						{
							for (int l = 0; l < WIDTH; l++)
							{
								if (map[k*5][l*5] == 6)
								{
									IMAGE img;

									loadimage(&img, _T("D:\\Yellow.jpg"));
									putimage(l * 5, k * 5, &img);
								}
							}
						}
					}
					
					//����  
					queue[rear].x = nextX;
					queue[rear].y = nextY;
					queue[rear].Step = front;//queue[rear].Step������front������Ե���(queue[rear].x,queue[rear].y)��

					++rear;

					map[nextX*5][nextY*5] = 6;//��Ǵ˵��ѱ�����  (�޸ĵ�ͼ,��ֹ��ͷ)
				}
			}
			++front;//������front�����ĵط�ȫ������,��ʼ����front+1���Ŀ������
					
		
	}

	
}