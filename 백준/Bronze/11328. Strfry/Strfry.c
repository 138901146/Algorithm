#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		int length, count[26]={0}, possible=1;
		char str[2][1001]={0};

		scanf("%s%s", str[0], str[1]);
		length=strlen(str[0]);

		if(length!=strlen(str[1]))
		{
			printf("Impossible\n");
			continue;
		}

		for(int i=0;i<length;++i)
		{
			++count[str[0][i]-'a'];
			--count[str[1][i]-'a'];
		}

		for(int i=0;i<26;++i)
			if(count[i])
			{
				possible=0;
				break;
			}

		printf("%s\n", possible?"Possible":"Impossible");
	}

	return 0;
}