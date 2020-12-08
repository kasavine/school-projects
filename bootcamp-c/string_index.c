#include "my.h"

int string_index(char* str, char c){
    int i = 0;
    while (str[i] != '\0'){
        if (c == str[i]) 
            return (i);
        i++;
    }
    return (-1);
}