#include<stdio.h>

#define MOD 1000000007

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	long long N, menu[5][2], previous=0, current=1, total=0;

	scanf("%lld", &N);

	for(int i=0;i<5;++i)
		menu[i][0]=1;

	while(--N)
	{
		menu[0][current]=0;
		for(int i=1;i<5;++i)
		{
			menu[0][current]=(menu[0][current]+menu[i][previous])%MOD;
			menu[i][current]=menu[0][previous];
			for(int j=1;j<5;++j)
				if(1<abs(i-j))
					menu[i][current]=(menu[i][current]+menu[j][previous])%MOD;
		}
		current^=1;
		previous^=1;
	}

	for(int i=0;i<5;++i)
		total=(total+menu[i][previous])%MOD;
	printf("%lld", total);
	return 0;
}