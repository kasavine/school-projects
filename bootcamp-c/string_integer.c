#include "my.h"

int string_integer(char* strn){
    int res = 0;
    int sign = 1;
    int i = 0;
    while (strn[i] == ' ' || strn[i] == '\t'){
        i++;
    }
    if (strn[i] == '-' || strn[i] == '+'){
        if (strn[i] == '-') 
            sign = -1;
        i++;
    }
    while (strn[i] >= '0' && strn[i] <= '9'){
        res = (res * 10) + (strn[i] - '0');
        i++;
    }
    return (res * sign);
}     