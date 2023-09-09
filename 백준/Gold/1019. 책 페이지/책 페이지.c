#include<stdio.h>

int main(void)
{
	int N, count[10]={0, }, add=0;

	scanf("%d", &N);

	for(int i=1;N;i*=10)
	{
		int last=N%10;
		N/=10;

		count[0]-=i;
		for(int j=0;j<10;++j)
		{
			count[j]+=N*i;
			if(j<last)
				count[j]+=i;
			else if(j==last)
				count[j]+=add+1;
		}

		add+=last*i;
	}

	for(int i=0;i<10;++i)
		printf("%d ", count[i]);
	return 0;
}