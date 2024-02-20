#include<stdio.h>

int main(void)
{
	int happy=0, sad=0;
	char str[256]={'\0'};

	fgets(str,sizeof(str),stdin);

	for(int i=1;str[i+1];++i)
		if(str[i-1]==':' && str[i]=='-')
		{
			if(str[i+1]==')')
				++happy;
			else if(str[i+1]=='(')
				++sad;
		}

	printf("%s", !(happy|sad)?"none":sad<happy?"happy":happy<sad?"sad":"unsure");
	return 0;
}