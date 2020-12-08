#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h> 


#define EVEN(N) (N % 2 == 0)
#define SUCCESS 0

#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."


#ifndef STRUCT_S_BOOL
#define STRUCT_S_BOOL
    typedef enum s_bool{
        FALSE,
        TRUE
    } t_bool;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
    typedef struct s_integer_array{
        int size;
        int* array;
    } integer_array;
#endif

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
    typedef struct s_string_array{
        int size;
        char** array;
    } string_array;
#endif