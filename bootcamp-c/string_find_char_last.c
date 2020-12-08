#include "my.h"

char* string_find_char_last(char* str, char c){
    char *last_found = NULL;
    while (*str){
        if (*str == c)
            last_found = str;
        str++;
    }
    return (last_found);
}