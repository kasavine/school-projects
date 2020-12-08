#include "my.h"

int find_start(char *s){
    int i = 0;
    while (s[i] && isspace(s[i])){
        i++;
    }
    return (i);
} //3

int trimmeded_str_len(char *s){
    int count = 0;
    int state = 0;
    // 1 space found
    // 0 char found

    int i = find_start(s);
    while(s[i]){
        if (!(is_space(s[i]))){
            state = 0;
            count++;
        }
        else if (is_space(s[i])){
            if (state == 0){
                count++;
            }
            state = 1;
        }
        i++;
    }
    if (state == 1) {
        count--;
    }
    return (count);
}

// "...first...second..third...."
// "first.second.third"

char* string_strip(char* s){
    int state = 0;
    char *s_cp;
    s_cp = (char*)malloc(sizeof(char) * trimmeded_str_len(s) + 1);
    
    int i = find_start(s);    
    int j = 0;

    while (s[i]){
        if (!(is_space(s[i]))){
            state = 0;
            s_cp[j] = s[i];
            j++;
        }
        else if (is_space(s[i])){
            if (state == 0){
                s_cp[j] = s[i];
                j++;
            }
            state = 1;
        }
        i++;
    }
    if (state == 1)
        s_cp[j-1] = '\0';
    else
        s_cp[j] = '\0';
   return (s_cp);   
}
