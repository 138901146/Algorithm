#include<stdio.h>

char T[1000001]={'\0'}, P[1000001]={'\0'};
int t[1000001]={0}, p[1000001]={0};

int main(void)
{
	int n=0, m=0, count=0;

	do
		scanf("%c", &T[n++]);
	while(T[n-1]!='\n' && T[n-1]!=EOF);
	--n;

	do
		scanf("%c", &P[m++]);
	while(P[m-1]!='\n' && P[m-1]!=EOF);
	--m;

	for(int i=1,j=0;i<m;++i)
	{
		while(j && P[i]!=P[j])
			j=p[j-1];

		if(P[i]==P[j])
			p[i]=++j;
	}

	for(int i=0,j=0;i<n;++i)
	{
		while(j && T[i]!=P[j])
			j=p[j-1];

		if(T[i]==P[j])
		{
			if(j==m-1)
			{
				t[count++]=i-j+1;
				j=p[j];
			}
			else
				++j;
		}
	}

	printf("%d\n", count);
	for(int i=0;i<count;++i)
		printf("%d ", t[i]);
	return 0;
}