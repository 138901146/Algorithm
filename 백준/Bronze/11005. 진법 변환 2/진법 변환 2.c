#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, B;
	char ans[32]={'\0', };

	scanf("%d %d", &N, &B);

	for(int i=0;N>0;i++)
	{
		ans[i]=N%B>9?N%B+'A'-10:N%B+'0';
		N/=B;
	}

	for(int i=0;i<strlen(ans)/2;i++)
	{
		char temp=ans[i];
		ans[i]=ans[strlen(ans)-1-i];
		ans[strlen(ans)-1-i]=temp;
	}

	printf("%s\n", ans);
	return 0;
}