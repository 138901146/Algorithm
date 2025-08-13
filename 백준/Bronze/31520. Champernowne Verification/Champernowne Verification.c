#include<stdio.h>
#include<string.h>

int main(void)
{
	int length;
	char n[11]={0};

	scanf("%s", n);
	length=strlen(n);

	if(n[0]!='1')
	{
		printf("-1");
		return 0;
	}

	for(int i=1;i<length;++i)
		if(n[i]-n[i-1]!=1)
		{
			printf("-1");
			return 0;
		}

	printf("%d", length);
	return 0;
}