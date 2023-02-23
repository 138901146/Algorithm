#include<stdio.h>

int main(void)
{
	int date[2][3];

	for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
			scanf("%d", &date[i][j]);

 	printf("%d\n", date[1][1]>date[0][1] || date[1][1]==date[0][1] && date[1][2]>=date[0][2]?date[1][0]-date[0][0]:date[1][0]-date[0][0]-1);
 	printf("%d\n", date[1][0]-date[0][0]+1);
 	printf("%d\n", date[1][0]-date[0][0]);

	return 0;
}