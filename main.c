#include "header.h"
#define MAX_BUFFER 400


/**
用于处理字典排序的函数，并进行URL编码
*/
void dictionary_sort(int size)
{
    if(!size%2)
        printf("ERROR");
    int i=0,j,k;
    char l[100] = {0};
    while (size--)
    {
        for (k = i; k > 0; k--)
        {
            for (j = k - 1; j >= 0; j--)
                if (strcmp(s[j], s[k]) > 0)
                {
                    strcpy(l, s[j]);
                    strcpy(s[j], s[k]);
                    strcpy(s[k], l);
                }
        }
        i++;
    }

    //printf("after sort:\n");
    for (j = 0; j < i; j++){
        urlencode(s[j],1);
        //printf("%s\n", s[j]);
    }
}
/**
用于处理请求字符串，进行URL编码并转换为StringToSign
*/
void char_process(char *string)
{
    int i,j,k,len=strlen(string),s_size;
    char string_tmp[len+90];
    strcpy(string_tmp,string);
    for(i=0;i<len;i++)
        if(string_tmp[i]=='?')
            break;
    for(i=i+1,j=0,k=0;i<len;i++){
        if(string_tmp[i]=='&')
            i++,j++,k=0;
        s[j][k]=string_tmp[i];
        k++;
    }
    dictionary_sort(s_size=j+1);
    strcpy(string,"GET&%2F&");
    for(i=0,j=0;i<MAX_BUFFER&&j<s_size;i++,j++){
        for(k=0;k<strlen(s[j]);k++)
        {
            string_tmp[i++]=s[j][k];
        }
        string_tmp[i]='&';
    }
    string_tmp[--i]='\0';
    urlencode(string_tmp,0);
    strcat(string,string_tmp);
}
int main(int argv,char** argc)
{
    if(argv!=3){
        printf("Usage: alidns String_tocaclute secret&\n");
        return 1;
    }
    unsigned char key[30],string[MAX_BUFFER];
    unsigned char HMACSHA1_out[MAX_BUFFER/2],BASE64_out[MAX_BUFFER];
    int sha1size;
    //拷贝字符串
    strcpy((char*)string,argc[argv-2]);
    strcpy((char*)key,argc[argv-1]);
    //格式化处理字符串并做URL编码
    char_process((char*)string);
    //对编码后的字符串执行哈希散列校验，算法HMAC-SHA1，并将结果进行BASE64编码
    sha1size=hmac_sha(key,strlen((char*)key),string,(int)strlen((char*)string),HMACSHA1_out,MAX_BUFFER/2);
    Base64_Encode(BASE64_out,HMACSHA1_out,sha1size);
    //构造请求字符串，URL编码后输出到标准输出流
    strcpy((char*)string,argc[argv-2]);
    strcat((char*)string,"&Signature=");
    urlencode((char*)BASE64_out,0);
    strcat((char*)string,(char*)BASE64_out);
    printf("%s",string);
    return 0;
}
