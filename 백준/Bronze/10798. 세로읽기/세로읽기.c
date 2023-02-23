#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[5][16]={'\0', };
	int length[5];

	for(int i=0;i<5;i++)
	{
		scanf("%s", str[i]);
		length[i]=strlen(str[i]);
	}

	for(int i=0;i<15;i++)
		for(int j=0;j<5;j++)
			if(i<length[j])
				printf("%c", str[j][i]);
	printf("\n");
	return 0;
}