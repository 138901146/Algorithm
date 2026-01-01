#include<stdio.h>

int main(void)
{
	int h, m, overlap=0;

	scanf("%02d:%02d", &h, &m);

	m+=60*h;
	for(int t=0;t<120;++t,++m)
		if(420<=m&&m<600||900<=m&&m<1140)
			++m;

	h=(m/60)%24;
	m%=60;

	printf("%02d:%02d", h, m);
	return 0;
}