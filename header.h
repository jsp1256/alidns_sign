#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "sha1.h"
#define CHAR_SIZE 150

char s[30][CHAR_SIZE]; //全局字符数组

void dictionary_sort (char s[][CHAR_SIZE],int size,int size2);//用于字典排序
void char_process(char *string); //字符处理函数

/**
URL_Encode/Decode
*/
int hex2dec(char c);
char dec2hex(short int c);
void urlencode(char url[],int flag);      //url编码
void urldecode(char url[]);      //url解码
/**
BASE64_Encode/Decode
*/
int Base64_Encode(unsigned char *t, const unsigned char *f, int dlen);
int Base64_Decode(unsigned char *t, const unsigned char *f, int n);

#endif // HEADER_H_INCLUDED
