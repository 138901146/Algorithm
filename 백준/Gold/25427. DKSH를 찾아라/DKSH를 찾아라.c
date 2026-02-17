#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N;
	long long pair[4]={0};
	char *S=NULL;

	scanf("%d", &N);

	S=(char *)calloc(N+1,sizeof(char));

	scanf("%s", S);

	for(int i=0;i<N;++i)
		switch(S[i])
		{
			case 'D':
				++pair[0];
				break;
			case 'K':
				pair[1]+=pair[0];
				break;
			case 'S':
				pair[2]+=pair[1];
				break;
			case 'H':
				pair[3]+=pair[2];
				break;
			default:
				break;
		}

	printf("%lld", pair[3]);
	free(S);
	return 0;
}