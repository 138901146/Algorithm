#include<stdio.h>

int main(void)
{
	int N, method[31]={0, };

	scanf("%d", &N);

	if(N%2==0)
	{
		method[2]=3;
		for(int i=4;i<=N;i+=2)
		{
			method[i]+=2;
			method[i]+=3*method[i-2];
			for(int j=4;j<i;j+=2)
				method[i]+=2*method[i-j];
		}
	}

	printf("%d\n", method[N]);
	return 0;
}