#include<stdio.h>

int main(void)
{
	int N, id, s, m, t;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d%d", &id, &s, &m, &t);
		printf("%08d %d %s\n", id, s+m+t, 54<s+m+t&&10<s&&7<m&&11<t?"PASS":"FAIL");
	}

	return 0;
}