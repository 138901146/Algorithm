#include<stdio.h>
#include<stdbool.h>

int abs(int N)
{
	return N>0?N:-N;
}

int main(void)
{
	int N, M, num, hundred, best=999999999, count=0;
	bool normal[10];

	for(int i=0;i<10;i++)
		normal[i]=true;

	scanf("%d", &N);
	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &num);
		normal[num]=false;
	}

	hundred=abs(N-100);

	if(hundred<2 || M==10)
	{
		printf("%d\n", hundred);
		return 0;
	}

	for(int n=0;n<1000000;n++)
	{
		bool able=true;
		count=0;
		num=n;

		if(num==0)
			for(int i=0;i<10;i++)
				if(normal[i])
				{
					count=i+1;
					break;
				}
		while(num>0)
		{
			if(!normal[num%10])
			{
				able=false;
				break;
			}
			count++;
			num/=10;
		}

		if(able)
			best=count+abs(N-n)>best?best:count+abs(N-n);
	}

	printf("%d\n", best>hundred?hundred:best);
	return 0;
}