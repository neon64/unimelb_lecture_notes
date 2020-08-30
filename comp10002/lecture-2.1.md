# Lecture 2.1

```c
#include <stdio.h>

#define MARY "Mary, Mary, quite contrary"

int main(int argc, char *argv[]) {
    int n = 12345;
    double x = 3.141592;
    char c='a';
    printf("%d  %3d  %6d  %-6d\n", n, n, n, n);
    printf("%f  %.4f  %6.2f  %-6.2f\n", x, x, x, x);
    printf("%c  %d  %c\n", c, c, c + 3);
    printf("%s\n%50s\m%-50s\n, MARY, MARY, MARY);
    return 0;
```

 - Relational and logical expressions are of type `int`.
 - Non zero is interpreted as `true`.
 - Zero is `false`.
 - No boolean type / constants.
 - There is no `elif` you need to write `else if`.
 -

```c
length_of_year = 365;
length_of_feb = 28;
if (year%4==0 && (year%100 != 0 || year%400==0)) {
    length_of_year += 1;
    length_of_feb += 1;
}
```

- note, that `&&` and `||` are evaluated in left to right order - you can safely rely upon this.

```c
if (month == 2) {
    length_of_month = length_of_feb;
} else if (month == 4 || month == 6 || month == 9 | month == 11) {
    length_of_month = 30;
} else {
    length_of_month = 31;
}
```


```c
switch (month) {
    case 2:
        ____
        break;
    case 4:
    case 9:
        length_ = _;
        break;
    default:
}
```