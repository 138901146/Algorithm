#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *top=NULL, *signal=NULL;

	scanf("%d", &N);
	top=(int *)malloc(N*sizeof(int));
	signal=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &top[n]);

	for(int i=1;i<N;i++)
		if(top[i]<top[i-1])
			signal[i]=i;
		else
		{
			int temp=i;

			while(temp>0)
			{
				temp=signal[temp-1];
				if(temp>0 && top[temp-1]>top[i])
				{
					signal[i]=temp;
					break;
				}
			}
		}

	for(int n=0;n<N;n++)
		printf("%d ", signal[n]);
	printf("\n");
	free(signal);
	free(top);
	return 0;
}