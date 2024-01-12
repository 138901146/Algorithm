#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    return (int)sqrt(n)*sqrt(n)==n?1:2;
}