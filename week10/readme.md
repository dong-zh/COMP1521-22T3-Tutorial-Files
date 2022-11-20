# Multithreaded Programming

The key thing to understand with concurrency is that, the OS could switch to another thread at any time, and it might be a very long time before your thread gets another turn on the CPU. Hence, if you have some shared resource across multiple threads, you might need tools like mutexes to execute a block of code atomically.

## Concurrency vs Parallelism

See [here](q2.md) for more information.

## Mutual Exclusion

In question 7, we had 2 threads trying to increment `globalTotal` in the function `add5k()`. The trouble is, `globalTotal++` isn't one instruction. In MIPS that'd be something like:

```mips
        .data
        # Global variable is in memory
globalTotal:
        .word   0

        .text

        # ...

add5k:

        # ...

        # The instructions below represent globalTotal++
        lw      $t0, globalTotal
        addi    $t0, $t0, 1
        sw      $t0, globalTotal
```

See how this simple `globalTotal++` line ends up being 3 assembly instructions? The CPU can suddenly decide to switch to another thread between those instructions. So if thread 1 gets switched out just before `sw`, then thread 2 runs to completion, then thread 1 gets switched back in and runs to completion, `globalTotal` only gets incremented by 1 despite the code being run twice.

The way we fix this is with mutual exclusion. We want to make that region of code mutually exclusive, and one of the ways to solve this is with a lock. In [q7Mutex.c](q7Mutex.c), we added a lock around `globalTotal++`, that means, for a thead to enter that block of code, it must acquire the lock. If a thread can't acquire a lock, it just sits there waiting until the lock is available.

## Deadlocks

The last page of [drawings.pdf](drawings.pdf) shows an example deadlock scenario. If thread 1 gets switched out just above `lock(m2)`. At that point, thread 1 has acquired lock 1, but not lock 2. When thread 2 starts, it successfully acquired lock 2, but can't acquire lock 1 because it's being held by thread 1. Thread 2 is stuck waiting, so the OS switches to thread 1, but thread 1 can't make any progress since it needs to acquire lock 2. Since both threads are waiting for a resource only the other thread has, we're stuck in a deadlock.

Note that if thread 1 could run to completion without being switched out, the deadlock wouldn't occur.
