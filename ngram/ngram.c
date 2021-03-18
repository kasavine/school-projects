#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* make_alphabet(char* str){
    char temp;
    int i, j;
    int len = strlen(str);
    for (i = 0; i < len-1; i++) {
        for (j = i+1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    return str;
    // "lmno425opabbcd"
    // "abcdlmnop245"
}

int check_position(char* alphabet, char c){
    int i = 0;
    while (alphabet[i]){
        if (alphabet[i] == c){
            return (i);
        }
        i++;
    }
    return (-1);
}

int* count_pieces(char* alphabet, char* str){
    int* result_array = (int*)malloc(sizeof(int) * 8+1);
    int pos;
    int i = 0;
    while (str[i]){
        pos = check_position(alphabet, str[i]);
        result_array[pos]++;
        i++;
    }
    return (result_array);
}

void print_counted(char* str){

    char* alphabet = make_alphabet(str);
    int* count = count_pieces(alphabet, str); // aab        // [2 1 0 0 0 0]
    
    int i = 0;
    while (alphabet[i] != '\0'){
        printf("%c:%d\n", alphabet[i], count[i]);
        while ((alphabet[i] == alphabet[i+1]) && (alphabet[i] != '\0')){
            i++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int len = 0;
    size_t i = 1;
    while (i < argc)
    {
        len += strlen(argv[i]);
        i++;
    }
    // printf("Total length: %d", len);

    char* str = (char*)malloc(sizeof(char) * len + 1);
    i = 1;
    while (i < argc){
        strcat(str, (argv[i]));
        i++;
    }
    print_counted(str);
    return 0;
}
