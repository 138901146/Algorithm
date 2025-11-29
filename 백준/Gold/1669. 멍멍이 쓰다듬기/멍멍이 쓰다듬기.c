#include<stdio.h>
#include<math.h>

int main(void)
{
	long long X, Y;

	scanf("%lld%lld", &X, &Y);

	Y-=X;
	X=(long long)sqrt(Y-1);

	printf("%lld", Y?(X<<1)+(X*X+X<Y):0);
	return 0;
}