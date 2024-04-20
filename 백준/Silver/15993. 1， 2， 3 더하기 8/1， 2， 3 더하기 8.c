#include<stdio.h>

unsigned int method[100001][2]={0,0,1,0,1,1,2,2};

int main(void)
{
	int n, T;

	for(int i=4;i<100001;++i)
	{
		method[i][0]=(method[i-1][1]+method[i-2][1]+method[i-3][1])%1000000009;
		method[i][1]=(method[i-1][0]+method[i-2][0]+method[i-3][0])%1000000009;
	}

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);
		printf("%u %u\n", method[n][0], method[n][1]);
	}

	return 0;
}