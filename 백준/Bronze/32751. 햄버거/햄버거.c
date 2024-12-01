#include<stdio.h>

int main(void)
{
	int N, ingredient[4];
	char recipe[100001]={0}, last=0;

	scanf("%d", &N);
	for(int i=0;i<4;++i)
		scanf("%d", &ingredient[i]);
	scanf("%s", recipe);

	if(recipe[0]!='a' || recipe[N-1]!='a')
	{
		printf("No");
		return 0;
	}

	while(N--)
	{
		if(recipe[N]==last || !ingredient[recipe[N]-'a']--)
		{
			printf("No");
			return 0;
		}

		last=recipe[N];
	}

	printf("Yes");
	return 0;
}