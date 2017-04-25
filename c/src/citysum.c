
#include <stdio.h>
#include "city.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE (8 * 1024)

int main(int argc, char * argv [])
{
    int fd;
    char buffer[BUFFER_SIZE];
    size_t r;
    uint128 sum;
    sum.first = 0xc00fee;
    sum.second = 0xc00fee;

    if (argc != 2) {
        fprintf( stderr, "ERROR: invalid arguments\n");
        fprintf( stderr, "USAGE: citysum [FILENAME]\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd <= 0) {
        fprintf( stderr, "ERROR: failed to open file %s\n", filename);
        return 2;
    }

    do {
        r = read(fd, buffer, BUFFER_SIZE);
        if (r <= 0)
            break;
        sum = CityHash128WithSeed(buffer, r, sum);
    } while(1);
    close(fd);
    
    printf("%zx:%zx", sum.first, sum.second);
    return 0;
}
