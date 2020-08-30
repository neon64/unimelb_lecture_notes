# Lecture 5.3

## Chapter 7 - Strings and Algorithms

strings = array of characters, null terminated

- strings are carried out using character pointers

libraries

```c
<ctype.h>

isalpha()

#include <string.h>

int strlen(char *s)
// WARNING: dest must be large enough to accomodate src, plus a null byte
// returns a pointer to dest
char *strcpy(char *dest, char *src)
char *strncpy(char *dest, char *src, int n)
// 
int strcmp(char *s1, char *s2)
// upper/lower case are considered equal
int strcasecmp(char *s1, char *s2)
// appends copy of src to dest by overwriting null byte, copying chars, then adding a new null byte
char *strcat(char *dest, char *src)

#include <stdlib.h>

int atoi(char *s)
double atof(char *s)
```

```c
malloc() // used to create space for new strings!
```

Example using pointers instead of arrays:

```c
#define N 5

int main() {
    int A[N], *p, i;
    for (i=0; i<N; i++) {
        A[i] = i*(i+1)/2;

    }
    printf("A %10p\n", A);
    p = A;
    // pointer steps through memory by the number of bytes of the thing it is pointing at
    for(p=A; p < A+N; p++) {
        printf("p = %10p, *p = %2d\n", p, *p);
    }
    return 0;
}
```

"that's the point[er] I'm trying to make. that was a pointless joke"

with strings:

```c
int main() {
    char *p = "A&A are just the best :-)";
    // while it is not equal to \NUL
    while(*p) {
        printf("p = %12p, string at p = %s\n", p, p);
        p = p + 1;
    }
    return 0;
}
```

```c
words < words.c
```

"Feels a little bit incestuous, but its just a file its okay."

```c
// not creating a variable, rather naming a type
typedef char word_t[MAXCHARS + 1]; // every string has to be terminated by a null byte
int getword(word_t W, int limit);
```

```c
while(getword(one_word, MAXCHARS) != EOF) {

}
```
