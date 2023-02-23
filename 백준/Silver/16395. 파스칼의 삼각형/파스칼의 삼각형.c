#include<stdio.h>

int main(void)
{
	long double factorial[30]={1.0, };
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i=1;i<n;i++)
		factorial[i]=factorial[i-1]*i;

	n--;
	k--;

	printf("%.0Lf\n", factorial[n]/(factorial[k]*factorial[n-k]));

	return 0;
}