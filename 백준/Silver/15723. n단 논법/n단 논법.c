#include<stdio.h>

int main(void)
{
	int n, m, thesis[26][26]={0};
	char pri, sec;

	scanf("%d", &n);

	while(n--)
	{
		getchar();
		scanf("%c is %c", &pri, &sec);
		thesis[pri-'a'][sec-'a']=1;
	}

	for(int i=0;i<26;++i)
		thesis[i][i]=1;

	for(int mid=0;mid<26;++mid)
		for(int start=0;start<26;++start)
			for(int end=0;end<26;++end)
				thesis[start][end]|=thesis[start][mid]&thesis[mid][end];

	scanf("%d", &m);

	while(m--)
	{
		getchar();
		scanf("%c is %c", &pri, &sec);
		printf("%c\n", thesis[pri-'a'][sec-'a']?'T':'F');
	}

	return 0;
}