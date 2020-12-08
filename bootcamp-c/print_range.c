#include "my.h"

int* my_range(int start, int end){
    int i = 0;
    int *res = (int*)malloc(sizeof(int) * (end - start));    

    if (start >= end)
        return (NULL);
    while (start <= end) {
        res[i] = start;
        start++;
        i++;
    }
    return (res);
}