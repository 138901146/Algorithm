#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	for(int test_case=0;test_case<n;test_case++)
	{
		int p, *price=NULL, expensive_index=0;
		char **C=NULL;

		scanf("%d", &p);
		price=(int *)malloc(p*sizeof(int));
		C=(char **)malloc(p*sizeof(char *));
		for(int c=0;c<p;c++)
			C[c]=(char *)calloc(21,sizeof(char));

		for(int i=0;i<p;i++)
		{
			scanf("%d %s", &price[i], C[i]);
			expensive_index=price[i]>price[expensive_index]?i:expensive_index;
		}

		printf("%s\n", C[expensive_index]);

		for(int c=0;c<p;c++)
			free(C[c]);
		free(C);
		free(price);
	}

	return 0;
}