#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int K, count=1, number;
	bool sieve[7368788]={false, };

	for(int i=3;i<7368788;i+=2)
		sieve[i]=true;
	for(int i=3;i<7368788;i+=2)
		if(sieve[i])
			for(int j=2*i;j<7368788;j+=i)
				sieve[j]=false;

	scanf("%d", &K);

	if(K==1)
		printf("2\n");
	else
	{
		for(number=3;count<K;number+=2)
			count+=sieve[number];
		printf("%d\n", number-2);
	}
	return 0;
}