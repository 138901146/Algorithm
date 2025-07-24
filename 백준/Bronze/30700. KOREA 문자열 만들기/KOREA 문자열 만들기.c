#include<stdio.h>

int main(void)
{
	int state=0;
	char S[1001]={0};

	scanf("%s", S);

	for(int i=0;S[i];++i)
		switch(state%5)
		{
			case 0:
				state+=S[i]=='K';
				break;
			case 1:
				state+=S[i]=='O';
				break;
			case 2:
				state+=S[i]=='R';
				break;
			case 3:
				state+=S[i]=='E';
				break;
			case 4:
				state+=S[i]=='A';
				break;
		}

	printf("%d", state);
	return 0;
}