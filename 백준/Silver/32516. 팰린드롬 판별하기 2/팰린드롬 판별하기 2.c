#include<stdio.h>

int main(void)
{
	int N, count=0;
	char T[200001]={0};

	scanf("%d", &N);
	scanf("%s", T);

	for(int i=0;i<N>>1;++i)
		if(T[i]!=T[N-1-i])
		{
			if(T[i]=='?' || T[N-1-i]=='?')
				++count;
			else
			{
				printf("0");
				return 0;
			}
		}
		else if(T[i]=='?' && T[N-1-i]=='?')
			count+=26;

	printf("%d", count);
	return 0;
}