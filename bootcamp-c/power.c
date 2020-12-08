#include "my.h"

int power_iterative(int num, int power){
    int i;
    int res = 1;

    if (power < 0)
        return (0);
    i = 0;
    while (i < power){
        res = res * num;
        i++;
    }
    return res;
}

int power_recursive(int num, int power){
    if (power == 0)
        return (1);
    if (power < 0)
        return (0);
    return (num * my_recursive_pow(num, power - 1));
}