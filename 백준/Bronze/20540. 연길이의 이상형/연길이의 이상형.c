#include<stdio.h>

int main(void)
{
	char MBTI[5]={'\0', };

	scanf("%s", MBTI);

	MBTI[0]=MBTI[0]=='E'?'I':'E';
	MBTI[1]=MBTI[1]=='S'?'N':'S';
	MBTI[2]=MBTI[2]=='F'?'T':'F';
	MBTI[3]=MBTI[3]=='P'?'J':'P';

	printf("%s\n", MBTI);
	return 0;
}