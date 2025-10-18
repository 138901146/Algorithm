#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length;
char str[21], last[21], selected[21];

int compare(const void *x,const void *y)
{
	return *(char *)x<*(char *)y?-1:1;
}

void permutation(int current,int done)
{
	if(current==length)
	{
		printf("%s\n", selected);
		strcpy(last,selected);
		return;
	}

	for(int i=0;i<length;++i)
		if(!((1<<i)&done))
		{
			selected[current]=str[i];
			if(0<strncmp(selected,last,current+1))
				permutation(current+1,1<<i|done);
		}
}

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		memset(str,0,21*sizeof(char));
		memset(last,0,21*sizeof(char));

		scanf("%s", str);

		length=strlen(str);
		qsort((void *)str,(size_t)length,sizeof(char),compare);

		permutation(0,0);
	}

	return 0;
}