#include<stdio.h>
#include<string.h>

int main(void)
{
	int count=0;
	char direction[10]={0}, street[10][11]={0};

	do
	{
		scanf("%c", &direction[count]);
		scanf("%s", street[count]);
		getchar();
	}
	while(strcmp(street[count++],"SCHOOL"));

	--count;
	while(count--)
		printf("Turn %s onto %s street.\n", direction[count+1]=='L'?"RIGHT":"LEFT", street[count]);
	printf("Turn %s into your HOME.", direction[0]=='L'?"RIGHT":"LEFT");

	return 0;
}