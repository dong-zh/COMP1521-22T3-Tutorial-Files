# Files

See [`file.md`](file.md) for the difference between inode numbers, file descriptors, and file pointers. Also see the bottom of [`testFile.txt`](testFile.txt) for a brief description of `whence` in `fseek()` and `lseek()`.

## Why are We Learning Files?

Everything in Linux is a file. Regular files, like text, images, executables, videos etc. are obviously files, but devices like the terminal and the webcam are also files. Therefore, it's important for us to know about how to interact with files in C.

## Common C Functions for File Manipulation

Please read the `man` page or search online for more details.

### Functions that Use File Descriptors

File descriptors should be avoided unless for pipes and low level operations, see [here](file.md) for more info.

- `open()`: opens a file and returns a file descriptor
- `read()`: reads a set number of bytes from an open file descriptor
- `write()`: writes a set number of bytes from an open file descriptor
- `lseek()`: moves the 'cursor' around in the file, kinda like moving the blinky cursor in a text editor
- `close()`: closes the file

### Functions that Use File Pointers (`FILE *`)

These functions are essentially wrappers around system calls. Again, see [here](file.md) for more info.

- `fopen()`: opens a file a returns a file pointer
- `fgetc()`: same as `getchar()` but you must specify a file rather than defaulting to `stdin`
- `fscanf()`: same as `scanf()` but you must specify a file rather than defaulting to `stdin`
- `fprintf()`: same as `printf()` but you must specify a file rather than defaulting to `stdout`
- `fputc()`: same `putchar()` but you must specify... (you get the idea)
- `fseek()` same as `lseek()`, but uses a file pointer rather than a file descriptor
- `fclose()`: closes the file

Notice how file functions starting with 'f' should be use file pointers obtained from `fopen()`.

Obviously these aren't the full list of file functions, see the `man` page or search online for more info.

## Opening a file with `fopen()`

In order to do anything to a file, you must open it first. You should use `fopen()` most of the time. For more information about `fopen()`, please read the `man` page by running `man 3 fopen`. The general syntax goes like this:

```c
FILE *myFile = fopen("path/to/file", "r");
```

`fopen()` takes in 2 arguments: the path to the file and whether to open it in reading, writing, or appending. The example above opens a file in reading mode. `fopen()` then returns a file pointer (`FILE *`). This pointer points to a struct which the C library uses for bookkeeping. You shouldn't concern yourself with what it's pointing to. The pointer represents the file you've just opened, and all you do is pass this pointer to other functions like `fscanf()`, `fgetc()`, `fgets()`, and `fread()`. Once you're done, remember to close it with `fclose()`.
