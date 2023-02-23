#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int n, *room=NULL, count=0;

		scanf("%d", &n);
		room=(int *)calloc(n+1,sizeof(int));

		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k+=j)
				room[k]++;

		for(int j=1;j<=n;j++)
			count+=room[j]%2;

		free(room);
		printf("%d\n", count);
	}

	return 0;
}