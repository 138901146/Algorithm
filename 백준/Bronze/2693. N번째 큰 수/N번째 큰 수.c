#include<stdio.h>

int main(void)
{
	int T, arr[10];

	scanf("%d", &T);

	while(T--)
	{
		for(int i=0;i<10;i++)
			scanf("%d", &arr[i]);

		for(int i=0;i<10;i++)
			for(int j=i+1;j<10;j++)
				if(arr[i]<arr[j])
				{
					int temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}

		printf("%d\n", arr[2]);
	}

	return 0;
}