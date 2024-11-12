#include<stdio.h>

int main(void)
{
    int Sx, Sy, Ex, Ey, Px, Py;

    scanf("%d%d", &Sx, &Sy);
    scanf("%d%d", &Ex, &Ey);
    scanf("%d%d", &Px, &Py);

    if(Sx==Ex)
    {
        if(Px==Sx)
        {
            if(Sy<=Py && Py<=Ey || Ey<=Py && Py<=Sy)
                printf("2");
            else
                printf("0");
        }
        else
            printf("0");
    }
    else if(Sy==Ey)
    {
        if(Py==Sy)
        {
            if(Sx<=Px && Px<=Ex || Ex<=Px && Px<=Sx)
                printf("2");
            else
                printf("0");
        }
        else
            printf("0");
    }
    else
        printf("1");

    return 0;
}