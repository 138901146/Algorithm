#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int count=0, sum=0, order[20][2]={0, };
	long long k;

	scanf("%lld", &k);

	if(k%2==0)
	{
		order[0][0]=2;
		while(k%2==0)
		{
			order[0][1]++;
			k/=2;
			sum++;
		}
		count++;
	}

	for(long long i=3;i*i<=k;i+=2)
		if(k%i==0)
		{
			order[count][0]=i;
			while(k%i==0)
			{
				order[count][1]++;
				k/=i;
				sum++;
			}
			count++;
		}

	if(k!=1)
		sum++;
	printf("%d\n", sum);
	for(int i=0;i<count;i++)
		for(int j=0;j<order[i][1];j++)
			printf("%d ", order[i][0]);
	if(k!=1)
		printf("%lld", k);
	printf("\n");
	return 0;
}