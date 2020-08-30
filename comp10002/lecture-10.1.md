# Lecture 10.1

- Assignment 2 explanation...

## Files (Chapter 11 from Alistair's Book)

A file is something which you can access which is outside the program.

File pointer - points to some device. Not necessary a physical "file" on a hard disk.

```c
FILE *fp = fopen("test.txt", "rwa+");
```

where `r` = read

`w` = write

`a` = appending

also `+`- `fseek` and `ftell` become available for random access

```c
printf = fprintf(stdout, ___)
scanf = fscanf(stdin, ___)
```

`stdin, stdout, stderr`

`fread()` and `fwrite()`

```c
fread(void *data_ptr, size_t size, size_t count, FILE *fstream); // returns num elements read
fwrite(void *data_ptr, size_t size, size_t count, FILE *fstream);
fclose(FILE *fptr);
```
