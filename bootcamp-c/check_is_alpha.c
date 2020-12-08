#include "my.h"

int check_is_alpha(char c){
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')){
        return (1);
    }
    return (0);
}
