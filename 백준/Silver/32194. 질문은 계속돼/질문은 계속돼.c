#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *result=NULL, query, x, y;

	scanf("%d", &N);
	result=(int *)malloc((N+2)*sizeof(int));

	result[0]=0;
	result[1]=1;
	for(int n=2;n<N+2;++n)
	{
		scanf("%d%d%d", &query, &x, &y);
		result[n]=result[n-1]+(query==1?result[y]-result[x-1]==y-x+1:result[y]==result[x-1]);
	}

	for(int n=2;n<N+2;++n)
		printf("%s\n", result[n]==result[n-1]?"No":"Yes");
	free(result);
	return 0;
}