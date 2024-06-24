#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	getchar();

	while(N--)
	{
		char subject[23]={0};
		scanf("%s", subject);

		switch(subject[0])
		{
			case 'A':
				printf("%d\n", subject[1]=='l'?204:302);
				break;
			case 'D':
				printf("207\n");
				break;
			case 'C':
				printf("B101\n");
				break;
			case 'N':
				printf("303\n");
				break;
			case 'S':
				printf("501\n");
				break;
			default:
				printf("105\n");
				break;
		}
	}

	return 0;
}