#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	while(N--)
	{
		int palindrome=1;
		char str[1001]={0};

		scanf("%s", str);

		for(int i=0,length=strlen(str);(i<<1)<length;++i)
			if(str[i]!=str[length-i-1])
			{
				palindrome=0;
				break;
			}

		count+=palindrome;
	}

	printf("%d", count*(count-1));
	return 0;
}
