#include "my.h"

int calc_abs(int num){
    if (num >= 0){
        return (num);
    }
    else{
        return (-(num));
    }
}

int calc_add(int num_a, int num_b){
    int res = num_a + num_b;
    return (res);
}

int calc_mult(int num_a, int num_b){
    int res = num_a * num_b;
    return (res);
}

int calc_sub(int num_a, int num_b){
    int res = num_a - num_b;
    return (res);
}