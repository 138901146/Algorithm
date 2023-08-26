#include<stdio.h>

int main(void)
{
	int N, word[25]={0, }, answer=0, end, flag, all=0;
	char string[101]={'\0', };

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%s", string);

		for(int i=0;string[i]!='\0';i++)
			word[n]|=1<<(string[i]-'a');

		all|=word[n];
	}

	if(all!=67108863)
	{
		printf("0\n");
		return 0;
	}

	end=1<<N;
	while(--end)
	{
		flag=0;

		for(int i=0;i<N && flag<67108863;i++)
			if(end&(1<<i))
				flag|=word[i];

		answer+=flag==67108863;
	}

	printf("%d\n", answer);
	return 0;
}