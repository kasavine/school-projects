#include "my.h"

int count_lines(int level){
    if (level == 0)
        return (0);
    return ((level + 3) + count_lines(level - 1));
}

int generate_level(char **array, int index, int first_line_len, int level){
    // printf("creating level for index %d, length: %d, level: %d\n", index, first_line_len, level);
    int j;
    int i;
    int len;
    int size;
    char *line;

    j = 0;
    while (j < level + 3){
        size = (j * 2) + first_line_len;
        line = malloc(size);
        i = 0;
        while(i < (first_line_len + (j * 2))){
            line[i] = '*';
            i++;
        }
        line[i] = '\0';
        array[index + j] = line;
        j++;
    }
    len = strlen(array[index + j - 1]);
    return (len);
}

void print_line(char *line, int max_len){
    int len_line = strlen(line);
    int count_spaces = (max_len - len_line) / 2;

    int i = 0;
    while (i < count_spaces){
        printf("%c", ' ');
        i++;
    }
    printf("%s\n", line);
}

void lower_part(int size, int last_len){
    int count_spaces;
    int i;
    int j;

    if (size % 2 == 0)
        count_spaces = (last_len - size) / 2 + 1;
    else
        count_spaces = (last_len - size) / 2;
    
    for (j = 0; j < count_spaces; j++){
        printf("%c", ' ');
    }
    for (i = 0; i < size; i++){
        printf("%c", '|');
    }
    printf("\n");
}

void christmas_tree(int size){
    int count;
    int last_len;
    int delta;
    char **array;
    int i;

    count  = count_lines(size); 
    array = (char**)malloc(sizeof(char *) * count); 
    last_len = generate_level(array, 0, 1, 1);
    delta = 2;

    for (int current_level = 1; current_level < size; current_level++){
        int lines_added = count_lines(current_level);
        last_len = generate_level(array, lines_added, last_len - delta, current_level + 1);
        if (current_level % 2 == 0) 
            delta+=2;
    }
    int last = last_len;    
    for (i = 0; i < count; i++){
        print_line(array[i], last);
    }

    int j;
    while (j < size){
        lower_part(size, last);
        j++;
    }
}


int main(int argc, char **argv){
    if(argc == 2){
        int size;
        size = atoi(argv[1]);
        christmas_tree(size);
    }
}