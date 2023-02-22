#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, refused=0;
	bool seat[101]={false, };

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int customer;
		scanf("%d", &customer);
		refused+=seat[customer];
		seat[customer]=true;
	}

	printf("%d\n", refused);
	return 0;
}