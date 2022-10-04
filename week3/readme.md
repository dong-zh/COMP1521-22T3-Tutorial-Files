# MIPS Memory and Addressing

Now that we've learnt about registers, what do we do if we need to store things that don't fit in registers, like for example, an array? The answer: store it in RAM. However, since almost all of our MIPS instructions operate on registers, we must first load the instructions from memory. This can be done with the following instructions:

- `lb`: load byte
- `lh`: load half word (2 bytes)
- `lw`: load word (4 bytes)
- `ld`: load double word (8 bytes)

All these instructions have a similar usage syntax. Let's use `lw` as our example since that's the most common one:

```mips
# General syntax
lw      $destinationRegister, address
```

Where `address` can be any of the following forms [here](https://cgi.cse.unsw.edu.au/~cs1521/22T3/resources/mips-guide.html#syntax) (see the 'address operand' table), and `$destination` is the register that you want to load data into.

## Addressing Modes

### `label`

```mips
lw      $t0, myVar
```

This will load a word starting from the label `myVar`. For example, if `myVar` is referencing address `0x10010000`, then the line above will load 4 bytes from `0x10010000` into `$t0`. Useful when you have to operate on a variable in memory that's referenced by a label.

### `($register)`

```mips
lw      $t0, ($t1)
```

This will load a word from the address stored inside `$t1`. The parentheses around `$t1` mean 'treat the value inside `$t1` as an address'. So, if `$t1` holds `0x10010004`, the instruction above will load 4 bytes from `0x10010004`. Useful when doing address calculations.

### `immediate($register)`

```mips
lw      $t0, -4($sp)
```

This will load a word from address (-4 + the value inside `$sp`). So, if `$sp` holds `0x10010004`, the instruction above will load 4 bytes from `0x10010000`. Useful for stack loads and stores.

### `label($register)`

```mips
lw      $t0, myArr($t1)
```

This will load a word from address (`myArr` + the value inside `$t1`), where `myArr` is a label. So, if `myArr` is at address `0x10010004` and `$t1` holds 8, then the instruction above will load 4 bytes from `0x1001000c`.

### `label +/- immediate`

```mips
lw      $t0, myArr + 8
```

This will load a word from address (`myArr` + 8), where `myArr` is a label. So, if `myArr` is at address `0x10010004`, the instruction above will load 4 bytes from `0x1001000c`.

### `label +/- immediate($register)`

```mips
lw      $t0, myArr + 8($t1)
```

This will load a word from address (`myArr` + 8 + the value inside `$t1`). So, if `myArr` is at address `0x10010004` and `$t1` holds 8, the instruction above will load 4 bytes from `0x10010014`.

## Storing Data into Memory

To store data, instead of using load instructions, we use store instructions like `sb`, `sh`, `sw`, and `sd`. The syntax for these instructions are the same as before, in a deceiving way.

```mips
sw      $sourceRegister, address
```

It's deceiving because the ordering is backwards from intuition. Normally, the object on the right is placed into the object on the left. This is the case with almost all MIPS instructions, including the load instructions. With store, it's the other way around. The value in the source register on the left is placed into the memory address on the right.

## Arrays

Arrays are a a contiguous block of memory. You're usually given a label that references the start of an array, and you have to figure out the offset from the start to get to an element. To calculate the offset, multiple the size of each element (in bytes) with the index.

For example, let's say we wanted to stored the number 42 into the 8th index of an integer array (`my_array[8] = 42`). Let's assume in MIPS, `my_array` can be referenced with a label of the same name. So, what do we do?

First, we must figure out where's the source, and where's the destination. In our case, the source is 42, an immediate, and the destination is an array, which lives in memory. Looking at [this](Instructions%20to%20Move%20Stuff%20Around.pdf) diagram, we see we must first `li` the immediate into a register, then `sw` it into memory. We use `sw` because an integer is 4 bytes, which is the size of a word.

While the `li` part is easy enough, to store something into RAM, we need an address. We already have the address of the start of the array, so we just need to find the offset (how many bytes is the 8th index away from the array's start). We can use the formula 'size of each element * index'. The size of an integer is 4 bytes, and the index is 8, which gives us 32 bytes. Hence, the address of `my_array[8]` is `my_array + 32`.

The actual MIPS code looks like this:

```mips
li      $t0, 42                 # Load 42 into $t0
sw      $t0, my_array + 32      # Store it into my_array[8]
```
