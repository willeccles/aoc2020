#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
    char* line = NULL;
    size_t len = 0;
    ssize_t r = 0;
    bool yes1[26] = {0};
    bool yes2[26] = {true};
    long count1 = 0, count2 = 0;

    for (int i = 0; i < 26; i++) {
        yes2[i] = true;
    }

    while ((r = getline(&line, &len, stdin)) > 0) {
        if (*line == '\n' || (*line == '\r' && line[1] == '\n')) {
            for (int i = 0; i < 26; i++) {
                count1 += yes1[i];
                count2 += yes2[i];
                yes1[i] = false;
                yes2[i] = true;
            }
        } else {
            for (char* c = line; *c; c++) {
                if (isalpha(*c)) {
                    yes1[*c - 'a'] = true;
                }
            }
            for (char c = 'a'; c <= 'z'; c++) {
                yes2[c - 'a'] &= NULL != strchr(line, c);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        count1 += yes1[i];
        count2 += yes2[i];
    }

    printf("Part 1: %ld\n", count1);
    printf("Part 2: %ld\n", count2);

    free(line);

    return 0;
}
