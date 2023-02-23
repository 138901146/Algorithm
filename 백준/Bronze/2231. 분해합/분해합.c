#include<stdio.h>

int main(void)
{
	int N, M=0;

	scanf("%d", &N);

	for(int i=1;i<N;i++)
	{
		int temp=i, div=i;

		while(div>0)
		{
			temp+=div%10;
			div/=10;
		}

		if(temp==N)
		{
			M=i;
			break;
		}
	}

	printf("%d\n", M);

	return 0;
}