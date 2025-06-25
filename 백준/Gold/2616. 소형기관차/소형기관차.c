#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int train, capacity, *customer=NULL, **max=NULL;

	scanf("%d", &train);
	customer=(int *)calloc(train+1,sizeof(int));
	max=(int **)malloc((train+1)*sizeof(int *));

	max[0]=(int *)calloc(3,sizeof(int));
	for(int i=1;i<=train;++i)
	{
		max[i]=(int *)calloc(3,sizeof(int));
		scanf("%d", &customer[i]);
		customer[i]+=customer[i-1];
	}

	scanf("%d", &capacity);

	for(int i=capacity;i<=train;++i)
	{
		max[i][0]=customer[i]-customer[i-capacity]<max[i-1][0]?max[i-1][0]:customer[i]-customer[i-capacity];
		for(int j=1;j<3;++j)
			max[i][j]=customer[i]-customer[i-capacity]+max[i-capacity][j-1]<max[i-1][j]?max[i-1][j]:customer[i]-customer[i-capacity]+max[i-capacity][j-1];
	}

	printf("%d", max[train][2]);
	for(int i=0;i<=train;++i)
		free(max[i]);
	free(max);
	free(customer);
	return 0;
}