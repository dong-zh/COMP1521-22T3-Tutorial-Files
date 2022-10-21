#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t Word;
#define WORD_WIDTH (sizeof(Word) * 8)

#define MASK (0x1)

Word reverseBits(Word input);

int main(int argc, char **argv)
{
	Word input = 0b00010101;
	printf("Answer is %u\n", reverseBits(input));

	// 0b10101000
	//
}


Word reverseBits(Word input)
{
	Word answer = 0;
	for (int i = 0; i < WORD_WIDTH; i++) {
		answer <<= 1;
		answer |= input & MASK;
		input >>= 1;
	}

	return answer;
}
