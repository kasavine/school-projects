#include "my.h"

char* robot_simulator(char* param_1){
    int x_val = 0;
    int y_val = 0;
    char *directions[] = {"north", "east", "south", "west"};
    int bearing = 0;    // {"0",     "1",     "2",    "3"}
    char result[1000];  
    char *ptr_result = result;                 
    int i = 0;
    while (param_1[i]){
        if (param_1[i] == 'L'){
            bearing = (bearing + 1) % 4; //(cur + 1)%4
        }
        else if (param_1[i] == 'R'){
            if (bearing == 0){
                bearing = 3;
            }
            else {
                bearing = ((bearing - 1) % 4); //(cur - 1)%4
            }
        }
        else if (param_1[i] == 'A'){
            if (bearing == 0){
                y_val--;
            }
            else if (bearing == 1){
                x_val--;   
            }
            else if (bearing == 2){
                y_val++;
            }
            else if (bearing == 3){
                x_val++;
            }
        }
        i++;
    }
    snprintf(result, 100, "{x: %d, y: %d, bearing: '%s'}", x_val, y_val, directions[bearing]);
    return (ptr_result);
}