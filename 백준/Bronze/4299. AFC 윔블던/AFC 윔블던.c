#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int sum, sub;
	bool found=false;

	scanf("%d %d", &sum, &sub);

	for(int MK=0;MK<=sum;MK++)
		if(2*MK-sub==sum)
		{
			printf("%d %d\n", MK, MK-sub);
			found=true;
			break;
		}

	if(!found)
		printf("-1\n");
	return 0;
}