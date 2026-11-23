#include<stdio.h>

int main(void)
{
	int n, sheet[10000], end[12];
	char letter[12]="AXBCXDXEFXGX";

	scanf("%d", &n);

	for(int i=0;i<n;++i)
		scanf("%d", &sheet[i]);

	for(int i=0;i<12;++i)
	{
		end[i]=-1;

		if(letter[i]=='X')
			continue;

		int current=i, terminatable=1;


		for(int j=0;j<n;++j)
		{
			current=(current+sheet[j]+24)%12;

			if(letter[current]=='X')
			{
				terminatable=0;
				break;
			}
		}

		if(terminatable)
			end[i]=current;
	}

	for(int i=0;i<12;++i)
		if(letter[i]!='X'&&end[i]!=-1)
			printf("%c %c\n", letter[i], letter[end[i]]);
	return 0;
}