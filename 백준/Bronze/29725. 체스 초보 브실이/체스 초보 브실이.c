#include<stdio.h>

int main(void)
{
	int score=0;
	char c;

	for(int i=0;i<8;++i)
	{
		for(int j=0;j<8;++j)
		{
			c=getchar();

			switch(c)
			{
				case 'P':
					++score;
					break;
				case 'p':
					--score;
					break;
				case 'N':
				case 'B':
					score+=3;
					break;
				case 'n':
				case 'b':
					score-=3;
					break;
				case 'R':
					score+=5;
					break;
				case 'r':
					score-=5;
					break;
				case 'Q':
					score+=9;
					break;
				case 'q':
					score-=9;
					break;
				default:
					break;
			}
		}
		getchar();
	}

	printf("%d", score);
	return 0;
}