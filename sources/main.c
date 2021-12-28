#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *(*fxn)(char *);

char *strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str) {
        return str;
    }

    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

char *donothing(char *str) {
    return str;
}

void str2BEhex(const char * string) {
    printf("0x");
    for(int i=0; i<strlen(string); i++) {
        printf("%02x", string[i]);
    }
    printf("\n");
}

int main(int argc, char ** argv, char ** env) {
    if (argc != 2) {
        printf("Invalid number of arguments! Requires 1 parameter.\n");
        return 0;
    }

    fxn preprocess_parameter = &donothing;
    if (NULL != getenv("ENDIANNESS") && 0 == strncmp(getenv("ENDIANNESS"), "LE", 2)) {
        preprocess_parameter = &strrev;
    }
    str2BEhex(preprocess_parameter(argv[1]));
    return 0;
}
