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

- the rightmost bit encodes <img src="svgs/648a3e38132a0462560d4e398df994c4.svg?invert_in_darkmode" align=middle width=47.65051004999999pt height=26.76175259999998pt/>

- so e.g.: <img src="svgs/df06bd9c46e401b679519d3ac32fc375.svg?invert_in_darkmode" align=middle width=247.85337389999995pt height=26.76175259999998pt/>

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