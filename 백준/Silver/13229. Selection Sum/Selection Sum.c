#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, start, end, m, *array=NULL;

	scanf("%d", &n);
	array=(int *)calloc(n+1,sizeof(int));

	for(int i=1;i<=n;++i)
	{
		scanf("%d", &array[i]);
		array[i]+=array[i-1];
	}

	scanf("%d", &m);

	while(m--)
	{
		scanf("%d%d", &start, &end);
		printf("%d\n", array[end+1]-array[start]);
	}

	free(array);
	return 0;
}