#include "my.h"

int check_doubles_second (char *str, char c){
    int i = 0;
    while (str[i]){
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int check_doubles_first (char *str, char c, int position){
    int i = 0;
    while (i < position){
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

char* s_union(char* first, char* second){
    char *res = (char *)malloc(sizeof(char) * (str_len(first) + str_len(second)) + 1);
    int j = 0;
    int i = 0;

    while (first[i]){
        if ((check_doubles_first(first, first[i], i))){
            res[j] = first[i];
            j++;
        }
        i++;
    }

    i = 0;
    while (second[i]){
        if ((check_doubles_second(first, second[i]))){
            if ((check_doubles_first(second, second[i], i))){
                res[j] = second[i];
                j++;
            }
        }
        i++;
    }
    res[j] = '\0';
    return (res);
    free (res);
}