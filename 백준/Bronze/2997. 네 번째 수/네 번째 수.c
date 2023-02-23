#include<stdio.h>

int main(void)
{
	int num[3];

	for(int i=0;i<3;i++)
		scanf("%d", &num[i]);

	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)
			if(num[i]>num[j])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}

	if(2*num[1]>num[0]+num[2])
		printf("%d\n", 2*num[1]-num[2]);
	else if(2*num[1]<num[0]+num[2])
		printf("%d\n", 2*num[1]-num[0]);
	else
		printf("%d\n", 2*num[2]-num[1]);

	return 0;
}