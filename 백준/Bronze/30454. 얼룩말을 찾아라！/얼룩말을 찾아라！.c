#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, L, max=0, count=0;
	bool zebra[1001]={false};

	scanf("%d%d", &N, &L);

	while(N--)
	{
		int line=0;

		for(int l=1;l<=L;++l)
		{
			scanf("%1d", &zebra[l]);
			if(zebra[l] && !zebra[l-1])
				++line;
		}

		if(line>max)
		{
			max=line;
			count=1;
		}
		else if(line==max)
			++count;
	}

	printf("%d %d", max, count);
	return 0;
}