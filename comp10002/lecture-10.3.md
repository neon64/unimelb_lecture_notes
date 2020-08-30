# Lecture 10.3

more on limited precision floating-point!!

`logsum.c`

$$
\sum_{i=0}^n \frac{1}{i}
$$

- after n=4 you already get differences from different formulas
1. subtracting numbers which may be close together - relative errors are magnified, absolute errors are additive

2. adding large sets of small numbers to large numbers on by one
   
   1. to rectify: first build up a mass of small numbers, than add those to the big number

3. comparing values which are the result of floating point arithmetic

use an "almost equals" comparison

## word

- four or eight bytes
  
  - isn't it always 16 bits??

`char`, `short`, `int`, `long`

- binary number

- computer scientists can count up to 1023 with two hands

- with toes, you can count up to 1 million!!!!

but sometimes you want negative numbers, and also different number of bits per thingo

32-bit integer, largest number is ~4 billion

(hence max RAM size of 4GB)

sign-magnitude encoding

- we have `0` and `-0`!!!!
  
  - ouch

twos-complement encoding

- the rightmost bit encodes $-2^{w-1}$

- so e.g.: $1 \times -2^{3} + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 $

- then you can just do straightforward binary addition! nice...

remember a program called `overflow.c` from week 1??

```c
int big = ____;
int bp1 = big + 1;
int bt2 = big * 2;
int bp1t2 = bp1 * 2;
```

how to flip a binary number?

```c
00011010 = 26
11100110 = -26

so that

  00011010
+ 11100110
----------
 100000000 which is zero if you discard the overflow bit
```

therefore signed integers are more like a closed loop - if you keep adding 1 you will eventually get back to where you started!!

```c
unsigned char 
unsigned short
unsigned int %u
unsigned long %lu
unsigned long long %llu (at least 64 bits)
```
