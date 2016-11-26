#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define F_PATH "c:\\1.txt"
#define NAM_LEN 40


//本程序，压缩字符串。只保留每3个字符中的第三个字符来压缩一个文件内容。
int main(int argc, char *argv[])
{
	int ch;
	int count = 0;
	char name[NAM_LEN];
	FILE *fp_in, *fp_out;
	
	//判断参数
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename", argv[0]);
	}

	//打开文件
	if ((fp_in = fopen(argv[1] , "r")) == NULL)
	{
		fprintf(stderr, "Open file error\"%s\"\n", argv[1]);
		exit(2);
	}

	//创建输出文件
	strcpy(name, argv[1]);						//把名字copy到数组中
	strcat(name, ".dat");						//把数组中的文件名加上后缀名。
	if ((fp_out = fopen(name , "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}

	//写入数据
	while ((ch = getc(fp_in)) != EOF)
	{
		if (count++ % 3  == 0)
		{
			putc(ch, fp_out);
		}

	}

	//关闭文件流
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
//	while ((ch = getc(fp)) != EOF) //(ch = getc(fp)) ,少两个括号，导致一直出错。后来不上就正常了。
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
