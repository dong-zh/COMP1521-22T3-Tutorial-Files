# Inode Number vs File Descriptor vs File Pointer

## Inode number

- As the name suggests, it's just a number
- Used by the file system
- Used by the OS
- Keeps track of what files are on your file system
- Every file in your file system has a unique inode number
- Kinda like a file ID

## File Descriptor

- It's just a number
- Every process has its own set of file descriptors
- Used to keep track of what files your process has opened
- e.g. when you open a file (using `open()`) for writing, you get a new file descriptor which you use to refer to that file
- Low level system calls like `read()`, `write()`, `lseek()` take in a file descriptor
- By default, every process has 3 files already open
  - `stdin`, with file descriptor 0
  - `stdout`, with file descriptor 1
  - `stderr`, with file descriptor 2
- You should use file pointers instead unless you're doing low level programming (like when you're using pipes)

## File Pointer (`FILE *`)

- A file pointer is a nice abstraction provided by the C standard library so it's easier to work with files
- Essentially a wrapper around a file **descriptor**
- The pointer actually points to a fancy struct containing information about your file
- You get one by calling `fopen()` (which is a wrapper around `open()`)
- You don't need to know what's in that struct
- Higher level functions like `fgetc()`, `fscanf()`, `fprintf()`, `fseek()` use file pointers
- In general, functions that use file pointers are easier to work with than those that use file descriptors
- If you've already opened a file with `open()` and have a file descriptor, you can turn it into a file pointer by using `fdopen()`
