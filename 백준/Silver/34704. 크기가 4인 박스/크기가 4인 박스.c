#include<stdio.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int main(void)
{
	int N, amount[5]={0}, a, box=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &a);
		++amount[a];
	}

	box+=amount[4];
	amount[4]=0;

	amount[0]=min(amount[1],amount[3]);
	box+=amount[0];
	amount[1]-=amount[0];
	amount[3]-=amount[0];

	if(amount[3])
	{
		box+=amount[3];
		amount[3]=0;
	}

	box+=(amount[2]-(amount[2]&1))>>1;
	amount[2]&=1;

	if(amount[2])
	{
		amount[0]=min(amount[1],2);
		++box;
		amount[1]-=amount[0];
		amount[2]=0;
	}

	if(amount[1])
	{
		box+=amount[1]>>2;
		if(amount[1]&3)
			++box;
	}

	printf("%d", box);
	return 0;
}