#include<stdio.h>

int main(void)
{
	int age, weight;
	char name[11]={0};

	scanf("%s%d%d", name, &age, &weight);

	while(name[0]!='#')
	{
		printf("%s %s\n", name, 17<age||80<=weight?"Senior":"Junior");
		scanf("%s%d%d", name, &age, &weight);
	}

	return 0;
}