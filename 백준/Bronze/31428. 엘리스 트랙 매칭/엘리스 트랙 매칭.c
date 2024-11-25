#include<stdio.h>

int main(void)
{
	int N, count[4]={0};
	char track;

	scanf("%d", &N);
	getchar();

	while(N--)
	{
		scanf("%c", &track);
		getchar();

		switch(track)
		{
			case 'C':
				count[0]++;
				break;
			case 'S':
				count[1]++;
				break;
			case 'I':
				count[2]++;
				break;
			case 'A':
				count[3]++;
				break;
		}
	}

	scanf("%c", &track);

	switch(track)
	{
		case 'C':
			printf("%d", count[0]);
			break;
		case 'S':
			printf("%d", count[1]);
			break;
		case 'I':
			printf("%d", count[2]);
			break;
		case 'A':
			printf("%d", count[3]);
			break;
	}

	return 0;
}