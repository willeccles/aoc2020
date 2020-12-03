#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[64] = {0};
    size_t width = 0;

    struct slope {
        size_t right;
        size_t down;
        size_t col;
        size_t trees;
    } slopes[5] = {
        { 1, 1, 0, 0 },
        { 3, 1, 0, 0 },
        { 5, 1, 0, 0 },
        { 7, 1, 0, 0 },
        { 1, 2, 0, 0 },
    };

    size_t row = 0;

    while (EOF != scanf("%63[.#]\n", line)) {
        if (width == 0) {
            width = strlen(line);
        }

        for (int i = 0; i < 5; i++) {
            if (row++ % slopes[i].down == 0) {
                slopes[i].trees += (line[slopes[i].col % width] == '#');
                slopes[i].col += slopes[i].right;
            }
        }
    }

    size_t p2 = 1;
    for (int i = 0; i < 5; i++) {
        p2 *= slopes[i].trees;
    }

    printf("Part 1: %zu\nPart 2: %zu\n", slopes[1].trees, p2);

    return 0;
}
