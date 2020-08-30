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

$2^n-1$ minimum moves for a tower of height $n$

Recursive solution:

Move tower of size $n-1$ from A to B

Move bottom piece from A to C

Move tower of size $n-1$ from B to C

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