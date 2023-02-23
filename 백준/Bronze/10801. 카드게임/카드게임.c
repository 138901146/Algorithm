#include<stdio.h>

int main(void)
{
	int A=0, B=0, a[10], b[10];

	for(int i=0;i<10;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<10;i++)
		scanf("%d", &b[i]);

	for(int i=0;i<10;i++)
		if(a[i]<b[i])
			B++;
		else if(a[i]>b[i])
			A++;

	printf("%c\n", A<B?'B':A>B?'A':'D');

	return 0;
}