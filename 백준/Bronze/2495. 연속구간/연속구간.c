#include<stdio.h>

int main(void)
{
	for(int t=0;t<3;t++)
	{
		int arr[8], length=1, max=1;

		for(int i=0;i<8;i++)
			scanf("%1d", &arr[i]);
		for(int i=1;i<8;i++)
		{
			length=arr[i]==arr[i-1]?length+1:1;
			max=length>max?length:max;
		}

		printf("%d\n", max);
	}

	return 0;
}