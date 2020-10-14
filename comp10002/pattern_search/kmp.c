#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void print_f(const char arr[], const int farr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%2c ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%2d ", farr[i]);
    }
    printf("\n");
}

bool kmp_search(char *source, char *pattern, int *f, int n, int m, int *loc) {
    int s = 0;
    int i = 0;
    while(s < n - m) {
        if(i >= m) {
            // it matches the whole pattern
            return true;
        }
        if(source[s+i] == pattern[i]) {
            i++;
        } else {
            s = s + i - f[i];
            i = f[i] < 0 ? 0 : f[i];

        }
    }
    // reached the end of the source without matching
    return false;
}

// example implementation from lecture notes
void compute_f_original(char *str, int n, int *F) {
    int pos = 2, cnd = 0;
    F[0] = -1;
	F[1] = 0;
	while (pos < n) {
		if (str[pos-1] == str[cnd]) {
			cnd += 1;
			F[pos] = cnd;
			pos += 1;
		} else if (cnd > 0) {
			cnd = F[cnd];
		} else {
			F[pos] = 0;
			pos += 1;
		}
	}
}

// my implementation
void generate_failure_function(char *pattern, int m, int **f, bool *strange) {
    assert(m >= 1);
    *f = (int *) malloc(sizeof(int) * m);
    (*f)[0] = -1;
    if(m > 1) {
        (*f)[1] = 0;
    }
    int s = 2;
    int c = 0;
    while(s < m) {
        //printf("computing F[%d]\n", s);
        //printf("comparing F[%d] = %c with F[%d] = %c: ", s - 1, pattern[s-1], c, pattern[c]);
        if(pattern[s-1] == pattern[c]) {
            c++;
            //printf("equal, F[%d] = %d\n", s, c);
            (*f)[s] = c;
            s++;
        } else if(c > 0) {
            // what does this do??
            // if c was equal
            if((*f)[c] != 0) {
                // fprintf(stderr, "f[c] wasn't equal to zero where c=%d, s=%d!\n", c, s);
                // *strange = true;
            }
            // this ends up decrementing c in a way... means we gradually work backwards to just a 1-character long substring match. if that fails, then c = 0 again, and we are looking for 1 matching letter.
            c = (*f)[c];
        } else {
            //printf("not equal\n");
            (*f)[s] = 0;
            s++;
        }
    }
}

int main(int argc, char *argv[]) {
    // char *source = "she shells sea shells at the sea shore.";
    // int n = strlen(source);
    char pattern[41];
    pattern[40] = '\0';
    for(int j = 0; j < 100000; j++) {
        for(int i = 0; i < 40; i++) {
            pattern[i] = (char) ((int) 'a') + (rand() % 26);
        }
        int m = strlen(pattern);
        assert(m == 40);
        int *f;
        int f2[40];
        bool strange = false;
        generate_failure_function(pattern, m, &f, &strange);
        compute_f_original(pattern, m, f2);

        bool matches = true;
        for(int i = 0; i < m; i++) {
            if(f[i] != f2[i]) {
                matches = false;
                break;
            }
        }
        if(!matches) {
            print_f(pattern, f, m);
            print_f(pattern, f2, m);
            return 0;
        }

        // if(strange) {
        //     print_f(pattern, f, m);
        // }
    }
    // int loc;
    // bool found = kmp_search(source, pattern, f, n, m, &loc);
    // printf("Was '%s' found in '%s'? %d", pattern, source, found);
}