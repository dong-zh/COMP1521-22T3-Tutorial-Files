# Week 9

This week's tutorial is halfway between the files topic and concurrency. The Kahoot had some revision about file permissions, and some stuff about the difference between a process and a thread (which you can read about in [processesVsThreads.md](processesVsThreads.md)).

## File Permissions

Please see the first page of [drawings.pdf](drawings.pdf) for the relevant diagram.

When you look at file permissions in Linux, you'll probably see 3 sets of `rwx`.

- `r` stands for read permission, i.e. you can open and see what the file contains
- `w` stands for write permission, i.e. you can change the contents of the file
- `x` stands for execute permission, i.e. you can execute the file, this is more relevant for executables (programs you compile with `dcc`)

A typical set of permissions look like the following:

```text
rw-r--r--
```

The first set of `rwx` apply to the owner of the file. This is typically the person that created the file.

The second set apply to the group. The group is rarely used for a typical user. By default, the group is yourself. One example where this might become useful is if there was a group with all the COMP1521 tutors. There might be a file called `exam.txt`, and the lecturer is the owner. He might give himself read and write permission, but only give the tutor group read permission.

The last set applies to everyone else, often called the public or other permission. In the `exam.txt` example, others might have no permission, because the lecturer doesn't want anyone else looking at the exam early.

One cool thing about file permissions is they can be represented in binary. For example, as long as you remember the ordering, in the column where there's permission, put a 1, and put a 0 where there's no permission.

```text
rw-r--r--
110100100
```

This is one of the few applications of octal! Each set of permissions is 3 bits, and each octal digit represents 3 binary bits. Hence the above can be represented in octal as

```text
rw-r--r--
110100100
6  4  4
```
