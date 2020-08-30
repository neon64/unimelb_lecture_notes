# Lecture 3.3

PSA: don't use global variables

```cpp

int my_global_var = 5;

void func(int x) {
    static int z = 7;
    x = x + 1;
    z = x + z + 1;
}
```