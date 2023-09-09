#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n)
{
    char triple[100]={'\0', };
    int i=0;

    while(n>0)
    {
        triple[i++]='0'+n%3;
        n/=3;
    }
    
    for(int i=0;i<strlen(triple);i++)
    {
        n*=3;
        n+=triple[i]-'0';
    }

    return n;
}