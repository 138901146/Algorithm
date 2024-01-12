#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    n>>=1;
    return n*(n+1);
}