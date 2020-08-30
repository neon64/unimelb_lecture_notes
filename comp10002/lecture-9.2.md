# Lecture 9.2 -



- "most challenging lecture"

- "hardest program of the subject"





## Function pointers

```c
double (*F)(double), x = 2.0;
F = sqrt;
printf("x = %.4f F(x)=%.4f\n", x, F(x));
F = sin;
printf("") // blah blah
```





## Function arguments

```c
// won't know the type of the objects, just knows the size of them all
int is_sorted(void *A, size_t nelem, size_t size, int (*cmp)(void*, void*));

int is_sorted(void *A, size_t nelem, size_t size, int (*cmp)(void*, void*)) {
    char *Ap = (char *) A;
    while(nelem > 1) {
        if(cmp(Ap, Ap+size) > 0) {
            return 0;
        }
        Ap += size;
        nelem -= 1;
    }
    return 1;
}


// to get length of an array
sizeof(s)/sizeof(*s)

// cast to a string
void *v1;
char **s1 = v1;
```



## Const parameters?  - not explained

```c
int string_ascending(const void *v1, const void *v2) {
    return strcmp(*(char **) v1, *(char **) v2);
}
```



## Use quicksort from the C standard library



```c
qsort(array, num, size, sort_func);
```





# `treeeg.c`

counting frequency of each of the words - using a tree








