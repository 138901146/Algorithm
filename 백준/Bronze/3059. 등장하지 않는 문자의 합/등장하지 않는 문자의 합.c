#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		char S[1001]={0};
		int appeared[26]={0}, sum=2015;

		scanf("%s", S);

		for(int i=0;S[i];++i)
			if(!appeared[S[i]-'A'])
			{
				appeared[S[i]-'A']=1;
				sum-=S[i];
			}

		printf("%d\n", sum);
	}

	return 0;
}