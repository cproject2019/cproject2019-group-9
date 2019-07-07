#pragma once

#include<graphics.h>
#include<conio.h>
#include<easyx.h>


//一开始的图片
void inputPicture1()
{
	IMAGE img;

	//加载图片
	loadimage(&img, _T("D:\\JLU.jpg"));
	putimage(0, 0, &img);
	getchar();
}

//第二张图片
void inputPicture2()
{
	IMAGE img;

	//加载图片
	loadimage(&img, _T("D:\\FD.jpg"));
	putimage(0, 0, &img);
}

//第三张图片
void inputPicture3()
{
	IMAGE img;

	//加载图片
	loadimage(&img, _T("D:\\FD1.jpg"));
	putimage(0, 0, &img);
}


//鼠标选择
void selectFunction()
{
	fillroundrect(170, 150, 370, 250, 70, 60);//画选项的框
	setbkmode(TRANSPARENT); // 设置文字背景为透明色
	TCHAR s1[] = _T("inquire information");//给框里面加字
	settextcolor(BLACK);//字的颜色

	LOGFONT f;
	gettextstyle(&f);//获取当前字体设置
	f.lfHeight = 24;//字号
	_tcscpy_s(f.lfFaceName, _T("ink free"));//字体
	f.lfQuality = ANTIALIASED_QUALITY;//输出效果为抗锯齿
	settextstyle(&f);

	outtextxy(195, 180, s1);//字的位置


	fillroundrect(470, 150, 670, 250, 70, 60);
	setbkmode(TRANSPARENT); // 设置文字背景为透明色
	TCHAR s2[] = _T("shortest path");
	outtextxy(510, 180, s2);


	fillroundrect(170, 450, 370, 550, 70, 60);
	setbkmode(TRANSPARENT); // 设置文字背景为透明色
	TCHAR s3[] = _T("modify information");
	outtextxy(195, 480, s3);


	fillroundrect(470, 450, 670, 550, 70, 60);
	setbkmode(TRANSPARENT); // 设置文字背景为透明色
	TCHAR s4[] = _T("scan all names");
	outtextxy(510, 480, s4);
}