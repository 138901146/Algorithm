#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char N[50]={'\0', };
	int B, decimal=0, power=1;

	scanf("%s %d", N, &B);

	for(int i=strlen(N)-1;i>=0;i--)
	{
		if(isdigit(N[i]))
			decimal+=power*(N[i]-'0');
		else
			decimal+=power*(N[i]-'A'+10);

		power*=B;
	}

	printf("%d\n", decimal);
	return 0;
}