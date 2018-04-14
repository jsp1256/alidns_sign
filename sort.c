#include "header.h"

int cmp(const void *str1,const void *str2){return strcmp((char*)str1,(char*)str2);}
/**
*参数:s:传入的一个二维确定的字符数组
*     size:数组一维大小
*/
void dictionary_sort (char s[][CHAR_SIZE],int size)
{
    qsort(s,size,CHAR_SIZE,cmp);
    int i;
    for (i = 0; i < size; i++)
        urlencode(s[i],1);
}
