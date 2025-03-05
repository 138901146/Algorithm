#include<stdio.h>

long long abs(long long x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, M, min_index;
	long long sx, sy, ex, ey, x, y, cx, cy, route, min=1000000000000;

	scanf("%d", &N);
	scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &M);

		route=0;
		cx=sx;
		cy=sy;

		while(M--)
		{
			scanf("%lld%lld", &x, &y);

			route+=abs(x-cx)+abs(y-cy);
			cx=x;
			cy=y;
		}

		route+=abs(ex-cx)+abs(ey-cy);

		if(route<min)
		{
			min=route;
			min_index=n;
		}
	}

	printf("%d", min_index);
	return 0;
}