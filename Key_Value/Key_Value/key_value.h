
#ifndef KEY_VALUE_H
#define KEY_VALUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ӡ����ѡ��
int print_interface();

//��ȡ�����ļ�
int read_conf(char *conf_path);

//����Key����ȡkey �� value��ֵ��
int read_val_conf(char *conf_path, char *key, char *value);

//д�������ļ���һ��д��һ�У�
int write_conf(char *conf_path, char *key, char *value);

int choice1();
int choice2();
int choice3();













#endif