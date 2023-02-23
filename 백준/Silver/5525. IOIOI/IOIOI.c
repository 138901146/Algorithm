#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, len=0, count=0;
	char *S=NULL;

	scanf("%d", &N);
	scanf("%d", &M);
	S=(char *)calloc(M+1,sizeof(char));

	scanf("%s", S);

	for(int i=2;i<M;i++)
		if(S[i]=='I')
		{
			if(S[i-1]=='O' && S[i-2]=='I')
			{
				len++;
				if(len>=N)
					count++;
			}
			else
				len=0;
		}

	printf("%d\n", count);
	free(S);
	return 0;
}