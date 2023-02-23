#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int b, c, d, *B=NULL, *C=NULL, *D=NULL, before=0, after=0, min;

	scanf("%d %d %d", &b, &c, &d);
	B=(int *)malloc(b*sizeof(int));
	C=(int *)malloc(c*sizeof(int));
	D=(int *)malloc(d*sizeof(int));

	min=b<=c&&b<=d?b:c<=b&&c<=d?c:d;

	for(int i=0;i<b;i++)
	{
		scanf("%d", &B[i]);
		before+=B[i];
	}
	for(int i=0;i<c;i++)
	{
		scanf("%d", &C[i]);
		before+=C[i];
	}
	for(int i=0;i<d;i++)
	{
		scanf("%d", &D[i]);
		before+=D[i];
	}

	qsort((void *)B,(size_t)b,sizeof(int),compare);
	qsort((void *)C,(size_t)c,sizeof(int),compare);
	qsort((void *)D,(size_t)d,sizeof(int),compare);

	for(int i=0;i<b;i++)
		after+=i<min?(9*B[b-i-1])/10:B[b-i-1];
	for(int i=0;i<c;i++)
		after+=i<min?(9*C[c-i-1])/10:C[c-i-1];
	for(int i=0;i<d;i++)
		after+=i<min?(9*D[d-i-1])/10:D[d-i-1];

	printf("%d\n%d\n", before, after);
	free(B);
	free(C);
	free(D);
	return 0;
}