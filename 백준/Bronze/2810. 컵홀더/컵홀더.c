#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, L_count=0;
	char *seat=NULL;

	scanf("%d", &N);
	seat=(char *)calloc(N+1,sizeof(char));

	scanf("%s", seat);

	for(int i=0;i<N;i++)
		if(seat[i]=='L')
		{
			i++;
			L_count++;
		}

	printf("%d\n", L_count==0?N:N+1-L_count);
	free(seat);
	return 0;
}