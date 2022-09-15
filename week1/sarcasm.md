# sArCaSm!

## Background

On the internet, there are usually 2 ways to convey sarcasm:

1. Using a `/s` at the end of your sentence ('NFTs are a great investment /s')
2. Writing your sentence in alternating casing ('nFtS ArE A GrEaT InVeStMeNt')

Hong Duang is a computing student at UNSW. He spends his spare time getting into pointless arguments on Twitter. Hong recently finished COMP1511 and wishes to use his C programming skills to 'good use'.

## Task

Write a C program that:

1. Takes a string as a command line argument
2. Converts the letters to sarcastic casing (ignoring whatever casing the string already had)
3. Prints it out to terminal (`stdout`)

### Desired Usage

```sh
$ ./sarcasise 'hello world'
hElLo wOrLd
$ ./sarcasise 'HELLO WORLD'
hElLo wOrLd
$ ./sarcasise 'NFTs are a great investment!!11!!!'
nFtS ArE A GrEaT InVeStMeNt!!11!!!
```
