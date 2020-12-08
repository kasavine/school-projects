#include "my.h"

int factorial_iterative(int num){
    int i;
    int res = 1;

    if (num < 0)
        return (0);
    if (num == 0)
        return (1);
    i = num;
    while (i){
        res = res * i;
        i--;
    }
    return (res);
}

int factorial_recursive(int num){
    if (num < 0)
        return (0);
    if (num == 0)
        return (1);
    return (num * my_recursive_factorial(num - 1));
}

