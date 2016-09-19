////////////////////////////
// Find me on port 0xbeef //
////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[10] = {0};
    char *flag;
    FILE *fp;
    int c;

    fp = fopen("/var/other/flag", "r");
    if(fp == NULL) {
        printf("opps\n");
        return 0;
    } else {
        flag = malloc(32);
        fgets(flag, 32, fp);
    }

    fgets(input, 10, stdin);

    for(c=0; c<strlen(input); c++) {
        if(input[c] == '%' && isalnum(input[c+1])) {
            printf("!!! FORMAT STRING DETECTED !!!\n");
            return 0;
        }
    }

    printf(input, flag);

    return 0;

}
