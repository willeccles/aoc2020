#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(void) {
    char pass[11] = {0};
    int max = 0;
    int ids[888] = {0};
    int n = 0;

    while (scanf("%s", pass) > 0) {
        int id = 0;
        for (int i = 0; i < 10; i++) {
            id |= (pass[i] == 'B' || pass[i] == 'R' ) << (9 - i);
        }
        ids[n++] = id;
        max = id > max ? id : max;
    }

    // this could be done more efficiently than O(n^2) by sorting the array, but
    // I am lazy and do not want to write a compare function for qsort(), nor do
    // I know how efficient qsort() is, nor do I care to find out
    int p2 = -1;
    for (int i = 0; i < 888 && p2 < 0; i++) {
        bool og = false;
        bool tg = false;
        for (int j = 0; j < 888; j++) {
            og = og || ids[j] == ids[i] + 1;
            tg = tg || ids[j] == ids[i] + 2;
        }
        if (!og && tg) {
            p2 = ids[i] + 1;
        }
    }

    printf("Part 1: %d\n", max);
    printf("Part 2: %d\n", p2);

    return 0;
}
