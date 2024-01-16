#include<stdio.h>

int main(void)
{
	int a, b, n, w, ans=0;

	scanf("%d%d%d%d", &a, &b, &n, &w);

	for(int i=1;i<n;++i)
		if(a*i+b*(n-i)==w)
		{
			if(ans)
			{
				printf("-1");
				return 0;
			}

			ans=i;
		}

	if(!ans)
		printf("-1");
	else
		printf("%d %d", ans, n-ans);
	return 0;
}