#include<stdio.h>

int main(void)
{
	int id[31]={0, };

	for(int i=0;i<28;i++)
	{
		int n;

		scanf("%d", &n);

		id[n]++;
	}

	for(int i=1;i<=30;i++)
		if(id[i]==0)
			printf("%d\n", i);

	return 0;
}