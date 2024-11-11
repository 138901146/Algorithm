#include<stdio.h>

int main(void)
{
    int N, weather;
    long long angry=0, sum=0;

    scanf("%d", &N);

    while(N--)
    {
        scanf("%d", &weather);

        if(weather)
            ++angry;
        else
            --angry;
        
        sum+=angry;
    }

    printf("%lld", sum);
    return 0;
}