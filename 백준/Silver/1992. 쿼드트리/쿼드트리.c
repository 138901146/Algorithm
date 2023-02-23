#include<stdio.h>
#include<stdlib.h>

int **quad_tree=NULL;

void print_area(int index,int size)
{
	int x=index/100, y=index%100, count=0;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			count+=quad_tree[x+i][y+j];

	if(count==0)
		printf("0");
	else if(count==size*size)
		printf("1");
	else
	{
		printf("(");
		print_area(100*x+y,size/2);
		print_area(100*x+y+size/2,size/2);
		print_area(100*(x+size/2)+y,size/2);
		print_area(100*(x+size/2)+y+size/2,size/2);
		printf(")");
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	quad_tree=(int **)malloc(N*sizeof(int *));
	for(int i=0;i<N;i++)
	{
		quad_tree[i]=(int *)malloc(N*sizeof(int));

		for(int j=0;j<N;j++)
			scanf("%1d", &quad_tree[i][j]);
	}

	print_area(0,N);
	printf("\n");

	for(int i=0;i<N;i++)
		free(quad_tree[i]);
	free(quad_tree);
	return 0;
}