#include "my.h"

void do_swap(int* a_num, int* b_num){
    int temp = *a_num;
    *a_num = *b_num;
    *b_num = temp;
}
