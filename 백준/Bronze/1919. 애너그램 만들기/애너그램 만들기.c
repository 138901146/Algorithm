#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int alphabet[2][26]={0, }, difference=0;

	for(int i=0;i<2;i++)
	{
		char c=getchar();

		while(c!='\n')
		{
			alphabet[i][c-'a']++;
			c=getchar();
		}
	}

	for(int i=0;i<26;i++)
		difference+=abs(alphabet[0][i]-alphabet[1][i]);

	printf("%d\n", difference);

	return 0;
}