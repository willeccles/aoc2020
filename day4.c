#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIT(n) (1 << n)

#if 0
#define BYR BIT(0)
#define IYR BIT(1)
#define EYR BIT(2)
#define HGT BIT(3)
#define HCL BIT(4)
#define ECL BIT(5)
#define PID BIT(6)
#define CID BIT(7)
#endif

#define IS_VALID(mask) (((mask) & 0x7F) == 0x7F)

struct passpart {
    const char* name;
    int value;
} parts[] = {
    { "byr", BIT(0) /*BYR*/ },
    { "iyr", BIT(1) /*IYR*/ },
    { "eyr", BIT(2) /*EYR*/ },
    { "hgt", BIT(3) /*HGT*/ },
    { "hcl", BIT(4) /*HCL*/ },
    { "ecl", BIT(5) /*ECL*/ },
    { "pid", BIT(6) /*PID*/ },
    { "cid", BIT(7) /*CID*/ },
};

int main(void) {
    char* line = NULL;
    size_t len = 0;
    ssize_t r = 0;
    int currpass1 = 0; // part 1
    //int currpass2 = 0; // part 2
    int valid = 0;

    while ((r = getline(&line, &len, stdin)) > 0) {
        if (*line != '\n') {
            for (int i = 0; i < 8; i++) {
                if (NULL != strstr(line, parts[i].name)) {
                    currpass1 |= parts[i].value;
                }
            }
        } else {
            valid += IS_VALID(currpass1);
            currpass1 = 0;
        }
    }

    valid += IS_VALID(currpass1);

    printf("Part 1: %d\n", valid);

    free(line);

    return 0;
}
