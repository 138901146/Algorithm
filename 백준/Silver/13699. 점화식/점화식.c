#include<stdio.h>

int main(void)
{
	long int t[36]={1,0};
	int n;

	for(int i=1;i<36;i++)
		for(int j=0;j<i;j++)
			t[i]+=t[j]*t[i-j-1];

	scanf("%d", &n);
	printf("%ld\n", t[n]);
	return 0;
}