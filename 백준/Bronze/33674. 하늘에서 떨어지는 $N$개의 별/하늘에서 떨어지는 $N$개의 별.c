#include<stdio.h>

int main(void)
{
	int N, D, K, s[100], star[100]={0}, count=0;

	scanf("%d%d%d", &N, &D, &K);

	for(int i=0;i<N;++i)
		scanf("%d", &s[i]);

	while(D--)
	{
		int clean=0;

		for(int i=0;i<N;++i)
			if(K<star[i]+s[i])
			{
				clean=1;
				break;
			}

		if(clean)
		{
			++count;
			for(int i=0;i<N;++i)
				star[i]=s[i];
		}
		else
			for(int i=0;i<N;++i)
				star[i]+=s[i];
	}

	printf("%d", count);
	return 0;
}