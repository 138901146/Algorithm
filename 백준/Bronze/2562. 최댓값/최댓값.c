#include<stdio.h>

int main(void)
{
	int value[9], max_index=0;

	for(int i=0;i<9;i++)
	{
		scanf("%d", &value[i]);
		max_index=value[i]>value[max_index]?i:max_index;
	}

	printf("%d\n%d\n", value[max_index], max_index+1);

	return 0;
}