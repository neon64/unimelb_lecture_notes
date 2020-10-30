# Lecture 5.2

## Typedefs

```c
typedef int data_t;

typedef struct {
    int a;
    int b;
} awesome;
```

Opaque type:

```c
typedef struct Point Point;

Point * point_new(int x, int y);
```

## Binary search

low through to high - 1

`cmp(a, b)` - where a and b are *pointers* to the data

-

### Binary search - Efficiency

<p align="center"><img src="svgs/a1816ea0dc9a4ff232c774b7630a811e.svg?invert_in_darkmode" align=middle width=229.17808485pt height=41.09589pt/></p>

Can show that solution is <img src="svgs/75324b8f78c6be9934af9f36b7567cc3.svg?invert_in_darkmode" align=middle width=250.64189205pt height=24.65753399999998pt/>

