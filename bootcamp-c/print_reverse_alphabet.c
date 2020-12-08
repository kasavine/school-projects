#include "my.h"

void print_reverse_alphabet(){
    char let = 'z';
    while (let >= 'a'){
        write(1, &let, 1);
        let--;
    }
    write(1, "\n", 1);
}