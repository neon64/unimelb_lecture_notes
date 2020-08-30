# Lecture 1.3 - Getting Started With C

## C origins

- 1969-1973 - Dennis Ritchie, at Bell Labs

- high level control, direct mapping to hardware
- relatively light execution
- applications and systems programming
- standards activity

How to compile:

```shell
gcc -Wall -o helloworld helloworld.c
./helloworld
```

## Starting point

```c
/* Comment */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    double x;
    scanf("%d %lf", &n, &x);
    printf("n=%d, x=%f\n", n, x);
    return 0;
}
```



**Chapter 2:** arithemtic operators, precedence, int vs double, scanf, printf

**Chapter 3:** logical operators

**Chapter 4:** for and while

**Chapter 5:** functions



## `overflow.c`

- why does he do declaration and assignment on seperate lines??



```c
%d = decimal integer
%f = floating point
%lf = double (only for scanf)
```



- first issue, integers overflow!! - without any exception





"C is like a chainsaw"





## `rounding.c`

```c
double x, y, z;
```

- floating-point has an exponent and a mantissa



```c
%23.20f - 23 chars total, 20 after decimal point
\n - newline
```



rounding with a float:

0.1 => 0.100000000000000555





## `addorder.c`



- subtraction of 4.5678 and 1.23e16 - leads to great error



## `mysphere.c`

```c

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

int main(int argc, char *argv[]) {
    double radius, volume;
    scanf("%lf", &radius);
    volume = (4.0/3.0)*PI*radius*radius*radius
    printf("sphere of radius %.2f has volume %.2f\n",
           radius, volume);
    return 0;
}
```



`4 / 3` - integer division

`4.0 / 3.0` - float division



## Key takeaways

- use #define for all constants

- integer division traps

- float rounding




