#include<stdio.h>

int main(void)
{
	int N, a[100], count, ascending;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);

	count=N;
	for(int i=0;i<N-1;++i)
	{
		if(a[i]<a[i+1])
			ascending=1;
		else if(a[i+1]<a[i])
			ascending=0;
		else
			continue;
		for(int j=i+1;j<N;++j,ascending^=1)
			if(ascending)
				if(a[j-1]<a[j])
					++count;
				else
					break;
			else
				if(a[j]<a[j-1])
					++count;
				else
					break;
	}

	printf("%d", count);
	return 0;
}