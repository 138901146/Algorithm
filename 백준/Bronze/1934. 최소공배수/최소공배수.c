#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int A, B, temp;

		scanf("%d %d", &A, &B);

		if(A>B)
		{
			temp=A;
			A=B;
			B=temp;
		}
		temp=B;

		while(temp%A!=0)
			temp+=B;

		printf("%d\n", temp);
	}

	return 0;
}