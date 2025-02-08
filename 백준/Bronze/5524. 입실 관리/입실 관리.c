#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		char Si[21]={0};

		scanf("%s", Si);

		for(int i=0;Si[i];++i)
			if('A'<=Si[i] && Si[i]<='Z')
				Si[i]+=32;

		printf("%s\n", Si);
	}

	return 0;
}