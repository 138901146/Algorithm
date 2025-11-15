#include<stdio.h>

int main(void)
{
	int N, r_seat=0, c_seat=0;
	char room[100][101]={0};

	scanf("%d", &N);
	for(int r=0;r<N;++r)
		scanf("%s", room[r]);

	for(int r=0;r<N;++r)
		for(int c=1;c<N;++c)
			if(room[r][c-1]=='.'&&room[r][c]=='.')
			{
				++c_seat;
				while(c<N&&room[r][c]=='.')
					++c;
			}

	for(int c=0;c<N;++c)
		for(int r=1;r<N;++r)
			if(room[r-1][c]=='.'&&room[r][c]=='.')
			{
				++r_seat;
				while(r<N&&room[r][c]=='.')
					++r;
			}

	printf("%d %d", c_seat, r_seat);
	return 0;
}