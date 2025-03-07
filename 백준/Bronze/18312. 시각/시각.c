#include<stdio.h>

int main(void)
{
	int N, K, count=0;

	scanf("%d%d", &N, &K);

	for(int h=0;h<=N;++h)
	{
		if(h/10==K || h%10==K)
		{
			count+=3600;
			continue;
		}

		for(int m=0;m<60;++m)
		{
			if(m/10==K || m%10==K)
			{
				count+=60;
				continue;
			}

			for(int s=0;s<60;++s)
				if(s/10==K || s%10==K)
					++count;
		}
	}

	printf("%d", count);
	return 0;
}