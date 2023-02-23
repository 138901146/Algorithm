#include<stdio.h>
#include<string.h>

int main(void)
{
	int count=0, i;
	char sentence[1001]={'\0', };

	fgets(sentence,sizeof(sentence),stdin);

	for(i=0;i<strlen(sentence);i++)
		if(sentence[i]=='U')
		{
			count++;
			break;
		}
	for(;i<strlen(sentence);i++)
		if(sentence[i]=='C')
		{
			count++;
			break;
		}
	for(;i<strlen(sentence);i++)
		if(sentence[i]=='P')
		{
			count++;
			break;
		}
	for(;i<strlen(sentence);i++)
		if(sentence[i]=='C')
		{
			count++;
			break;
		}

	printf("I %s UCPC\n", count==4?"love":"hate");
	return 0;
}