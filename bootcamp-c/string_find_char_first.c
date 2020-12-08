#include "my.h"

char* string_find_char_first(char* str, char c){
    while (*str){
        if (*str == c)
            return (str);
        str++;
    }
    return (NULL);
}