#include "my.h"

int hidenp(char* first, char* second){
    int i = 0;
    int j = 0;
    int count = 0;
    int len_first = strlen(first);

    while (first[i]){
        while (second[j]){
            if (first[i] == second[j]){ 
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    return ((len_first == count) ? 1 : 0);
}