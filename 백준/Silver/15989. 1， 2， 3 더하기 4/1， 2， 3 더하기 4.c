#include<stdio.h>

int onetwothree(int n,int three,int two,int count)
{
	if(two>0)
		return onetwothree(n,three,0,count+two);
	else if(three>0)
		return onetwothree(n,three-1,(n-3*(three-1))/2,count+1);
	else
		return count;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int n;

		scanf("%d", &n);

		printf("%d\n", onetwothree(n,n/3,(n-3*(n/3))/2,1));
	}

	return 0;
}