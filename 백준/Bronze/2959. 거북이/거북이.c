#include<stdio.h>

int main(void)
{
	int turtle[4];

	for(int i=0;i<4;i++)
		scanf("%d", &turtle[i]);

	for(int i=0;i<3;i++)
		for(int j=i+1;j<4;j++)
			if(turtle[i]>turtle[j])
			{
				int temp=turtle[i];
				turtle[i]=turtle[j];
				turtle[j]=temp;
			}

	printf("%d\n", turtle[0]*turtle[2]);
	return 0;
}