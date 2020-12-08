#include "my.h"

char* string_find_sub(char* str, char* sub_str){
    int i;
    int j;

    if (!(*sub_str))
        return (str);
    i = 0;
    while (str[i]){
        j = 0;
        while (sub_str[j] == str[i + j]){
            if (sub_str[j + 1] == '\0')
                return (str + i);
            j++;
        }
        i++;
    }
    return (NULL);
}