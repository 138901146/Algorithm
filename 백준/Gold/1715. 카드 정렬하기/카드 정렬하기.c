#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *card=(int *)calloc(1001,sizeof(int)), N, num, pri=1, sec, sum=0;
	long long count=0;

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%d", &num);
		card[num]++;
		sum+=num;
	}

	card=realloc(card,(sum+1)*sizeof(int));
	for(int n=1;n<N;n++)
	{
		while(card[pri]==0)
			pri++;

		sec=pri;
		if(card[pri]==1)
		{
			sec++;
			while(card[sec]==0)
				sec++;
		}

		count+=pri+sec;
		card[pri+sec]++;
		card[pri]--;
		card[sec]--;

		pri=sec;
	}

	printf("%lld\n", count);
	free(card);
	return 0;
}