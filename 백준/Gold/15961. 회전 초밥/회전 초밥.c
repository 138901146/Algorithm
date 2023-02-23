#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, d, k, c, *plate=NULL, *ate=NULL, max=0, count=0;

	scanf("%d%d%d%d", &N, &d, &k, &c);
	plate=(int *)malloc(N*sizeof(int));
	ate=(int *)calloc(d+1,sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &plate[n]);

	for(int i=0;i<k;i++)
		ate[plate[i]]++;
	ate[c]++;

	for(int i=1;i<=d;i++)
		if(ate[i]>0)
			count++;
	max=count;

	for(int i=1;i<N;i++)
	{
		if(ate[plate[i-1]]==1)
			count--;
		ate[plate[i-1]]--;
		if(ate[plate[(i+k-1)%N]]==0)
		{
			count++;
			if(count>max)
				max=count;
		}
		ate[plate[(i+k-1)%N]]++;
	}

	printf("%d\n", max);
	free(ate);
	free(plate);
	return 0;
}