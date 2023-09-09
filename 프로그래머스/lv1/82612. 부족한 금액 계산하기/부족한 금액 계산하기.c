#include <stdio.h>
#include <stdlib.h>

long long solution(long long int price,int money,int count)
{
    price*=((count)*(count+1))/2;
    return price>=money?price-money:0;
}