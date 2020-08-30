# Lecture 8.1

## Arrays and structs

array - homogeneous-typed data is aggregated, with individual elements identified by *ordinal position*, 0,1,2,3,4,5

struct - heterogeneous-typed data is aggregated, identified by *component name*

```c
int print_struct(my_struct_t *one_struct) {
    // do something with it
}

int read_planet_ptr(planet_t *planet) {

}
```

## `->` operator

`x->y` shortcut for `(*x).y`