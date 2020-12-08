#include "my.h"

void print_alphabet(){
    char let = 'a';
    while (let <= 'z'){
        write(1, &let, 1);
        let++;
    }
    write(1, "\n", 1);
}