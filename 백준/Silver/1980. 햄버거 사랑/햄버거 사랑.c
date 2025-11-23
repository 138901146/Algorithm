#include<stdio.h>

int main(void)
{
	int n, m, t, coke, count;

	scanf("%d%d%d", &n, &m, &t);

	coke=t;
	count=0;

	for(int i=0;i*n<=t;++i)
	{
		int current_coke=(t-i*n)%m, current_count=i+(t-i*n)/m;

		if(current_coke<coke||current_coke==coke&&count<current_count)
		{
			coke=current_coke;
			count=current_count;
		}
	}

	printf("%d %d", count, coke);
	return 0;
}