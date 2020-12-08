#include "my.h"

int check_doubles_first (char *str, char c, int position){
    int i = 0;
    while (i < position){
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

char* s_inter(char* first, char* second){
    char *res =  (char *)malloc(sizeof(char) * str_len(first) + 1);

    int i = 0;
    int j = 0;    
    int res_i = 0;
    while (first[i])
    {
        j = 0;
        while (second[j])
        {
            if (first[i] == second[j])
            {
                if (check_doubles_first(first, first[i], i))
                {
                    res[res_i] = first[i];
                    res_i++;
                    break;
                }
            }
            j++;
        }
        i++;
    }
    res [res_i] = '\0';
    return (res);
    free (res);
}