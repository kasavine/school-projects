#include "my.h"

char* string_copy(char* str1, char* str2){
    int i = 0;
    while (str2[i]){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return (str1);
}
