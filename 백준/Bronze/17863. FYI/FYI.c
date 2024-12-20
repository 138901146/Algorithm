#include<stdio.h>

int main(void)
{
	char N[8]={0};

	scanf("%s", N);
	printf("%s", N[0]=='5'&&N[1]=='5'&&N[2]=='5'?"YES":"NO");

	return 0;
}