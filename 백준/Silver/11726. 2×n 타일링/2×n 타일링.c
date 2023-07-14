#include<stdio.h>

int rectangle[1001]={0, };

int find_2n(int n)
{
	if(n<3)
		return n;
	if(rectangle[n])
		return rectangle[n];
	return rectangle[n]=(find_2n(n-1)+find_2n(n-2))%10007;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d\n", find_2n(n));
	return 0;
}