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
		print_interface(); //��ӡ����

		int choice = 0;
		printf("Enter your choice:");
		scanf("%d", &choice);             //��ȡѡ��
		while (choice > 4 || choice < 1)
		{
			printf("����������������룺");
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
