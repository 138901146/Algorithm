#include<stdio.h>

int main(void)
{
	int num[5], avr=0;

	for(int i=0;i<5;i++)
	{
		scanf("%d", &num[i]);
		avr+=num[i];
	}
	avr/=5;

	for(int i=0;i<4;i++)
		for(int j=i+1;j<5;j++)
			if(num[i]<num[j])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}

	printf("%d\n%d\n", avr, num[2]);

	return 0;
}