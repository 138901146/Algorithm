#include<stdio.h>
#include<string.h>

int main(void)
{
	char S[1001]={0};
	int prefix_sum[1001]={0}, length, max=0;

	scanf("%s", S);

	length=strlen(S);
	for(int i=0;i<length;++i)
		prefix_sum[i+1]=prefix_sum[i]+S[i]-'0';

	for(int i=0;i<=length;++i)
		for(int j=2;i+j<=length;j+=2)
			if(prefix_sum[i+(j>>1)]<<1==prefix_sum[i]+prefix_sum[i+j])
				max=j<max?max:j;

	printf("%d", max);
	return 0;
}