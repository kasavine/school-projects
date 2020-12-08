#include "my.h"

char* string_dup(char* str){
    int len = len_str(str);
    char *dup_str = (char*)malloc(sizeof(char) * len + 1);
    int i = 0;

    while (str[i]){
        dup_str[i] = str[i];
        i++;
    }
    return (dup_str);
}