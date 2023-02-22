#include<stdio.h>
#include<string.h>

int main(void)
{
	char A[10001]={'\0', }, B[10001]={'\0', };
	unsigned long long int mul=0;
	int len_A, len_B;

	scanf("%s", A);
	scanf("%s", B);
	len_A=strlen(A);
	len_B=strlen(B);

	for(int i=0;i<len_A;i++)
	{
		if(A[i]=='0')
			continue;
		for(int j=0;j<len_B;j++)
			mul+=(A[i]-'0')*(B[j]-'0');
	}

	printf("%llu\n", mul);
	return 0;
}