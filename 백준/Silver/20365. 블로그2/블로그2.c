#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int N, redcount=0, bluecount=0;
	char *problem=NULL;

	scanf("%d", &N);
	problem=(char *)malloc((N+1)*sizeof(char));
	scanf("%s", problem);

	for(int i=1;i<strlen(problem);i++)
		if(problem[i]!=problem[i-1])
		{
			if(problem[i-1]=='R')
				redcount++;
			else
				bluecount++;
		}
	if(problem[strlen(problem)-1]=='R')
		redcount++;
	else
		bluecount++;

	printf("%d\n", redcount<bluecount?redcount+1:bluecount+1);
	free(problem);
	return 0;
}