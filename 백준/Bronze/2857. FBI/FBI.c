#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	bool isFBI[5]={false, }, morethanzero=false;

	for(int i=0;i<5;i++)
	{
		char name[11]={'\0', };

		scanf("%s", name);

		if(strstr(name,"FBI")!=NULL)
		{
			morethanzero=true;
			isFBI[i]=true;
		}
	}

	if(!morethanzero)
		printf("HE GOT AWAY!\n");
	else
	{
		for(int i=0;i<5;i++)
			if(isFBI[i])
		printf("%d ", i+1);
		printf("\n");
	}

	return 0;
}