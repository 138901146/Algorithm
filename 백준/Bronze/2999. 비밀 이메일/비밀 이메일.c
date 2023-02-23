#include<stdio.h>
#include<string.h>

int main(void)
{
	char message[101]={'\0', };
	int R, C, N;

	scanf("%s", message);
	N=strlen(message);

	for(int r=1;r<=N;r++)
		for(int c=r;r*c<=N;c++)
			if(r*c==N)
			{
				R=r;
				C=c;
			}

	for(int i=0;i<R;i++)
	    for(int j=0;j<C;j++)
	        printf("%c", message[i+j*R]);
    printf("\n");
    
	return 0;
}