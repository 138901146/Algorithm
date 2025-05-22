#include<stdio.h>

int main(void)
{
	int count=0;
	char S[1001]={0};

	fgets(S,sizeof(S),stdin);

	for(int i=0;i<1001;++i)
		switch(S[i])
		{
			case 'B':
				++count;
			case 'A':
			case 'a':
			case 'b':
			case 'D':
			case 'd':
			case 'e':
			case 'g':
			case 'O':
			case 'o':
			case 'P':
			case 'p':
			case 'Q':
			case 'q':
			case 'R':
			case '@':
				++count;
				break;
			default:
				break;
		}

	printf("%d", count);
	return 0;
}