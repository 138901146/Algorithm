#include<stdio.h>

int main(void)
{
	int v=0, y=0;
	char str[51]={0};

	scanf("%s", str);

	for(int i=0;str[i];++i)
		switch(str[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++v;
			case 'y':
				++y;
		}

	printf("%d %d", v, y);
	return 0;
}