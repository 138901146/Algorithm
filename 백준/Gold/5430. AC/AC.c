#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int T;

	scanf("%d", &T);
	getchar();
	for(int t=0;t<T;t++)
	{
		char p[100001]={'\0', };
		int n, left=0, right, *arr=NULL;
		bool reversed=false, error=false;

		scanf("%s", p);
		scanf("%d", &n);
		getchar();
		right=n-1;

		for(int i=0;i<strlen(p);i++)
			if(p[i]=='R')
				reversed=!reversed;
			else
				if(left>right)
				{
					error=true;
					break;
				}
				else if(reversed)
					right--;
				else
					left++;
	
		arr=(int *)malloc(n*sizeof(int));

		if(n==0)
			scanf("[]");
		for(int i=0;i<n;i++)
		{
			if(i==0)
				scanf("[%d", &arr[i]);
			else
				scanf(",%d", &arr[i]);
			if(i==n-1)
				scanf("]");
		}
		getchar();

		if(error)
			printf("error\n");
		else
		{
			printf("[");
			if(reversed)
				for(int i=right;i>=left;i--)
				{
					printf("%d", arr[i]);
					if(i>left)
						printf(",");
				}
			else
				for(int i=left;i<=right;i++)
				{
					printf("%d", arr[i]);
					if(i<right)
						printf(",");
				}
			printf("]\n");
		}
		free(arr);
	}

	return 0;
}