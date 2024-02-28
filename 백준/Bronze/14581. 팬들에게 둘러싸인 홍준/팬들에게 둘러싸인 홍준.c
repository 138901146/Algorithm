#include<stdio.h>

int main(void)
{
	char id[21]={'\0'};

	scanf("%s", id);

	for(int i=0;i<3;++i)
		printf(":fan:");
	printf("\n");
	printf(":fan::%s::fan:\n", id);
	for(int i=0;i<3;++i)
		printf(":fan:");

	return 0;
}