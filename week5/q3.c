#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint16_t a = 0x5555;
	uint16_t b = 0xaaaa;
	uint16_t c = 0x0001;

	printf("a: 0x%x\n", a | b);
	printf("b: 0x%x\n", a & b);
	printf("c: 0x%x\n", a ^ b);
	printf("d: 0x%x\n", a & ~b);
	printf("e: 0x%x\n", c << 6);
	printf("f: 0x%x\n", a >> 4);
	printf("g: 0x%x\n", a & (b << 1));
	printf("h: 0x%x\n", b | c);
	printf("i: 0x%x\n", a & ~c);
}
