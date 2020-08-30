# Lecture 9.2

Warnings from Alistair:
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

### Taking function pointers as arguments

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


// trick to get the length of an array
// e.g. of: `my_type_t s[1000];`
sizeof(s)/sizeof(*s)

// C allows you to cast a pointer directly to a string.
void *v1;
char **s1 = v1;
```


## Const parameters

The contents pointed to by `v1` and `v2` will not be changed over the course of this function call.

```c
int string_ascending(const void *v1, const void *v2) {
    return strcmp(*(char **) v1, *(char **) v2);
}
```

## PSA: use quicksort from the C standard library

In the real world, one just uses a pre-built quicksort implementation, for example the one from the C standard library.

```c
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
```

- `base` − This is the pointer to the first element of the array to be sorted.
- `nitems` − This is the number of elements in the array pointed by base.
- `size` − This is the size in bytes of each element in the array.
- `compar` − This is the function that compares two elements.

`compar` here is a real-world example of function pointers, as explained above ^^.

`qsort` is an example of a 'polymorphic' function (in the very manual C-sense of the word polymorphism).



