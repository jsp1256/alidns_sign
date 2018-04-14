#include "header.h"

int cmp(const void *str1,const void *str2){return strcmp((char*)str1,(char*)str2);}

void dictionary_sort (char s[][CHAR_SIZE],int size,int size2)
{
    qsort(s,size,size2,cmp);
    int i;
    for (i = 0; i < size; i++)
        urlencode(s[i],1);
}
