/*
**
** QWASAR.IO -- my_split
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {string_array*}
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int str_len(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int count_words(char *str, char *separator)
{
    int cur_index = 0;
    int cur_state = 0;

    int i = 0;
    while (str[i])
    {
        if (str[i] != *separator && cur_state == 0)
        {
            cur_state = 1;
            cur_index++;
        }
        else if (str[i] == *separator)
        {
            cur_state = 0;
        }
        i++;
    }
    return (cur_index);
}

char *malloc_for_substr(char *str, int i, char *separator)
{
    printf("STR which came %s\n", str);
    char *sub_str;
    int len_word;
    int i_copy;
    int j;

    len_word = 0;
    while (str[i] && str[i] != *separator)
    {
        len_word++;
        i++;
    }
    printf("LEN WORD %d AND I %d\n", len_word, i);
    sub_str = (char *)malloc(sizeof(char) * len_word + 1);

    i_copy = i - len_word;
    j = 0;
    while (str[i_copy] && str[i_copy] != *separator)
    {
        sub_str[j] = str[i_copy];
        i_copy++;
        j++;
    }
    sub_str[j] = '\0';
    return (sub_str);
}

string_array* my_split(char* str, char* separator)
{
    int len_s;
    char* sub_cp;
    int seps;
    string_array *result;
    int array_size;
    int i;
    int j;
    

    array_size = count_words(str, separator);
    len_s = str_len(str);
    result = (string_array *)malloc(sizeof(string_array));
    result->size = array_size;
    result->array = malloc(sizeof(char**) * array_size);

    // printf("4");
    printf("res size  %d\n", result->size);

    i = 0;
    j = 0;
    //while (str[i] && str[i] == *separator)
    while(str[i] != '\0' && str[i] == *separator)
    {
        i++;
    }
    while (j < result->size && str[i] != '\0')
    {
        // printf("i BEFORE %d\n", i);
        sub_cp = malloc_for_substr(str, i, separator);
        // printf("sub cp ->> %s\n", sub_cp);
        result->array[j] = malloc(sizeof(strlen(sub_cp)));
        strcpy(result->array[j], sub_cp);
        i = strlen(sub_cp) + 1;
        // printf("i after %d\n", i);
        j++;
    }
    return (result);
}

int main ()
{
    char *str = strdup("abc abcbbb      deffff   ");
                    //    2   6           18
    char *sep = malloc(sizeof(char));
    *sep = ' ';
    // printf("kuku\n");
    printf("%d\n", count_words(str, sep));
    printf("|%s|\n", malloc_for_substr(str, 0, sep));
    string_array *res = my_split(str, sep);

    int size = count_words(str, sep);

    int i = 0;
    while (i < size) 
    {
        printf("%s \n", res->array[i]);
        i++;
    }

    return (0);

}