#include "my.h"

char* string_join_struct(string_array* str_1, char* str_2){
    if (str_1->size == 0)
        return (NULL);
    int len_str_2 = len_str(str_2);
    int total = len_str_2;
    int i = 0;
    while (str_1->size > i){
        total = len_str(str_1->array[i]) + total;
        i++;
    }
    char* res = (char*)malloc(sizeof(char) * total + 1);

    int j = 0;
    while (str_1->size > j){
        res = strcat(res, str_1->array[j]);
        if (j != str_1->size - 1){
            res = strcat(res, str_2);
        }
        j++;
    }
    res = strcat(res, "\0");
    return (res);
}
