#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		char x[21]={'\0', }, y[21]={'\0', };

		scanf("%s %s", x, y);

		printf("Distances: ");
		for(int i=0;i<strlen(x);i++)
			printf("%d ", x[i]>y[i]?y[i]-x[i]+26:y[i]-x[i]);
		printf("\n");
	}

	return 0;
}