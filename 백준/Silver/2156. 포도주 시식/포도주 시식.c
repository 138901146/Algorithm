#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, *wine=NULL, **maxwine=NULL, max=0;

	scanf("%d", &n);
	wine=(int *)malloc(n*sizeof(int));
	maxwine=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
		maxwine[i]=(int *)calloc(3,sizeof(int));

	for(int i=0;i<n;i++)
	{
		scanf("%d", &wine[i]);

		if(i>0)
		{
			maxwine[i][0]=maxwine[i-1][0]>=maxwine[i-1][1]&&maxwine[i-1][0]>=maxwine[i-1][2]?maxwine[i-1][0]:maxwine[i-1][1]>=maxwine[i-1][0]&&maxwine[i-1][1]>=maxwine[i-1][2]?maxwine[i-1][1]:maxwine[i-1][2];
			maxwine[i][1]=maxwine[i-1][0]+wine[i];
			maxwine[i][2]=maxwine[i-1][1]+wine[i];
		}
		else
			maxwine[0][1]=wine[0];
	}
	max=maxwine[n-1][0]>max?maxwine[n-1][0]:max;
	max=maxwine[n-1][1]>max?maxwine[n-1][1]:max;
	max=maxwine[n-1][2]>max?maxwine[n-1][2]:max;

	printf("%d\n", max);
	for(int i=0;i<n;i++)
		free(maxwine[i]);
	free(maxwine);
	free(wine);
	return 0;
}