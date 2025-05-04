#include<stdio.h>

int main(void)
{
	int N, size[6], T, P, T_count=0;

	scanf("%d", &N);
	for(int i=0;i<6;++i)
		scanf("%d", &size[i]);
	scanf("%d%d", &T, &P);

	for(int i=0;i<6;++i)
		if(size[i]%T)
			T_count+=size[i]/T+1;
		else
			T_count+=size[i]/T;

	printf("%d\n%d %d", T_count, N/P, N%P);
	return 0;
}