#include "my.h"

char* string_capitalize(char* str){
    char* temp = str;
    int i = 0;
    int char_found = -1;

    while (str[i] != '\0'){
        if (str[i] == ' '){
            temp[i] = str[i];
            i++;
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z'){
            if (char_found == -1){
                char_found = 1;
                temp[i] = str[i];
            }
            else{
                temp[i] = str[i] + 32;
            }
            i++;
        }
        else {
            if (char_found == -1){
                char_found = 1;
                temp[i] = str[i] - 32;
            }
            else{
                temp[i] = str[i];
            }
            i++;
        }
    }
    return (temp);
}
