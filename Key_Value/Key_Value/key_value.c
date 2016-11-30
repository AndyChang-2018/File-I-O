#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ConfPt "c:\\myconfig.ini"
#define MAXLEN 40

int print_interface()
{
	printf("************�ļ����ó���*************\n");
	printf("|                                   |\n");
	printf("|          1,�鿴�����ļ�           |\n");
	printf("|          2,��KEY��ֵ              |\n");
	printf("|          3,д�������ļ���          |\n");
	printf("|          4,�˳�                   |\n");
	printf("|                                   |\n");
	printf("*************************************\n");
	return 0;
}

//��ȡ�����ļ�
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

	//�ر��ļ���
	if ((fclose(pf_conf) != 0))
	{
		fprintf(stderr, "Error in closing files \n");
		exit(4);
	}

	return 0;
}

//����Key����ȡkey �� value��ֵ��
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



	while ((fgets(temp, 100, pf_conf)) != NULL)   //����һ��
	{
		if (strstr(temp , key) == NULL)          // �ж��Ƿ����
		{
			continue;
		}

		flag = 1;
		char *ptemp = NULL;
		if ((ptemp = strchr(temp , '=')) == NULL)  //���ҡ�=����������ָ��
		{
			fprintf(stderr, "û�м�ֵ��");
		}
		else
		{
			while (*++ptemp != '\n')
			{
				*value++ = *ptemp;               //��ֵ
			}
		}

	}


	//�ر��ļ���
	if ((fclose(pf_conf) != 0))
	{
		fprintf(stderr, "Error in closing files \n");
		exit(4);
	}

	if (flag == 0)
	{
		printf("û���ҵ�key����\n");
		return -1;
	}



	return 0;
}

//���ж����ļ�
//�����Ƿ���ڼ�����������ж�VALUEֵ�Ƿ���ȣ��������ȣ���׷��key = value

//д�������ļ�
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

	while ((fgets(array[line++], 100, pf_conf)) != NULL)   //����һ��
	{
		
		if (strstr(array[line-1], key) == NULL)          // �ж��Ƿ����
		{
			continue;
		}

		flag = 1;

		if (strstr(array[line - 1], value) != NULL) 
		{
			printf("��%d�У�", line );
			fprintf(stderr, "�Ѿ����ù��ˣ�");
			printf("\n");
			return -1;
		}
		else
		{
			char *ptemp = NULL;
			if ((ptemp = strchr(array[line - 1], '=')) == NULL)  //���ҡ�=����������ָ��
			{
				fprintf(stderr, "û�м�ֵ��");
			}
			else
			{
				while ( *value != '\0')
				{
					*++ptemp = *value++;               //��ֵ
				}
				*(ptemp) = '\n';
				*(ptemp+1) = '\0';
			}
		}

	}
	if (flag == 0)
	{
		fprintf(pf_conf, "%s =%s\n", key, value);
		//�ر��ļ���
		if ((fclose(pf_conf) != 0))
		{
			fprintf(stderr, "Error in closing files \n");
			exit(4);
		}
	}
	else
	{
		//�ر��ļ���
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


		//�ر��ļ���
		if ((fclose(pf_conf) != 0))
		{
			fprintf(stderr, "Error in closing files \n");
			exit(4);
		}

	}
	


	return 0;
}

//�ַ�������
int digstr(char *config, char *key2, char *value2)
{
	char *key = key2;
	char *value = value2;
	char *temp = config;
	char *flag = NULL;
	if ((flag = strchr(config, '=')) == NULL)
	{
		printf("�����ʽ���󣡸�ʽ�� key = value\n");
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


//��ȡ�����ļ�
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


//��ȡkey��ֵ
int choice2()
{
	int ret = 0;
	char key[MAXLEN] = { 0 };
	char value[MAXLEN] = { 0 };
	printf("Enter your key: ");
	scanf("%s", key);                    //����key��ֵ

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

//д�������ļ�
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