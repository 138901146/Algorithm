#include<stdio.h>

int main(void)
{
	int univ[3], min=0, sum=0;

	for(int i=0;i<3;i++)
	{
		scanf("%d", &univ[i]);
		min=univ[min]<univ[i]?min:i;
		sum+=univ[i];
	}

	printf("%s\n", sum>=100?"OK":min==0?"Soongsil":min==1?"Korea":"Hanyang");
	return 0;
}