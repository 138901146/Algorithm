#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, alcohol, best=-1;
		char S[21], alcoholic[21];

		scanf("%d", &N);

		getchar();

		while(N--)
		{
			scanf("%s%d", S, &alcohol);
			if(best<alcohol)
			{
				best=alcohol;
				strcpy(alcoholic,S);
			}
		}

		printf("%s\n", alcoholic);
	}

	return 0;
}