#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int price) {
    return price>499999?price/5<<2:price>299999?price/10*9:price>99999?price*95/100:price;
}