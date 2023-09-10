#include<stdio.h>

int main(void)
{
	int y, m, d, N;

	scanf("%04d-%02d-%02d", &y, &m, &d);
	scanf("%d", &N);

	d+=N;

	m+=(d-1)/30;
	d%=30;
	if(!d)
		d=30;
	y+=(m-1)/12;
	m%=12;
	if(!m)
		m=12;

	printf("%04d-%02d-%02d", y, m, d);
	return 0;
}