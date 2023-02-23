#include<stdio.h>

int main(void)
{
	int dice[3];

	scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);

	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)
			if(dice[i]>dice[j])
			{
				int temp=dice[i];
				dice[i]=dice[j];
				dice[j]=temp;
			}

	printf("%d\n", dice[0]==dice[2]?(10000+1000*dice[2]):dice[0]==dice[1]||dice[1]==dice[2]?(1000+100*dice[1]):100*dice[2]);

	return 0;
}