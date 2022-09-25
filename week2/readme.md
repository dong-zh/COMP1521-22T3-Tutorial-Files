# Assembly and MIPS

## What is Assembly

- When we write C, we're just writing ASCII letters into a text file.
- A CPU doesn't understand C code, they only understand machine code (binary).
  - Although modern CPUs are extremely complicated, you can think of each 1 and 0 corresponding to whether a wire should be turned on or off.
  - There are many different machine code [instruction sets](https://en.wikipedia.org/wiki/Instruction_set_architecture). some examples include:
    - [x86-64](https://en.wikipedia.org/wiki/X86-64#AMD64), which most desktop and laptop CPUs use. Your CPU uses the x86-64 instruction set if it's from Intel or AMD.
    - [ARM](https://en.wikipedia.org/wiki/ARM_architecture), which most mobile CPUs use. If you have an iPhone, Apple's 'A' series processors use the ARM architecture, Qualcomm's Snapdragon and Samsung's Exynos CPUs also use ARM. Notably, Apple's M1 CPUs for laptops and desktops also use ARM.
    - [MIPS](https://en.wikipedia.org/wiki/MIPS_architecture), which we're learning in this course. Some devices that had a MIPS CPU include the Nintendo 64, Sony PS1, Sony PS2, and Sony PSP. These days, MIPS CPUs are only found in embedded systems like vehicles, and networking equipment.
    - [RISC-V](https://en.wikipedia.org/wiki/RISC-V#Implementations), a relatively new and completely open source architecture.
- So, in order to run a C program, it must first be compiled to machine code with a compiler like `dcc`, `gcc`, or `clang`.
- Since we don't want to write raw machine code, we have something called assembly code. It's like a more human readable way of programming a CPU.
  - For example, instead of writing `00000000010001010011000000100000`, we can write `add $6, $2, $5`, which is raw assembly.
  - One line of raw assembly translates to 1 line of machine code.
  - In this course, we learn MIPSY assembly. It's like raw MIPS assembly but much easier to learn and program in.
  - Instead of `add $6, $2, $5`, we'd write `add $a2, $v0, $a1`

## A Basic Introduction to the MIPS Architecture

*Always have [this page](https://cgi.cse.unsw.edu.au/~cs1521/22T2/resources/mips-guide.html) open when you're writing MIPS!*

### How to Run a MIPS Program

- Since your computer (probably) doesn't have a MIPS CPU, we emulate one in software using `mipsy`.
- To run a MIPS program on CSE:

  ```bash
  # mipsy
  1521 mipsy file.s
  ```

- [Mipsy Web](https://cs1521.web.cse.unsw.edu.au/mipsy/) is an online IDE for writing and debugging assembly.
- I recommend using Mipsy Web for debugging over `mipsy` on the command line unless you've already have experience with command line debuggers like `gdb`.

### Registers

- The MIPS architecture has 32 general purpose registers: `$0` to `$31`, each being 32 bits. However, you should *not* use the raw register numbers when you're writing MIPS. You should always use their names instead (e.g. use `$t0` instead of `$8`).
- Since we only have 32 registers, we need to share them with the kernel and assembler. We don't want the assembler to accidentally write all over our data, nor do we want to accidentally overwrite the kernel's data.
- This is why we have register conventions. Registers are given names to remind us of their intended purpose.
- `$t` registers are the ones you should be using for general use in a function.
- `$s` registers will be discussed in a later week. Avoid them for now.
- `$a` registers are for function arguments. If you want to pass something into a function, you should put it in the `$a` registers
- `$v` registers are for function returns. If you call a function that returns something, expect to find it in the `$v` registers. The only exception to this is `syscall`.
- `$at` and `$k` registers are reserved for the assembler and kernel respectively. You shouldn't use them but there are no circuits stopping you from using them.
- `$zero` is physically impossible to change. It's hardwired be to 0.
- `$sp`, `$fp`, and `$gp` have a special purpose, and you shouldn't use them unless you *really* know what you're doing.

### MIPS Instructions and Branching

- Most MIPS instructions operate on registers. See the SPIM documentation for the full list of instructions.
- Conditions and loops can be implemented in assembly using branches.
- To convert an `if` to assembly, first, consider using `goto` in C as that's all we have in assembly.
  - For example:

    ```c
    if (x == 42) {
      x = 0;
    } else {
      x = 1;
    }
    ```

    becomes

    ```c
    if (x >= 42) goto x_ge_42;
    goto x_lt_42;

    x_ge_42:
    x = 0;
    goto x_end;

    x_lt_42:
    x = 1;

    x_end:
    ```

  - Sometimes, we can save ourselves a `goto` by checking the opposite condition. This works for simple `if` statements, but if you try this on complex `if` statements with many `else if`s, you might make it even more compleicated.

    ```c
    if (x < 42) goto x_lt_42;

    x_ge_42:
    x = 0;
    goto x_end;

    x_lt_42:
    x = 1;

    x_end:
    ```

    In assembly, that's

    ```mips
            # Assume $t0 is x
            blt     $t0, 42, x_lt_42
    x_ge_42:
            li      $t0, 0
            b       x_end
    x_lt_42:
            li      $t0, 1
    x_end:
    ```

- Loops follow a similar idea. You must implement loops using only `goto`s.
  - Consider the following `for` loop.

    ```c
    for (int i = 0; i < 5; i++) {
            // Do stuff
    }
    ```

    Instead of asking yourself 'under what condition should I keep looping', turn that into 'when should I exit the loop'. This means flipping the condition around (be careful, the logical opposite of `<` is `>=`).

    ```c
    i_init:
    ;
    int i = 0;
    i_cond:
    if (i >= 5) goto i_end;
    i_body:
    // Do stuff
    i_step:
    i++;
    goto i_cond;
    i_end:
    ```

    Sometimes, you need to add a semicolon after a label due to a weird C thing.

  - I like to use lots of labels for `for` loops, so I would do the following. The minimum amount of labels you need are 2:

    ```c
    int i = 0;
    i_cond:
    if (i >= 5) goto i_end;
    // Do stuff
    i++;
    goto i_cond;
    i_end:
    ```

### `syscall`

- Whenever we want to read or print to terminal, we must ask system for help.
- The system can do many other things, like file manipulation and memory allocation. See the SPIM documentation for more details.
- This is done by doing a `syscall`. To perform a `syscall`, you must first set it up.

  1. Tell the system which `syscall` you want it to do (check the SPIM documentation) by loading the code into `$v0`. `syscall` kind of breaks convention because `$v0` is usually the return value from a function.
  2. Depending on which `syscall` is being performed, it might need an argument. Put the argument in `$a0`. For example, when printing a string, put the string's address inside `$a0`.
  3. Do the syscall by writing `syscall`

- For example, to print the number 42:

  ```mips
        li      $v0, 1  # syscall code 1 is print int
        li      $a0, 42 # put the number to print inside $a0
        syscall         # do the syscall, the printing happens on this line
  ```
