#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	int N, M, current=0, previous=1, count[26][2], sum=0;

	scanf("%d%d", &N, &M);
	for(int i=0;i<26;++i)
		count[i][0]=1;

	while(--M)
	{
		current^=1;
		previous^=1;
		for(int i=0;i<26;++i)
		{
			count[i][current]=0;
			for(int j=0;j<26;++j)
				if(N<=i-j || N<=j-i)
					count[i][current]=(count[i][current]+count[j][previous])%MOD;
		}
	}

	for(int i=0;i<26;++i)
		sum=(sum+count[i][current])%MOD;

	printf("%d", sum);
	return 0;
}