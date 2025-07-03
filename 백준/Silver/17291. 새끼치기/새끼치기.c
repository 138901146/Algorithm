#include<stdio.h>

int main(void)
{
	int N, born[21]={0,1,0,}, dead[21]={0,}, alive=0;

	scanf("%d", &N);

	for(int n=1;n<=N;++n)
	{
		for(int i=1;i<n;++i)
			born[n]+=born[i]-dead[i];

		if(3<n && !(n&1))
			dead[n]+=born[n-3]+born[n-4];

		alive+=born[n]-dead[n];
	}

	printf("%d", alive);
	return 0;
}