#include<stdio.h>

int main(void)
{
	int h[2], m[2], s[2], k, t, gap;

	for(int i=0;i<2;++i)
		scanf("%02d:%02d:%02d", &h[i], &m[i], &s[i]);
	scanf("%d%d", &t, &k);

	gap=3600*(h[1]-h[0])+60*(m[1]-m[0])+s[1]-s[0];

	printf("%d", t*(100-k)<=gap*100);
	return 0;
}