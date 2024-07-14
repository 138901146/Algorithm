#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[21]={0};
	int palindrome=1;

	scanf("%s", str);

	for(int left=0,right=strlen(str)-1;left<right;++left,--right)
		if(str[left]!=str[right])
		{
			palindrome=0;
			break;
		}

	printf("%s", palindrome?"true":"false");
	return 0;
}