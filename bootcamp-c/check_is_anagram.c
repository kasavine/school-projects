#include "my.h"

void swap(char* param_1, char* param_2){
    char temp = *param_1;
    *param_1 = *param_2;
    *param_2 = temp;
}

char *sorting (char *s){
    int s_len = str_len(s);
    for (int i = 0; i < s_len - 1; i++) {
        for (int j = 0; j < s_len - i - 1; j++) {
             if (s[j] >= s[j+1])
                swap(&s[j], &s[j+1]);
        }
    }
    return (s);
}

int check_is_anagram(char* first, char* second){
    int first_len = str_len(first);
    int second_len = str_len(second);

    char *sorted_first = (char *)malloc(sizeof(char) * first_len + 1);
    char *sorted_second = (char *)malloc(sizeof(char) * second_len + 1);
    if (first_len == second_len)
    {
        sorted_first = sorting(first);
        sorted_second = sorting(second);

        int i = 0;
        while (sorted_first[i])
        {
            if (sorted_first[i] != sorted_second[i])
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}

/*
f bcde
   ^
abc
changed = true
loop changed
   changed = false
   loop until last element
     if right < left
       swap(right, left)
       changed = true
*/

    // #include <stdio.h>
    // #include <string.h>
    // int main(int ac, char **av) {
    //     // is_anagram(strdup("abcdef"), strdup("fabcde"));
    //     char *a = strdup("abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    //     char *b = strdup("abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbc");
    //     printf("%s - %d\n", sorting(a), str_len(a));
    //     printf("%s - %d\n", sorting(b), str_len(b));
    //     printf("is_anagram - %d", is_anagram(a, b));
    //     return 0;
    // }
