# Lecture 3.2

- recursive functions

```c
return(0);

// vs

return 0;
```

```c

int eeee(int x) {
    if(x == 0) {
        return 0;
    } else {
        return oooo(x - 1);
    }
}

int oooo(int x) {
    if(x == 0) {
        return 1;
    } else {
        return eeee(x - 1);
    }
}
```

## Towers of Hanoi

three columns

[Wikipedia](https://en.wikipedia.org/wiki/Tower_of_Hanoi)

<img src="svgs/fe9381b12bf563bf6fe9b69a65836f30.svg?invert_in_darkmode" align=middle width=45.47754749999999pt height=21.839370299999988pt/> minimum moves for a tower of height <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>

Recursive solution:

Move tower of size <img src="svgs/efcf8d472ecdd2ea56d727b5746100e3.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> from A to B

Move bottom piece from A to C

Move tower of size <img src="svgs/efcf8d472ecdd2ea56d727b5746100e3.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> from B to C

-> now everything is on place C

```c
void hanoi(char from, char via, char to, int n) {

    int i;
    if (n <= 0) {
        return;
    }
    hanoi(from, to, via, n -1);
    for(i=1;i<n; i++) {
        printf("    ");
    }
    printf("Moving a disk from %c to %c\n", from, to);
    hanoi(via, from, to, n - 1);
}
```