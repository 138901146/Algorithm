#include<stdio.h>

int main(void)
{
	char letter;
	int count=0;

	for(int i=0;i<6;++i)
	{
		scanf("%c", &letter);
		getchar();
		count+=letter=='W';
	}

	switch(count)
	{
		case 0:
			count=-1;
			break;
		case 1:
		case 2:
			count=3;
			break;
		case 3:
		case 4:
			count=2;
			break;
		case 5:
		case 6:
			count=1;
			break;
	}

	printf("%d", count);
	return 0;
}