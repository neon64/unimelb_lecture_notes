# Lecture 10.3 - signed integer representations

## Integer data types:

`unsigned char`, `unsigned short`, `unsigned int`, `unsigned long`

- binary number (integer), non-negative

>  computer scientists can count up to 1023 with two hands
>
> with toes, you can count up to 1 million!!!!
>
>  -Alistair

but sometimes you want negative numbers.

With a 32-bit integer, largest number is ~4 billion

(hence max RAM size of 4GB by the way)

## Options for negative integers:

#### sign-magnitude encoding

- we have `0` and `-0`!!!!
  
  - ouch.
  - not a good option

#### twos-complement encoding

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



32 bits to encode numbers

`00000000 00000000 00000000 00000001 = 1`

`00000000 00000000 00000000 00000110 = 6`

`00000000 00000000 00000000 00000110 = 6`

`11111111111111111111111111111010 = -6`

`&`, `|` , `^`, `~`

Note: `020` is octal,

`0x20` is hexadecimal!!!