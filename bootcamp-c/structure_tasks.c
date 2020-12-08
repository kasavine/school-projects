#include "my.h"

void my_first_struct(integer_array* param_1){
    int i = 0;
    printf("%i\n", param_1->size);
    while (param_1->size > i){
        printf("%i\n", param_1->array[i]);
        i++;
    }
}
bool my_is_sort(integer_array* param_1){
    int i = 0;
    while ((param_1->size - 2) > i){
        if ((param_1->array[i] >= param_1->array[i + 1] &&
             param_1->array[i + 1] >= param_1->array[i + 2]) ||
            (param_1->array[i] <= param_1->array[i + 1] &&
             param_1->array[i + 1] <= param_1->array[i + 2])){
            i++;
        }
        else {
            return (false);
        }
    }
    return (true);
}

void my_print_words_array(string_array* param_1){
    int i = 0;
    while (param_1->size > i){
        put_char(param_1->array[i]);
        i++;
    }
}

integer_array* my_count_on_it(string_array* param_1){
    integer_array* sizes  = (integer_array*)malloc(sizeof(integer_array));
    int len;
    int i = 0;

    sizes->size = param_1->size;
    sizes->array = (int*)malloc(sizes->size * sizeof(int));
    while (param_1->size > i){
        len = len_str(param_1->array[i]);
        sizes->array[i] = len;
        i++;
    }
    return (sizes);
}
