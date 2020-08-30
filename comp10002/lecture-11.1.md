# Lecture 11.1 - floating point representation

## Motivating example

`logsum.c`
$$
\sum_{i=0}^n \frac{1}{i}
$$

- after n=4 you already get differences from different formulas

1. subtracting numbers which may be close together - relative errors are magnified, absolute errors are additive

2. adding large sets of small numbers to large numbers on by one

   1. to rectify: first build up a mass of small numbers, than add those to the big number

3. comparing values which are the result of floating point arithmetic

In practice: need to use an "almost equals" comparison



## Floating-point representations

- one bit sign

- a $w_e$ bit integer exponent of 2 or 16

- a $w_m$ bit mantissa, normalised so that the leading binary or hexadecimal bit is 0

`floatbits.c`

if first bit is `0`, then +ve number, otherwise if first bit is `1`, then a -ve number

```c
-123.456 * 10^-5
|\_____/      \/
| mantissa    exponent
|
sign
```

$x = SM \cdot B^E$

"Normalised encodings" => proper scientific notation

mantissa - the 1 on the LHS of equals sign never gets encoded....

To encode 2^0 - 127

2^-1 - 126

2 ^-2 - 125 etc...


## More on precision of floating-point

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



##