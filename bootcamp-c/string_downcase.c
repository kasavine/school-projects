#include "my.h"

char* string_downcase(char* str){
    char* temp = str;
    int i = 0;
    while (temp[i] != '\0'){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            temp[i] = str[i] + 32;
            i++;
        }
        else{
            temp[i] = str[i];
            i++;
        }
    }
    return (temp);
}