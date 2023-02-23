#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n>0)
	{
		int *number=calloc(2*n+1,sizeof(int)), count=0;

		number[0]=number[1]=1;
		for(int i=2;i<=2*n;i++)
			if(number[i]==0)
				for(int j=2*i;j<=2*n;j+=i)
					number[j]++;

		for(int i=n+1;i<=2*n;i++)
			count+=number[i]==0;

		printf("%d\n", count);

		free(number);
		scanf("%d", &n);
	}

	return 0;
}