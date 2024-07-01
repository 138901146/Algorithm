#include<stdio.h>
#include<string.h>

int main(void)
{
	int length_A, length_B;
	char A[10002]={0}, B[10002]={0};

	scanf("%s%s", A, B);

	length_A=strlen(A);
	length_B=strlen(B);

	for(int i=length_A, diff=10001-length_A;0<=i;--i)
		A[diff+i]=A[i];
	for(int i=length_B, diff=10001-length_B;0<=i;--i)
		B[diff+i]=B[i];

	for(int i=10000-length_A;0<=i;--i)
		A[i]='0';
	for(int i=10000-length_B;0<=i;--i)
		B[i]='0';

	for(int i=10001, plus=0;0<=i;--i)
	{
		int a=A[i]-'0', b=B[i]-'0';

		if(9<a+b+plus)
		{
			A[i]=a+b+plus-10+'0';
			plus=1;
		}
		else
		{
			A[i]=a+b+plus+'0';
			plus=0;
		}
	}

	for(int i=0, flag=0;i<10001;++i)
		if(flag)
			printf("%c", A[i]);
		else if(A[i]!='0')
		{
			flag=1;
			printf("%c", A[i]);
		}

	return 0;
}