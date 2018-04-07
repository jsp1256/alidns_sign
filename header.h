#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "sha1.h"
char s[30][150]; //ȫ���ַ�����

void dictionary_sort(int size);  //�����ֵ�����
void char_process(char *string); //�ַ�������

/**
URL_Encode/Decode
*/
int hex2dec(char c);
char dec2hex(short int c);
void urlencode(char url[],int flag);      //url����
void urldecode(char url[]);      //url����
/**
BASE64_Encode/Decode
*/
int Base64_Encode(unsigned char *t, const unsigned char *f, int dlen);
int Base64_Decode(unsigned char *t, const unsigned char *f, int n);

#endif // HEADER_H_INCLUDED
