#include "my.h"

char *string_reverse(char *str){
    int len = str_len(str);
    char *res = (char *)malloc(sizeof(char) * len + 1);
    int i = 0;

    while (len){
        len--;
        res[i] = str[len];
        i++;
    }
    res[i] = '\0';
    return (res);
}