#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define P2CHECK(s,n,c) ((strlen(s) >= (size_t)(n)) && ((s)[(n)-1] == (c)))

int main(void) {
    int part1valid = 0;
    int part2valid = 0;
    char pass[64] = {0};
    int min, max;
    char c;

    while (EOF != scanf("%d-%d %c: %64[^\n]", &min, &max, &c, pass)) {
        int count = 0;
        for (char* p = pass; *p; p++) {
            if (*p == c) {
                count++;
            }
        }

        part1valid += (count >= min && count <= max);
        part2valid += (P2CHECK(pass, min, c) ^ P2CHECK(pass, max, c));
    }

    printf("Part 1: %d valid passwords\n", part1valid);
    printf("Part 2: %d valid passwords\n", part2valid);

    return 0;
}
