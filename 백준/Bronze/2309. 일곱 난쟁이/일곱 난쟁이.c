#include<stdio.h>

int main(void)
{
	int dwarf[9];

	for(int i=0;i<9;i++)
		scanf("%d", &dwarf[i]);

	for(int i=0;i<8;i++)
	{
		int sum=0;
		for(int j=i+1;j<9;j++)
		{
			sum=0;

			for(int d=0;d<9;d++)
				if(d==i || d==j)
					continue;
				else
					sum+=dwarf[d];
			if(sum==100)
			{
				dwarf[i]=dwarf[j]=0;
				break;
			}
		}

		if(sum==100)
			break;
	}

	for(int i=0;i<8;i++)
		for(int j=i+1;j<9;j++)
			if(dwarf[i]>dwarf[j])
			{
				int temp=dwarf[i];
				dwarf[i]=dwarf[j];
				dwarf[j]=temp;
			}

	for(int i=2;i<9;i++)
		printf("%d\n", dwarf[i]);

	return 0;
}