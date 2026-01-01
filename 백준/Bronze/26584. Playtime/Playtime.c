#include<stdio.h>

int main(void)
{
	int games;

	scanf("%d", &games);
	getchar();

	while(games--)
	{
		char str[100]={0}, i;
		int minute=0;

		fgets(str,sizeof(str),stdin);

		for(i=0;str[i]!=',';++i);
		++i;

		while('0'<=str[i]&&str[i]<='9')
		{
			minute*=10;
			minute+=str[i++]-'0';
		}

		for(i=0;str[i]!=',';++i)
			printf("%c", str[i]);
		printf(" -");
		if(525600<=minute)
			printf(" %d year(s)", minute/525600);
		minute%=525600;
		if(1440<=minute)
			printf(" %d day(s)", minute/1440);
		minute%=1440;
		if(60<=minute)
			printf(" %d hour(s)", minute/60);
		minute%=60;
		if(minute)
			printf(" %d minute(s)", minute);
		printf("\n");
	}

	return 0;
}