#include<stdio.h>

int convert(char *day)
{
	switch(day[0])
	{
		case 'M':
			return 0;
		case 'T':
			return day[1]=='u'?1:3;
		case 'W':
			return 2;
		case 'F':
			return 4;
		default:
			return -1;
	}
}

int main(void)
{
	int T, N, H1, H2, count=0;
	char D1[4]={0}, D2[4]={0};

	scanf("%d%d", &T, &N);

	while(N--)
	{
		scanf("%s%d%s%d", D1, &H1, D2, &H2);

		H1+=24*convert(D1);
		H2+=24*convert(D2);

		count+=H2-H1;
	}

	if(T<=count)
		printf("0");
	else if(count+48<T)
		printf("-1");
	else
		printf("%d", T-count);

	return 0;
}