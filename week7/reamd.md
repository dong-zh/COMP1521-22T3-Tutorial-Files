# 2's Complements and Floats

## 2's Complement

- 2's complement is how we represent negative integers in binary
- It allows us to subtract numbers by simply adding a negative number
- We don't have to design a new subtracting circuit in the CPU
- There's only 1 way to write 0

## IEEE 754 Floating Point

- First bit is the sign
- Next 8 bits is the biased exponent (actual exponent + 127)
- Last 23 bits is the mantissa
- Denormalised numbers
