#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;

	scanf("%d", &n);
	getchar();

	while(n--)
	{
		char name[27]={0};
		short g=0, b=0;

		fgets(name,sizeof(name),stdin);

		name[strlen(name)-1]=0;

		for(short i=0;i<strlen(name);++i)
			if(name[i]=='g' || name[i]=='G')
				++g;
			else if(name[i]=='b' || name[i]=='B')
				++b;

		printf("%s is %s\n", name, b<g?"GOOD":g<b?"A BADDY":"NEUTRAL");
	}

	return 0;
}