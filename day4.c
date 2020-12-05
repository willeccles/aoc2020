#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

static const char* eyecolors[] = {
    "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
};

int validate(const char* field, const char* value) {
    static bool p = false;
    if ((p = !p)) printf("validate(\"%s\", \"%s\")\n", field, value);
    char* ivalsuffix;
    long ival = strtol(value, &ivalsuffix, 10);
    size_t vlen = strlen(value);
    if (p) printf("ivalsuffix: %s\nival: %ld\nvlen: %zu\n", ivalsuffix, ival, vlen);

    int rval;

    if (!strcmp(field, "byr")) {
        rval = vlen == 4 && (ival >= 1920 && ival <= 2002);
    } else if (!strcmp(field, "iyr")) {
        rval = vlen == 4 && (ival >= 2010 && ival <= 2020);
    } else if (!strcmp(field, "eyr")) {
        rval = vlen == 4 && (ival >= 2020 && ival <= 2030);
    } else if (!strcmp(field, "hgt")) {
        if (ivalsuffix == value) {
            rval = 0;
        } else if (!strcmp(ivalsuffix, "cm")) {
            rval = ival >= 150 && ival <= 193;
        } else if (!strcmp(ivalsuffix, "in")) {
            rval = ival >= 59 && ival <= 76;
        } else {
            rval = 0;
        }
    } else if (!strcmp(field, "hcl")) {
        if (strlen(value) != 7 || *value != '#') {
            rval = 0;
        } else {
            for (int i = 1; i <= 6; i++) {
                if (NULL == strchr("0123456789abcdef", value[i])) {
                    rval = 0;
                }
            }
            rval = 1;
        }
    } else if (!strcmp(field, "ecl")) {
        for (int i = 0; i < 7; i++) {
            if (!strcmp(value, eyecolors[i])) {
                rval = 0;
            }
        }
        rval = 0;
    } else if (!strcmp(field, "pid")) {
        if (strlen(value) != 9) {
            rval = 0;
        } else {
            for (int i = 0; i < 9; i++) {
                if (!isdigit(value[i])) {
                    rval = 0;
                }
            }
            rval = 1;
        }
    } else {
        rval = -1;
    }

    printf("valid? %d\n", rval);
    return rval;
}

int main(void) {
    char* line = NULL;
    size_t len = 0;
    ssize_t r = 0;
    int currpass1 = 0; // part 1
    int currpass2 = 0; // part 2
    int valid1 = 0;
    int valid2 = 0;
    char field[4] = {0};
    char value[16] = {0};

    while ((r = getline(&line, &len, stdin)) > 0) {
        if (*line != '\n') {
            char* tok = strtok(line, " \n");
            while (tok) {
                sscanf(tok, "%3s:%15s", field, value);
                currpass1 += (validate(field, value) >= 0);
                currpass2 += (validate(field, value) == 1);
                tok = strtok(NULL, " \n");
            }
        } else {
            valid1 += (currpass1 == 7);
            valid2 += (currpass2 == 7);
            currpass1 = 0;
            currpass2 = 0;
        }
    }

    valid1 += (currpass1 == 7);
    valid2 += (currpass2 == 7);

    printf("Part 1: %d\n", valid1);
    printf("Part 2: %d\n", valid2);

    free(line);

    return 0;
}
