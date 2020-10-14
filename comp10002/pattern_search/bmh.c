
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define ALPHABET 256

void compute_skip_table(char *str, int n, int *skip_table) {
    for(int i = 0; i < ALPHABET; i++) {
        skip_table[i] = n;
    }
    for(int i = 0; i < n - 1; i++) {
        skip_table[(int) str[i]] = n - i - 1;
    }
}

void print_skip_table(int *skip_table) {
    for(int i = 0; i < ALPHABET; i++) {
        if(i >= (int) '!' && i <= (int) '~') {
            printf("- %c = %d\n", (char) i, skip_table[i]);
        } else {
            printf("- #%d = %d\n", i, skip_table[i]);
        }
    }
}

bool bmh(char *source, char *pattern, int* skip_table, int n, int m) {
    int s = 0;
    while(s <= n - m) {
        for(int i = 0; i < n; i++) {
            printf("%d", i % 10);
        }
        printf("\n%s\n", source);
        for(int i = 0; i < s; i++) {
            printf(" ");
        }
        printf("%s\n", pattern);
        bool matches = true;
        for(int i = m - 1; i >= 0; i--) {
            if(source[s+i] != pattern[i]) {
                int skip_amt = skip_table[(int) source[s+i]];
                printf("Skipping by %d\n\n", skip_amt);
                s += skip_amt;
                matches = false;
                break;
            }
        }
        if(matches) { return true; }
    }
    return false;
}

int main(int argc, char *argv[]) {
    int skip_table[ALPHABET];
    char *pattern = "she shells";
    int m = strlen(pattern);
    compute_skip_table(pattern, m, skip_table);
    print_skip_table(skip_table);

    char *source = "she sells sea shells by the she shells";
    int n = strlen(source);

    int res = bmh(source, pattern, skip_table, n, m);
    printf("Found = %d\n", res);
}