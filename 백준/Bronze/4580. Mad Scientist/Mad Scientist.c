#include<stdio.h>

int main(void)
{
	int k;

	scanf("%d", &k);

	while(k)
	{
		int data[2]={0}, current=0, previous=1;

		for(int i=1;i<=k;++i,current^=1,previous^=1)
		{
			scanf("%d", &data[current]);
			for(int j=data[previous];j<data[current];++j)
				printf("%d ", i);
		}

		printf("\n");
		scanf("%d", &k);
	}

	return 0;
}