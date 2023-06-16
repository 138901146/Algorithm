#include<stdio.h>

int main(void)
{
	int father, mother, baby;

	scanf("%d", &father);
	scanf("%d", &mother);
	scanf("%d", &baby);

	if(father<mother)
	{
		int temp=father;
		father=mother;
		mother=temp;
	}
	if(father<baby)
	{
		int temp=father;
		father=baby;
		baby=temp;
	}
	if(baby>mother)
	{
		int temp=mother;
		mother=baby;
		baby=temp;
	}

	printf("%d\n", mother);
	return 0;
}