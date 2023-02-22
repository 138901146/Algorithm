#include<stdio.h>
#include<string.h>

int power10(int x)
{
	int n=1;

	for(int i=0;i<x;i++)
		n*=10;

	return n;
}

int main(void)
{
	int N, alphabet[26]={0, }, sum=0;
	char word[10][9]={'\0', };

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%s", word[n]);
		for(int i=0;i<strlen(word[n])/2;i++)
		{
			char temp=word[n][i];
			word[n][i]=word[n][strlen(word[n])-1-i];
			word[n][strlen(word[n])-1-i]=temp;
		}

		for(int i=0;i<strlen(word[n]);i++)
			alphabet[word[n][i]-'A']+=power10(i);
	}

	for(int i=0;i<25;i++)
		for(int j=i+1;j<26;j++)
			if(alphabet[i]<alphabet[j])
			{
				int temp=alphabet[i];
				alphabet[i]=alphabet[j];
				alphabet[j]=temp;
			}

	for(int i=0,mul=9;alphabet[i]>0;i++,mul--)
		sum+=mul*alphabet[i];

	printf("%d\n", sum);
	return 0;
}