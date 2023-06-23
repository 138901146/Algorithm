#include<stdio.h>

int main(void)
{
	int dwarf[9], difference=-100, fake[2]={-1,-1};

	for(int i=0;i<9;i++)
	{
		scanf("%d", &dwarf[i]);
		difference+=dwarf[i];
	}

	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(dwarf[i]>dwarf[j])
			{
				int temp=dwarf[i];
				dwarf[i]=dwarf[j];
				dwarf[j]=temp;
			}

	for(int i=0;i<9&&fake[0]==-1;i++)
		for(int j=i+1;j<9;j++)
			if(dwarf[i]+dwarf[j]==difference)
			{
				fake[0]=i;
				fake[1]=j;
				break;
			}

	for(int i=0;i<9;i++)
		if(i!=fake[0] && i!=fake[1])
			printf("%d\n", dwarf[i]);

	return 0;
}