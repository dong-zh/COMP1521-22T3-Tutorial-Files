# MIPS Functions

## The Problem

Since we have only of 32 integer registers, functions introduce a problem where we have to somehow share these registers across different functions in a systematic way. The solution is not to share, but to put certain registers onto the stack. This is called the MIPS function calling convention.

## MIPS Function Calling Convention

Convention says that `$ra` and `$s` registers must preserve their value across a function call. This means every time you use a `$s` register in a function, you *must* store it onto the stack at the top of your function, and load it back at the bottom. In addition, you'll also need to save `$ra` as well since using the `jal` instruction changes `$ra`.

What this also effectively means, is `$t` and `$a` registers are assumed to be reset after every `jal`. So, if you're not sure whether whether to use `$t` or `$s` registers, think to yourself: 'at every `jal`, would my program break if every `$t` and `$a` register was reset?' Alternatively, you can use this flowchart:

![Flowchart showing when to use `$s` vs `$t` registers](sRegs.png)

So, a typical function in MIPS looks like this:

```mips
myFunction: # In the caller, you'd jump and link to this label
myFunction__prologue: # This is where we store registers onto the stack
        begin
        push    $ra
        push    $s0
        push    $s1
        # Push any other $s registers you use

myFunction__body:
        # Do stuff

myFunction__epilogue: # This is where we load the values back from the stack
        # Pop any other $s registers you use, notice the ordering is reversed
        pop     $s1
        pop     $s0
        pop     $ra
        end
        jr      $ra
```

Remember this quote:

> For every `push` that's executed, there must be an equal and opposite execution of `pop`

\- Isaac Newton (probably)

One common mistake is, when people see an early return in a function that has a stack, they put `jr $ra`. If you do that, the `pop`s never get executed. Instead, you should `b function__epilogue` and have a single `jr $ra` at the epilogue.
