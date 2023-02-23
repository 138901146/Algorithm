#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	bool ascending=true, descending=true;
	int order[8];

	for(int i=0;i<8;i++)
		scanf("%d", &order[i]);

	for(int i=1;i<8;i++)
		if(order[i]>order[i-1])
			descending=false;
		else
			ascending=false;

	if(ascending)
		printf("ascending\n");
	else if(descending)
		printf("descending\n");
	else
		printf("mixed\n");

	return 0;
}