#include "my.h"

char* string_capitalize_reverse(char* str){
    char *res = (char *)malloc(sizeof(char) * str_len(str) + 1);

    int i = 0;
    // "a FiRSt LiTTlE TESt"
    // "A firsT littlE tesT"
    while (str[i]){
        if (check_is_upper(str[i]) && !(is_space_or_end(str[i + 1]))){
            res[i] = str[i] + 32;
        }
        else if (check_is_lower(str[i]) && is_space_or_end(str[i + 1])){
            res[i] = str[i] - 32;
        }
        else{
            res[i] = str[i];
        }
        i++;
    }
    return (res);
}