#include<stdio.h>
#include<string.h>

int main(void)
{
	char document[2502]={0}, word[52]={0};
	int document_length, word_length, count=0;

	fgets(document,sizeof(document),stdin);
	fgets(word,sizeof(word),stdin);

	document_length=strlen(document);
	word_length=strlen(word);
	document[--document_length]=0;
	word[--word_length]=0;

	for(int i=0;i+word_length<=document_length;++i)
	{
		int current=0;

		while(current<word_length && word[current]==document[i+current])
			++current;

		if(current==word_length)
		{
			++count;
			i+=word_length-1;
		}
	}

	printf("%d", count);
	return 0;
}