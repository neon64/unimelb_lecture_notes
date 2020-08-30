# Lecture 2.3

```c

int n, cycles, max;
if (scanf("%d", &n)) != 1) {
    exit(EXIT_FAILURE);
}
```


- careful of #define, its literally dumb string replacement with no macro huygeine.


```c
while (scanf("%d", &next) == 1) {

}
// will terminate with control+D, or strings or any other invalid sort of input
```

always break input by pressing control+D

## Fortran example - reading from stdin

```fortran

 100 DO 300 I=1, 1000
C    Comments go here...
 300 K + K + 1
 ```

 `fortcomm` - removes comments

 ```c

 int main(int argc, char *argv[]) {

    int ch, incomment=0, newlinelast=1;
    while ((ch=getchar()) != EOF) {
        if (ch == 'C' && newlinelast) {
            incomment = 1;
        }
        if (!incomment) {
            putchar(ch);
        }
        if (ch == '\n') {
            incomment=0;
            newlinelast = 1;
        } else {
            newlinelast = 0;
        }
    }
```


avoid `do while` loops
