#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int diff=0;
		char str[2][101]={0};

		scanf("%s", str[0]);
		scanf("%s", str[1]);

		for(int i=0;str[0][i];++i)
			diff+=str[0][i]!=str[1][i];

		printf("Hamming distance is %d.\n", diff);
	}

	return 0;
}