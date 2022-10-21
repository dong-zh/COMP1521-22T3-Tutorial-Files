# Printer Control

## Introduction

You've been hired to write a driver to control a printer/scanner combo. The printer communicate through a series of flags that can be either 0 or 1:

- `NO_INK` (read/write): The printer sets this flag when it's out of ink. You must unset it when the ink is replaced.
- `COLOUR` (write): When set, the printer will scan or print in colour. This flag is controlled by you.
- `SELECT_PRINT` (write): You set this flag to select printing mode.
- `SELECT_SCAN` (write): You set this flag to select scanning mode.
- `START` (read/write): You set this flag to do the selected task (print or scan). The printer will unset this when it's finished.

Don't worry about how the actual file gets to and from the printer.

One way to implement this is to have a variable for each flag:

```c
int NO_INK = 0;       // Ink levels OK
int COLOUR = 1;       // Printing/scanning in colour
int SELECT_PRINT = 1; // Print mode selected
int SELECT_SCAN = 0;  // Scan mode not selected
int START = 0;        // Printing/scanning hasn't started
```

However, this is a waste of space, and in hardware, every bit matters! Each variable takes up 32 bits, but we only need to store 1 bit of information for each flag. Instead, we can pack all those flags into a single 8 bit (1 byte) integer, and use the individual bits to represent the flags:

```text
printerControl = 0 0 0 0 0 0 0 0
                       ^ ^ ^ ^ ^
                       | | | | |
                       | | | | L [NO_INK]
                       | | | L [COLOUR]
                       | | L [SELECT_PRINT]
                       | L [SELECT_SCAN]
                       L [START]
```

The most significant 3 bits are unused.

In C, that would look like:

```c
uint8_t printerControl = 0;

#define NO_INK (0x1)       // 0b 0000 0001
#define COLOUR (0x2)       // 0b 0000 0010
#define SELECT_PRINT (0x4) // 0b 0000 0100
#define SELECT_SCAN (0x8)  // 0b 0000 1000
#define START (0x10)       // 0b 0001 0000
```

## Questions

*For the following questions, assume the C code above is included globally. Don't change any other flags.*

Write a function:

1. that prints (to terminal) whether it's out of ink.
2. that tells the printer the ink has been replaced.
3. to use colour and select scan mode. Assume no mode has been selected yet.
4. that toggles between print and scan mode. Assume 1 mode is already selected.
5. to start printing/scanning. It should:
   1. check that 1 (and only 1) mode is selected
   2. there's ink if printing.
   3. print (to terminal) what it's doing and any error messages.
   4. wait until the printing/scanning is finished and print a 'finished' message.
