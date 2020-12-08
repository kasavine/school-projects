#include "my.h"

int count_words(char *str, char *separator){
    int cur_index = 0;
    int cur_state = 0;

    int i = 0;
    while (str[i]){
        if (str[i] != *separator && cur_state == 0){
            cur_state = 1;
            cur_index++;
        }
        else if (str[i] == *separator){
            cur_state = 0;
        }
        i++;
    }
    return (cur_index);
}

char *malloc_for_substr(char *str, int i, char *separator){
    char *sub_str;
    int len_word;
    int i_copy;
    int j;

    len_word = 0;
    while (str[i] && str[i] == *separator){
        i++;
    }
    while (str[i] && str[i] != *separator){
        len_word++;
        i++;
    }
    sub_str = (char *)malloc(sizeof(char) * len_word + 1);

    i_copy = i - len_word;
    j = 0;
    while (str[i_copy] && str[i_copy] != *separator){
        sub_str[j] = str[i_copy];
        i_copy++;
        j++;
    }
    sub_str[j] = '\0';
    return (sub_str);
}

string_array* string_split(char* str, char* separator){
    int len_s;
    int seps;
    char* sub_cp;
    string_array *result;
    int array_size;
    int i = 0;
    int j = 0;

    array_size = count_words(str, separator);
    len_s = str_len(str);
    result = (string_array *)malloc(sizeof(string_array));
    result->size = array_size;
    result->array = (char**)malloc(sizeof(char**) * array_size);

    while(str[i] && str[i] == *separator){
        i++;
    }
    while (str[i] && j < result->size){
        sub_cp = malloc_for_substr(str, i, separator);
        result->array[j] = (char*)malloc(sizeof(strlen(sub_cp)));
        strcpy(result->array[j], sub_cp);
        while (str[i] && str[i] == *separator){
            i++;
        }
        i = strlen(sub_cp) + i + 1;
        free (sub_cp);
        j++;
    }
    return (result);
}