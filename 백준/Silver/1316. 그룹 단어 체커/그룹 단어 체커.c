#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		char word[101]={'\0', };
		int alphabet[26]={0, }, check=1;

		scanf("%s", word);

		for(int j=1;j<strlen(word);j++)
			if(word[j]!=word[j-1])
			{
				alphabet[word[j-1]-'a']++;

				if(alphabet[word[j]-'a']!=0)
				{
					check=0;
					break;
				}
			}
			count+=check;
	}

	printf("%d\n", count);

	return 0;
}