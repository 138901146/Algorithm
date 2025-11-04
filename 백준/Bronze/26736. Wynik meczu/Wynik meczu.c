#include<stdio.h>

char str[100001]={0};

int main(void)
{
	int X=0, Y=0;

	scanf("%s", str);

	for(int i=0;str[i];++i)
		if(str[i]=='A')
			++X;
		else
			++Y;

	printf("%d : %d", X, Y);
	return 0;
}