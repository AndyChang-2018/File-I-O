#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ConfPt "c:\\myconfig.ini"
#define MAXLEN 40

int print_interface()
{
	printf("************文件配置程序*************\n");
	printf("|                                   |\n");
	printf("|          1,查看配置文件           |\n");
	printf("|          2,看KEY的值              |\n");
	printf("|          3,写入配置文件查          |\n");
	printf("|          4,退出                   |\n");
	printf("|                                   |\n");
	printf("*************************************\n");
	return 0;
}

//读取配置文件
int read_conf(char *conf_path)
{
	FILE *pf_conf = NULL;
	if ((pf_conf = fopen(conf_path, "r")) == NULL)
	{
		fprintf(stderr, "Could't open the file:%s", conf_path);
		exit(1);
	}

	int ch = 0;
	while ((ch = getc(pf_conf)) != EOF)
	{
		putchar(ch);
	}	

	//关闭文件流
	if ((fclose(pf_conf) != 0))
	{
		fprintf(stderr, "Error in closing files \n");
		exit(4);
	}

	return 0;
}

//根据Key来读取key 的 value的值；
int read_val_conf(char *conf_path, char *key, char *value)
{
	char temp[100] = { 0 };
	int flag = 0;
	FILE *pf_conf = NULL;
	if ((pf_conf = fopen(conf_path, "r")) == NULL)
	{
		fprintf(stderr, "Could't open the file:%s", conf_path);
		exit(1);
	}



	while ((fgets(temp, 100, pf_conf)) != NULL)   //读入一行
	{
		if (strstr(temp , key) == NULL)          // 判断是否键名
		{
			continue;
		}

		flag = 1;
		char *ptemp = NULL;
		if ((ptemp = strchr(temp , '=')) == NULL)  //查找‘=’，并返回指针
		{
			fprintf(stderr, "没有键值！");
		}
		else
		{
			while (*++ptemp != '\n')
			{
				*value++ = *ptemp;               //赋值
			}
		}

	}


	//关闭文件流
	if ((fclose(pf_conf) != 0))
	{
		fprintf(stderr, "Error in closing files \n");
		exit(4);
	}

	if (flag == 0)
	{
		printf("没有找到key键！\n");
		return -1;
	}



	return 0;
}

//按行读入文件
//查找是否存在键名，如果有判断VALUE值是否相等，如果不相等，则追加key = value

//写入配置文件
int write_conf(char *conf_path, char *key, char *value)
{
	char array[256][20] = { 0 };
	int line = 0;
	int flag = 0;

	FILE *pf_conf = NULL;
	if ((pf_conf = fopen(conf_path, "r+")) == NULL)
	{
		fprintf(stderr, "Could't open the file:%s", conf_path);
		exit(1);
	}

	while ((fgets(array[line++], 100, pf_conf)) != NULL)   //读入一行
	{
		
		if (strstr(array[line-1], key) == NULL)          // 判断是否键名
		{
			continue;
		}

		flag = 1;

		if (strstr(array[line - 1], value) != NULL) 
		{
			printf("在%d行，", line );
			fprintf(stderr, "已经设置过了！");
			printf("\n");
			return -1;
		}
		else
		{
			char *ptemp = NULL;
			if ((ptemp = strchr(array[line - 1], '=')) == NULL)  //查找‘=’，并返回指针
			{
				fprintf(stderr, "没有键值！");
			}
			else
			{
				while ( *value != '\0')
				{
					*++ptemp = *value++;               //赋值
				}
				*(ptemp) = '\n';
				*(ptemp+1) = '\0';
			}
		}

	}
	if (flag == 0)
	{
		fprintf(pf_conf, "%s =%s\n", key, value);
		//关闭文件流
		if ((fclose(pf_conf) != 0))
		{
			fprintf(stderr, "Error in closing files \n");
			exit(4);
		}
	}
	else
	{
		//关闭文件流
		if ((fclose(pf_conf) != 0))
		{
			fprintf(stderr, "Error in closing files \n");
			exit(4);
		}

		if ((pf_conf = fopen(conf_path, "w+")) == NULL)
		{
			fprintf(stderr, "Could't open the file:%s", conf_path);
			exit(1);
		}

		int count = 0;
		while (count < line - 1)
		{
			fputs(array[count], pf_conf);
			count++;
		}


		//关闭文件流
		if ((fclose(pf_conf) != 0))
		{
			fprintf(stderr, "Error in closing files \n");
			exit(4);
		}

	}
	


	return 0;
}

//字符串分离
int digstr(char *config, char *key2, char *value2)
{
	char *key = key2;
	char *value = value2;
	char *temp = config;
	char *flag = NULL;
	if ((flag = strchr(config, '=')) == NULL)
	{
		printf("输入格式错误！格式： key = value\n");
	}


	while (*temp != *flag)
	{
		*key++ = *temp++;
	}

	while (*(flag + 1) != '\0')
	{
		flag++;
		*value++ = *flag;
	}


	return 0;
}


//读取配置文件
int choice1()
{
	int ret = 0;
	if ((ret = read_conf(ConfPt)) != 0)
	{
		fprintf(stderr, "ERROR: read_conf(pf_conf, key, value)");
		exit(2);
	}
	return 0;
}


//读取key的值
int choice2()
{
	int ret = 0;
	char key[MAXLEN] = { 0 };
	char value[MAXLEN] = { 0 };
	printf("Enter your key: ");
	scanf("%s", key);                    //读入key的值

	if (ret = read_val_conf(ConfPt, key, value))
	{
		return -1;
	}
	fputs(key, stdout);
	printf("=");
	puts(value);
	printf("\n");

	return 0;

}

//写入配置文件
int choice3()
{
	char config[100] = { 0 };
	char key2[10] = { 0 };
	char value2[20] = { 0 };
	printf("Enter your config :");
	fflush(stdin);
	gets(config);
	digstr(config, key2, value2);

	write_conf(ConfPt, key2, value2);
	read_conf(ConfPt);

	return 0;
}