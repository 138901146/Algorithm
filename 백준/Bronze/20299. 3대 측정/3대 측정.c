#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, L, **VIP=NULL, count=0;

	scanf("%d %d %d", &N, &K, &L);
	VIP=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		VIP[n]=(int *)malloc(4*sizeof(int));

	for(int n=0;n<N;n++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &VIP[n][i]);
		VIP[n][3]=VIP[n][0]>=L&&VIP[n][1]>=L&&VIP[n][2]>=L&&VIP[n][0]+VIP[n][1]+VIP[n][2]>=K;
		count+=VIP[n][3];
	}

	printf("%d\n", count);
	for(int n=0;n<N;n++)
		if(VIP[n][3])
			printf("%d %d %d ", VIP[n][0], VIP[n][1], VIP[n][2]);
	printf("\n");
	for(int n=0;n<N;n++)
		free(VIP[n]);
	free(VIP);
	return 0;
}