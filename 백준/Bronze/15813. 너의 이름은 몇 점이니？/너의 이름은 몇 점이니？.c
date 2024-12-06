#include<stdio.h>

int main(void)
{
	int len, score=0;
	char name[101]={0};

	scanf("%d", &len);
	scanf("%s", name);

	while(len--)
		score+=name[len]-'A'+1;

	printf("%d", score);
	return 0;
}