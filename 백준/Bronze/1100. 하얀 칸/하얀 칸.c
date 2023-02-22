#include<stdio.h>

int main(void)
{
	int count=0;
	char chess[8][9]={'\0', };

	for(int i=0;i<8;i++)
		scanf("%s", chess[i]);

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			count+=(i+j)%2==0&&chess[i][j]=='F';

	printf("%d\n", count);

	return 0;
}