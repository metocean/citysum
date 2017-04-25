
// #include <sys/time.h>
#include <stdio.h>
#include "city.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE (8 * 1024)

int citysum(const char *filename, uint64_t *first, uint64_t *second) {
    uint128 sum;
    sum.first = *first;
    sum.second = *second;
    char buffer[BUFFER_SIZE];
    int fd;
    size_t r;

    fd = open(filename, O_RDONLY);
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

    *first = sum.first;
    *second = sum.second;

    return 0;
}
