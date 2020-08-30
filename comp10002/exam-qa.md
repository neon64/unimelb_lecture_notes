- file operations - the gap from this year
  - study them ! good for your soul anyway

- suffix arrays
- boyer moore
- kmp

- multiplication algorithm from one of the final lectures?

- iterative mergesort

- `static` means private to a module - but don't worry about `static` for the exam



Functions to know:

abs - stdlib.h
strcasecmp - case insensitive comparison - but NON-STANDARD C - yikes!!

tolower - ctype.h
isalpha
islnum
fabs - math.h
sin
cos
sqrt

ones to look up:

fwrite()
fread()
qsort()

> "Artem's got 10 things inside him and his parent knows that"



## Quicksort

- partitioning: zone to the left, zone in the middle (equal), zone to the right (greater)
- but does redundant swapping between less than pivot and the middle zone

- more relaxed specification - can allow things to be equal in the left side and things to be equal in the right side

```c
void qsort(data_t A[], int left, int right) {
    lo = left;
    ri = hi-1;
    // partitioning loop
    p = A[??]; // find a *particular* value that isn't the largest and isn't the smallest
    while(still things to process) {
        while(A[lo] <=p) lo++;
        while(A[hi] >=p) hi--;
        // two elements moved by one swap operation
        swap(A+lo, A+hi);
        lo++;
        hi++;
    }
    qsort(A, lo, );
    qsort(A, , );
    return;
}
```

- what's the beef with that loop?
  - loads of different cases, off by one errors, etc... are possible.
  - if you give it an array that is all the same element, then its O(n^2)?

- not on the exam!


