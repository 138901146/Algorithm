#include<stdio.h>

int main(void)
{
	int count=0;
	char str[1001]={0};

	scanf("%s", str);

	for(int i=3;str[i];++i)
		if(str[i-3]=='D' && str[i-2]=='K' && str[i-1]=='S' && str[i]=='H')
			++count;

	printf("%d", count);
	return 0;
}