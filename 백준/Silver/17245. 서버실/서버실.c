#include<stdio.h>

int computer[1000][1000];

int main(void)
{
	int N, left=0, right=10000000, mid, answer;
	long long sum=0, half;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &computer[i][j]);
			sum+=computer[i][j];
		}
	half=sum>>1;
	half+=sum&1;

	while(left<=right)
	{
		sum=0;
		mid=(left+right)>>1;

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				sum+=computer[i][j]>mid?mid:computer[i][j];

		if(sum>=half)
		{
			right=mid-1;
			answer=mid;
		}
		else
			left=mid+1;
	}

	printf("%d", answer);
	return 0;
}