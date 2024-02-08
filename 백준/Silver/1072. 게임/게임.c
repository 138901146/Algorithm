#include<stdio.h>

int main(void)
{
	long long X, Y, Z, left=0, right=1000000000, mid;

	scanf("%lld%lld", &X, &Y);

	Z=Y*100/X;

	if(98<Z)
	{
		printf("-1");
		return 0;
	}

	while(left<right)
	{
		mid=left+right>>1;

		if((Y+mid)*100/(X+mid)==Z)
			left=mid+1;
		else
			right=mid-1;
	}
	mid=left+right>>1;
	mid+=(Y+mid)*100/(X+mid)==Z;

	printf("%lld", mid);
	return 0;
}