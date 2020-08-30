# Lecture 4.1 - arrays and sorting

```cpp
#define N 5

int main(int argc, char *argv[]) {
    int A[N], i;
    for (i = 0; i < N; i++) {
        A[i] = i * (i+1) / 2;
    }
    for (i = 0; i < N; i++) {
        printf("A[%d]=%d  ", i, A[i]);
    }
    return 0;
}
```

- 25 million integer variables numbered from 0 to 24999999

"one day when I'm old I'm going to set up an digital art show with this, and people are going to walk over and just say 'wow'"

- **no** execution time bounds-checking

## Arrays

In K&R C, arrays must be sized at compilation time, in 1990 standard C, that restriction is lifted in functions - the array size ay be an `int` function parameter.

The notation `A[i]` is merely a shorthand for `*(A + i)`

Functions cannot return arrays.

Function prototypes

```cpp
int read_int_array(int A[], int n) {
    // body goes here
}
```

Read into array with post-increment operator...

```cpp
A[n++]
```
