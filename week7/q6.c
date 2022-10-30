#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MASK (0x7e000)
#define SHIFT_AMOUNT (13)

uint32_t sixMiddleBits(uint32_t number);

int main(void)
{
	uint32_t number = 0xabcd1234;

	uint32_t extracted = sixMiddleBits(number);

	printf("Extracted: %d (0x%x)\n", extracted, extracted);
}

uint32_t sixMiddleBits(uint32_t number)
{
	// uint32_t answer = 0;
	// answer = number & MASK;
	// answer = answer >> SHIFT_AMOUNT;
	// return answer;


	return (number & MASK) >> SHIFT_AMOUNT;
}
