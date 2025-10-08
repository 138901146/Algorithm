#include<stdio.h>

int main(void)
{
	int N, K, current=0, S;
	char alphabet, wheel[26]={0}, exist[26]={0};

	scanf("%d%d", &N, &K);
	while(K--)
	{
		scanf("%d %c", &S, &alphabet);
		current=(current-S+100*N)%N;

		if(wheel[current]&&wheel[current]!=alphabet)
		{
			printf("!");
			return 0;
		}
		else if(wheel[current]!=alphabet&&exist[alphabet-'A'])
		{
			printf("!");
			return 0;
		}

		wheel[current]=alphabet;
		exist[alphabet-'A']=1;
	}

	for(int n=0;n<N;++n)
		printf("%c", wheel[(current+n)%N]?wheel[(current+n)%N]:'?');
	return 0;
}