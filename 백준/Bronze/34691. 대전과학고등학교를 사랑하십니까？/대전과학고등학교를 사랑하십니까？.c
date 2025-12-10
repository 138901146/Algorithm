#include<stdio.h>

int main(void)
{
	char str[7]={0};

	scanf("%s", str);

	while(str[0]!='e')
	{
		switch(str[0])
		{
			case 'a':
				printf("Panthera tigris");
				break;
			case 't':
				printf("Pinus densiflora");
				break;
			case 'f':
				printf("Forsythia koreana");
				break;
		}
		printf("\n");
		scanf("%s", str);
	}

	return 0;
}