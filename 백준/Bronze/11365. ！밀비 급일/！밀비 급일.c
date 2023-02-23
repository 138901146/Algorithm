#include<stdio.h>
#include<string.h>

int main(void)
{
	while(1)
	{
		char note[501]={'\0', };

		fgets(note,sizeof(note),stdin);
		note[strlen(note)-1]='\0';

		if(strcmp(note,"END")==0)
			break;

		for(int i=strlen(note)-1;i>=0;i--)
			printf("%c", note[i]);
		printf("\n");
	}

	return 0;
}