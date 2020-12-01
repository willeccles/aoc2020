#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    // there's like 200 lines in the input, this should be fine
    int input[256] = {0};
    int count = 0;

    while (EOF != scanf("%d", &(input[count]))) {
        count++;
    }

    bool foundpair = false;
    bool foundtriple = false;
    int p1, p2; // these are here purely so the output is in order
    for (int i = 0; i < count && (!foundpair || !foundtriple); i++) {
        for (int j = 0; j < count && (!foundpair || !foundtriple); j++) {
            if (!foundpair && i != j) {
                if (input[i] + input[j] == 2020) {
                    p1 = input[i] * input[j];
                    foundpair = true;
                }
            }
            for (int k = 0; k < count && !foundtriple; k++) {
                if (i != j && i != k && k != j) {
                    if (input[i] + input[j] + input[k] == 2020) {
                        p2 = input[i] * input[j] * input[k];
                        foundtriple = true;
                    }
                }
            }
        }
    }

    printf("Part 1: %d\nPart 2: %d\n", p1, p2);

    return 0;
}
