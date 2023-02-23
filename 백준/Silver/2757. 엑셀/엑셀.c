#include<stdio.h>
#include<string.h>

int main(void)
{
	int n, m;

	scanf("R%dC%d", &n, &m);

	while(n!=0 || m!=0)
	{
		char C[7]={'\0', };

		for(int i=0;m>0;i++)
		{
			m--;
			C[i]='A'+m%26;
			m/=26;
		}

		for(int i=strlen(C)-1;i>=0;i--)
			printf("%c", C[i]);
		printf("%d\n", n);

		getchar();
		scanf("R%dC%d", &n, &m);
	}

	return 0;
}