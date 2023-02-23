#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	long long L, num, hash=0, mul=1;
	char *str=NULL;

	scanf("%lld", &L);
	str=(char *)calloc(L,sizeof(char));
	scanf("%s", str);

	for(long long i=0;i<L;i++)
	{
		num=str[i]-'a'+1;

		num=mul*num;
		num%=1234567891;

		hash+=num;
		hash%=1234567891;

		mul*=31;
		mul%=1234567891;
	}

	printf("%lld\n", hash);
	free(str);
	return 0;
}