#include "my.h"

char* string_copy_n(char* str1, char* str2, int n){
    int i = 0;
    while (i < n){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return (str1);
}