#include "my.h"

int fibonacci(int num){
    if (num == 0) {
        return (0);
    }
    if (num == 1) {
        return (1);
    }
    if (num == 2) {
        return (1);
    }
    return (my_fibonacci(num - 1) + my_fibonacci(num - 2));

    // 0 1 2 3 4 5 6 7
    // 0 1 1 2 3 5 8 13
}
