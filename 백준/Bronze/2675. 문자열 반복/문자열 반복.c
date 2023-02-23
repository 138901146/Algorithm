#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int R;
		char S[21]={'\0', };

		scanf("%d", &R);
		scanf("%s", S);

		for(int j=0;j<strlen(S);j++)
			for(int k=0;k<R;k++)
				printf("%c", S[j]);
		printf("\n");
	}

	return 0;
}