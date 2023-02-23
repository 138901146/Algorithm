#include<stdio.h>

int main(void)
{
	int N, price, maxprice=0, dice[4];

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		for(int i=0;i<4;i++)
			scanf("%d", &dice[i]);

		for(int i=0;i<3;i++)
			for(int j=i+1;j<4;j++)
				if(dice[i]>dice[j])
				{
					int temp=dice[i];
					dice[i]=dice[j];
					dice[j]=temp;
				}

		if(dice[0]==dice[3])
			price=50000+dice[0]*5000;
		else if(dice[0]==dice[2] || dice[1]==dice[3])
			price=10000+dice[1]*1000;
		else if(dice[0]==dice[1] && dice[2]==dice[3])
			price=2000+500*(dice[1]+dice[2]);
		else if(dice[0]==dice[1] || dice[1]==dice[2])
			price=1000+dice[1]*100;
		else
			price=100*dice[3]+1000*(dice[2]==dice[3]);

		maxprice=price>maxprice?price:maxprice;
	}

	printf("%d\n", maxprice);
	return 0;
}