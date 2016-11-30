#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"key_value.h"


int main()
{


	while (1)
	{
		print_interface(); //打印界面

		int choice = 0;
		printf("Enter your choice:");
		scanf("%d", &choice);             //读取选择
		while (choice > 4 || choice < 1)
		{
			printf("输入错误！请重新输入：");
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:  choice1();
			break;
		case 2:  choice2();
			break;
		case 3:  choice3();
			break;
		case 4: exit(3);
		default:
			exit(3);
		}

	}




	system("pause");
	return 0;
}
