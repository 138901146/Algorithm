#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	for(int test_case=0;test_case<t;test_case++)
	{
		char **cloth=NULL, temp[21]={'\0', };
		int n, *num=NULL;
		long long int mul=1;

		scanf("%d", &n);
		num=(int *)calloc(n,sizeof(int));
		cloth=(char **)malloc(n*sizeof(char *));
		for(int i=0;i<n;i++)
		{
			bool same=false;

			cloth[i]=(char *)calloc(21,sizeof(char));
			scanf("%s %s", temp, cloth[i]);

			for(int j=0;j<i;j++)
				if(strcmp(cloth[i],cloth[j])==0)
				{
					same=true;
					num[j]++;
					break;
				}
			if(!same)
				num[i]++;
		}

		for(int i=0;i<n;i++)
			mul*=(num[i]+1);

		printf("%lld\n", mul-1);
		for(int i=0;i<n;i++)
			free(cloth[i]);
		free(cloth);
		free(num);
	}

	return 0;
}