#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
long long solution(long long n) {
    return (long long)sqrt(n)*sqrt(n)==n?(sqrt(n)+1)*(sqrt(n)+1):-1;
}