#pragma once

#define MaxVertices 50//建筑的最大数

#include <stdio.h>
#include <stdlib.h>
#include"Operation.h"

void write()
{
	FILE *fp;
	fp = fopen("Buildinfo.txt", "w"); 
	rewind(fp);

	Buildinfo[0] = { "Dingxin building",'a', "Library, offices of many teachers and student affairs hall." };
	Buildinfo[1] = { "Lisiguang building",'b', "has many computers and laboratories." };
	Buildinfo[2] = { "Roller skate rink",'c', "place for roller skating." };
	Buildinfo[3] = { "Football field",'d', "place for playing football." };
	Buildinfo[4] = { "Qing Lake",'e', "a big lake with swans and ducks." };
	Buildinfo[5] = { "Qing Lake basketball court",'f', "place for playing football." };
	Buildinfo[6] = { "Jingxin building",'g', "teaching building, the special place for TAQ and KYM students." };
	Buildinfo[7] = { "Hupan dining hall",'h', "place for meals." };
	Buildinfo[8] = { "Nanyuan apartment",'r', "dormitories for girls." };
	Buildinfo[9] = { "Shenziyuan dining hall",'j', "place for meals." };
	Buildinfo[10] = { "Rixin Building",'k', "shopping center, swimming pool, cinema, restaurants, Internet bar." };
	Buildinfo[11] = { "Playground",'l', "place for running and sports meeting." };
	Buildinfo[12] = { "Tianjiabing student center",'m', "a little hall for activities." };
	Buildinfo[13] = { "Tennis court",'n', "place for playing tennis." };
	Buildinfo[14] = { "Beiyuan apartment",'p', "dormitories for boys." };
	Buildinfo[15] = { "Wenyuan apartment",'q', "dormitories for boys and girls." };
	Buildinfo[16] = { "Gym",'s', "place for different sports." };
	Buildinfo[17] = { "Administrative building",'t', "place for conferences." };
	Buildinfo[18] = { "Yifu library",'u', "place for reading books and study." };
	Buildinfo[19] = { "Music hall",'v', "place for watching music plays." };
	Buildinfo[20] = { "Foreign Languages building",'w', "teaching building and the center of foreign languages college." };
	Buildinfo[21] = { "Laboratory building",'x', "place for experimenting." };
	Buildinfo[22] = { "Art college",'y', "the center of art college." };
	Buildinfo[23] = { "Yifu building",'z', "teaching building." };
	Buildinfo[24] = { "Administrative building basketball court",'A', "place for playing basketball." };
	Buildinfo[25] = { "Kuangyaming building",'B', "the center of kuangyaming class students." };
	Buildinfo[26] = { "Parking lot",'C', "place for parking." };
	Buildinfo[27] = { "Software college",'D', "the center of software college." };
	Buildinfo[28] = { "Physics building",'E', "the center of physics college." };
	Buildinfo[29] = { "Electrician building",'F', "the center of electrician." };
	Buildinfo[30] = { "Biology building",'G', "the center of biology college." };
	Buildinfo[31] = { "Tangaoqing building",'H', "places which has many laboratories." };
	Buildinfo[32] = { "May flower square",'I', "a big square which has fountain." };
	Buildinfo[33] = { "Central library",'J', "place for reading books and studying." };
	Buildinfo[34] = { "Dongrong conference center",'K', "place for speeches and conferences." };
	Buildinfo[35] = { "The third teaching building",'L', "teaching building." };
	Buildinfo[36] = { "Jida supermarket",'M', "a supermarket besides western gate." };
	Buildinfo[37] = { "Shopping center",'N', "place for shopping." };
	Buildinfo[38] = { "School hospital",'O', "place for students to seeing a doctor." };
	Buildinfo[39] = { "Youyi gulid hall",'P', "a hotel near JLU." };
	Buildinfo[40] = { "Supermolecule building",'Q', "place which has national laboratories." };
	Buildinfo[41] = { "Yan Lake",'R', "a lake which is smaller than Qing lake." };
	Buildinfo[42] = { "Mathmatics building",'S', "national tianyuan mathematics northeast center and mathematical laboratories." };
	Buildinfo[43] = { "Western gate",'T', "a gate near Sanjiahu park." };
	Buildinfo[44] = { "Little western gate",'U', "a gate which has fewer students than Western gate." };
	Buildinfo[45] = { "Northern gate",'V', "a gate near Jida supermarket." };
	Buildinfo[46] = { "Eastern gate",'W', "the biggest door in JLU." };
	Buildinfo[47] = { "Beiyuan basketball court",'o', "place for playing basketball." };

	int i;
	for (i = 0; i < 48; i++)
	{
		fwrite(&Buildinfo[i].name, sizeof(Buildinfo[i].name), 1, fp); //向文件中写入数据
		fprintf(fp, "|");

		fwrite(&Buildinfo[i].code, sizeof(Buildinfo[i].code), 1, fp); //向文件中写入数据
		fprintf(fp, "|");

		fwrite(&Buildinfo[i].introduction, sizeof(Buildinfo[i].introduction), 1, fp); //向文件中写入数据
		fprintf(fp, "\n");
	}

	fclose(fp);

	return;
}
