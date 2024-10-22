#include<stdio.h>

int main(void)
{
	int N;
	char S[11]={0};

	scanf("%d", &N);
	scanf("%s", S);

	for(int i=3;i<N;++i)
		if(S[i-3]=='g' && S[i-2]=='o' && S[i-1]=='r' && S[i]=='i')
		{
			printf("YES");
			return 0;
		}

	printf("NO");
	return 0;
}