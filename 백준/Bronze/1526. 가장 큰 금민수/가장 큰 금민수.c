#include<stdio.h>
#include<stdbool.h>

bool gms(int x)
{
	while(x)
	{
		if(x%10!=4 && x%10!=7)
			return false;

		x/=10;
	}

	return true;
}

int main(void)
{
	int N, ans;

	scanf("%d", &N);

	for(int n=N/10;n<=N;++n)
		if(gms(n))
			ans=n;

	printf("%d", ans);
	return 0;
}