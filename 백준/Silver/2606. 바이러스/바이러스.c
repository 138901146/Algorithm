#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
    int com, pair, x, y, count=0;
    bool **virus=NULL;

    scanf("%d", &com);
    virus=(bool **)malloc(com*sizeof(bool *));
    for(int i=0;i<com;i++)
        virus[i]=(bool *)calloc(com,sizeof(bool));
    scanf("%d", &pair);

    for(int i=0;i<com;i++)
        virus[i][i]=true;

    for(int p=0;p<pair;p++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;

        virus[x][y]=virus[y][x]=true;
    }
    for(int k=0;k<com;k++)
        for(int i=0;i<com;i++)
            for(int j=0;j<com;j++)
                virus[i][j]|=virus[i][k]&&virus[k][j];

    for(int i=1;i<com;i++)
        count+=virus[0][i];
    printf("%d\n", count);
    for(int n=0;n<com;n++)
        free(virus[n]);
    free(virus);
    return 0;
}