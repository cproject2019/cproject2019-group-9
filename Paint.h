#pragma once

#include<graphics.h>
#include<conio.h>
#include<easyx.h>


//һ��ʼ��ͼƬ
void inputPicture1()
{
	IMAGE img;

	//����ͼƬ
	loadimage(&img, _T("D:\\JLU.jpg"));
	putimage(0, 0, &img);
	getchar();
}

//�ڶ���ͼƬ
void inputPicture2()
{
	IMAGE img;

	//����ͼƬ
	loadimage(&img, _T("D:\\FD.jpg"));
	putimage(0, 0, &img);
}

//������ͼƬ
void inputPicture3()
{
	IMAGE img;

	//����ͼƬ
	loadimage(&img, _T("D:\\FD1.jpg"));
	putimage(0, 0, &img);
}


//���ѡ��
void selectFunction()
{
	fillroundrect(170, 150, 370, 250, 70, 60);//��ѡ��Ŀ�
	setbkmode(TRANSPARENT); // �������ֱ���Ϊ͸��ɫ
	TCHAR s1[] = _T("inquire information");//�����������
	settextcolor(BLACK);//�ֵ���ɫ

	LOGFONT f;
	gettextstyle(&f);//��ȡ��ǰ��������
	f.lfHeight = 24;//�ֺ�
	_tcscpy_s(f.lfFaceName, _T("ink free"));//����
	f.lfQuality = ANTIALIASED_QUALITY;//���Ч��Ϊ�����
	settextstyle(&f);

	outtextxy(195, 180, s1);//�ֵ�λ��


	fillroundrect(470, 150, 670, 250, 70, 60);
	setbkmode(TRANSPARENT); // �������ֱ���Ϊ͸��ɫ
	TCHAR s2[] = _T("shortest path");
	outtextxy(510, 180, s2);


	fillroundrect(170, 450, 370, 550, 70, 60);
	setbkmode(TRANSPARENT); // �������ֱ���Ϊ͸��ɫ
	TCHAR s3[] = _T("modify information");
	outtextxy(195, 480, s3);


	fillroundrect(470, 450, 670, 550, 70, 60);
	setbkmode(TRANSPARENT); // �������ֱ���Ϊ͸��ɫ
	TCHAR s4[] = _T("scan all names");
	outtextxy(510, 480, s4);
}