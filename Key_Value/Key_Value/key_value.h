
#ifndef KEY_VALUE_H
#define KEY_VALUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//打印界面选项
int print_interface();

//读取配置文件
int read_conf(char *conf_path);

//根据Key来读取key 的 value的值；
int read_val_conf(char *conf_path, char *key, char *value);

//写入配置文件，一次写入一行；
int write_conf(char *conf_path, char *key, char *value);

int choice1();
int choice2();
int choice3();













#endif