#include "my.h"

char* string_uppercase(char* str){
    char* temp = str;
    int i = 0;
    while (temp[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z'){
            temp[i] = str[i] - 32;
            i++;
        }
        else{
            temp[i] = str[i];
            i++;
        }
    }
    return (temp);
}