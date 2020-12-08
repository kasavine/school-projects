#include "my.h"

void put_char(char c){
    write(1, &c, 1);
}

void draw_line(int col, char mid, char start_end){
    int x = col;
    
    if (col == 0) {
        return ;
    } 
    else if (col == 1){
        put_char(start_end);
        put_char('\n');
    }
    else {
        put_char(start_end);
        while (x > 2){
            put_char(mid);
            x--;
        }
        put_char(start_end);
        put_char('\n');
    }
}

void square(int col, int row){
    int y = row;
    char start_end = 'o';
    char mid_row = '-';
    char mid_col = '|';

    if (col == 0 || row == 0){
        return ;
    }
    else if (row == 1){
        draw_line(col, mid_row, start_end);
    }
    else {
        draw_line(col, mid_row, start_end);

        while (y > 2){
            draw_line(col, ' ', mid_col);
            y--;
        }
        draw_line(col, mid_row, start_end);
    }
}

int main(int ac, char **av){
    if (ac == 3){
        square(atoi(av[1]), atoi(av[2]));
    }
    return (0);
}