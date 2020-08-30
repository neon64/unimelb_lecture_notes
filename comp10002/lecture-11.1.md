# Lecture 11.1

- more on encodings

32 bits to encode numbers

`00000000 00000000 00000000 00000001 = 1`

`00000000 00000000 00000000 00000110 = 6`

`00000000 00000000 00000000 00000110 = 6`

`11111111111111111111111111111010 = -6`

`&`, `|` , `^`, `~`

Note: `020` is octal,

`0x20` is hexadecimal!!!

## Floating-point representatins

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

"Normalised encodings" => proper scientiffic

mantissa - the 1 on the LHS of equals sign never gets encoded....

To encode 2^0 - 127

2^-1 - 126

2 ^-2 - 125 etc...
