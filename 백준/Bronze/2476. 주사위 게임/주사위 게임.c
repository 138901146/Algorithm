#include<stdio.h>

int main(void)
{
	int N, max_price=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int dice[3], price;

		scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);

		for(int j=0;j<2;j++)
			for(int k=j+1;k<3;k++)
				if(dice[j]>dice[k])
				{
					int temp=dice[j];
					dice[j]=dice[k];
					dice[k]=temp;
				}

		price=dice[0]==dice[2]?(10000+1000*dice[2]):dice[0]==dice[1]||dice[1]==dice[2]?(1000+100*dice[1]):100*dice[2];
		max_price=price>max_price?price:max_price;
	}

	printf("%d\n", max_price);

	return 0;
}