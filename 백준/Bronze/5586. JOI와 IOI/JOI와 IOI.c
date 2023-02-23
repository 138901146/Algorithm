#include<stdio.h>
#include<string.h>

int main(void)
{
	int JOI=0, IOI=0;
	char alphabet[10001]={'\0', };

	scanf("%s", alphabet);

	for(int i=0;i<strlen(alphabet)-2;i++)
	{
		JOI+=alphabet[i]=='J'&&alphabet[i+1]=='O'&&alphabet[i+2]=='I';
		IOI+=alphabet[i]=='I'&&alphabet[i+1]=='O'&&alphabet[i+2]=='I';
	}

	printf("%d\n%d\n", JOI, IOI);

	return 0;
}