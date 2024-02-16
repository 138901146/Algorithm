#include<stdio.h>

int main(void)
{
	int N, d, k, c, belt[30000], sushi[3001]={0}, max, count=0;

	scanf("%d%d%d%d", &N, &d, &k, &c);

	for(int i=0;i<k;++i)
	{
		scanf("%d", &belt[i]);

		if(!sushi[belt[i]])
			++count;
		++sushi[belt[i]];
	}
	max=count+(!sushi[c]);

	for(int i=k;i<N;++i)
	{
		scanf("%d", &belt[i]);

		--sushi[belt[i-k]];
		if(!sushi[belt[i-k]])
			--count;

		if(!sushi[belt[i]])
			++count;
		++sushi[belt[i]];

		max=max<count+!sushi[c]?count+!sushi[c]:max;
	}

	for(int i=0;i<k;++i)
	{
		--sushi[belt[N+i-k]];
		if(!sushi[belt[N+i-k]])
			--count;

		if(!sushi[belt[i]])
			++count;
		++sushi[belt[i]];

		max=max<count+!sushi[c]?count+!sushi[c]:max;
	}

	printf("%d", max);
	return 0;
}