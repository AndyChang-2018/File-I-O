#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define F_PATH "c:\\1.txt"
#define NAM_LEN 40


//������ѹ���ַ�����ֻ����ÿ3���ַ��еĵ������ַ���ѹ��һ���ļ����ݡ�
int main(int argc, char *argv[])
{
	int ch;
	int count = 0;
	char name[NAM_LEN];
	FILE *fp_in, *fp_out;
	
	//�жϲ���
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename", argv[0]);
	}

	//���ļ�
	if ((fp_in = fopen(argv[1] , "r")) == NULL)
	{
		fprintf(stderr, "Open file error\"%s\"\n", argv[1]);
		exit(2);
	}

	//��������ļ�
	strcpy(name, argv[1]);						//������copy��������
	strcat(name, ".dat");						//�������е��ļ������Ϻ�׺����
	if ((fp_out = fopen(name , "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}

	//д������
	while ((ch = getc(fp_in)) != EOF)
	{
		if (count++ % 3  == 0)
		{
			putc(ch, fp_out);
		}

	}

	//�ر��ļ���
	if ((fclose(fp_in) != 0) || (fclose(fp_out) != 0))
	{
		fprintf(stderr, "Error in closing files \n");
		exit(4);
	}

	system("pause");
	return 0;
}


//int main(int argc , char *argv[])
//{
//	int ch;
//	FILE *fp ;
//	fp = fopen(F_PATH, "r");	
//	while ((ch = getc(fp)) != EOF) //(ch = getc(fp)) ,���������ţ�����һֱ�����������Ͼ������ˡ�
//	{
//		putchar(ch); 
//	}
//
//
//	fclose(fp);
//
//	system("pause");
//	return 0;
//}
