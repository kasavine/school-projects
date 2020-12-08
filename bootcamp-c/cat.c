#include "my.h"

int main(int argc, char **argv){
    int sz; 
    if (argc > 1){  
        for (int i = 1; i < argc; i++){
            char buffer;  
            int fd = open(argv[i], O_RDONLY);
            while (read(fd, &buffer, 1)) {
                printf("%c", buffer);
            }
        close(fd);
        }
    }
}
