#include<stdio.h>

int main(void)
{
	int side[3];

	for(int i=0;i<3;i++)
		scanf("%d", &side[i]);

	while(side[0]!=0 || side[1]!=0 || side[2]!=0)
	{
		for(int i=0;i<2;i++)
			for(int j=i+1;j<3;j++)
				if(side[i]>side[j])
				{
					int temp=side[i];
					side[i]=side[j];
					side[j]=temp;
				}

		if(side[0]==side[1] && side[1]==side[2])
			printf("Equilateral\n");
		else if(side[0]+side[1]<=side[2])
			printf("Invalid\n");
		else if(side[0]==side[1] || side[1]==side[2])
			printf("Isosceles\n");
		else
			printf("Scalene\n");

		for(int i=0;i<3;i++)
			scanf("%d", &side[i]);
	}

	return 0;
}