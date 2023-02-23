#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int dwarf[9], sum=0;
	bool solved=false;

	for(int i=0;i<9;i++)
	{
		scanf("%d", &dwarf[i]);
		sum+=dwarf[i];
	}

	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<9;j++)
			if(sum-dwarf[i]-dwarf[j]==100)
			{
				for(int k=0;k<9;k++)
					if(k!=i && k!=j)
						printf("%d\n", dwarf[k]);
				solved=true;
			break;
			}
		if(solved)
			break;
	}

	return 0;
}