#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[1000000]={'\0', }, character;
	int N, alphabet[26]={0, }, pri=-1, sec=-1;

	fgets(word,sizeof(word),stdin);
	N=strlen(word);

	for(int i=0;i<N;i++)
		alphabet[word[i]>='a'?word[i]-'a':word[i]-'A']++;

	for(int i=0;i<26;i++)
		if(alphabet[i]>pri)
		{
			pri=alphabet[i];
			character='A'+i;
		}
		else if(alphabet[i]>sec)
			sec=alphabet[i];

	printf("%c\n", pri==sec?'?':character);

	return 0;
}