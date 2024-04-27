#include<stdio.h>

int main(void)
{
	int N, start[100], end[100], work[1001]={0}, total=0, max=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &start[i], &end[i]);

		for(int j=start[i];j<end[i];++j)
		{
			total+=work[j]==0;
			++work[j];
		}
	}

	for(int i=0;i<N;++i)
	{
		int count=0;

		for(int j=start[i];j<end[i];++j)
			count+=1<work[j];

		max=max<total-end[i]+start[i]+count?total-end[i]+start[i]+count:max;
	}

	printf("%d", max);
	return 0;
}