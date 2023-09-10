#include<stdio.h>

int main(void)
{
	unsigned long long N, M, T, S, house=0, studycafe=0;

	scanf("%llu%llu", &N, &M);
	scanf("%llu%llu", &T, &S);

	if(N%8==0)
		house=N+S*((N-1)/8);
	else
		house=N+S*(N/8);
	if(M%8==0)
		studycafe=M+(S+(T<<1))*((M-1)/8)+T;
	else
		studycafe=M+(S+(T<<1))*(M/8)+T;

	if(house<studycafe)
		printf("Zip\n%lld", house);
	else
		printf("Dok\n%lld", studycafe);
	return 0;
}