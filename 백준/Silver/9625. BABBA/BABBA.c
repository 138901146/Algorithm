#include<stdio.h>

int main(void)
{
	int A=1, B=0, K;

 	scanf("%d", &K);

	for(int i=0;i<K;i++)
	{
		int temp=B;
		B+=A;
		A=temp;
	}

	printf("%d %d\n", A, B);

	return 0;
}