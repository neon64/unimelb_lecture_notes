# Lecture 11.2

#### 

More precision of floating-point stuff...

1 / 10 = `.000110011001100110011001100...` in binary - therefore you won't get an exact representation!!

```c
floatbits 0.1
        00111101 11001100 11001100 11001101
         ------- - 
       the exponent
                  ----------------------------
                      the mantissa
```

can only encode a **finite** number of floating point bits

23 bits of mantissa

8 bits of exponent

1 bit of the sign

- also note: the C preprocessor

## Lec11 - Problem-solving, algorithms and more

1. Generate and test

2. Divide and conquer
   
   1. Subset sums
      
      - Is there a subset of the following numbers that adds up to exactly 1,000?

## Subset sum

```c
int subsetsum(int A[], int n, int k) {
    if(k == 0) {
        return 1;
    } else if(n==0) {
        return 0;
    } else {
        return subsetsum(A, n-1, k-A[n-1]) || subsetsum(A, n-1, k)
    }
}
```

- worst case grows - exponentionally

- we haven't developed better algorithms to solve these problems, because they just have exponential complexity

- another one is solving all constraints for e.g.: exam timetabling
