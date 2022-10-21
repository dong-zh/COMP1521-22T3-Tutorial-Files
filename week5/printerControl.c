#include <stdio.h>
#include <stdint.h>

#define NO_INK (0x1)
#define COLOUR (0x2)
#define SELECT_PRINT (0x4)
#define SELECT_SCAN (0x8)
#define START (0x10)

// The printer
uint8_t printerControl = 0b0000001;

void checkInk(void);
void replaceInk(void);
void useColourAndSelectScan(void);
void toggleMode(void);
void start(void);

int main(void)
{
	// Main function for testing
	printf("printerControl = 0x%02x\n", printerControl);
	// checkInk();
	// replaceInk();
	// useColourAndSelectScan();
	// start();
	// toggleMode();
	printf("printerControl = 0x%02x\n", printerControl);

}

void checkInk(void)
{
	if (printerControl & NO_INK) {
		printf("Out of ink\n");
	} else {
		printf("Ink levels OK\n");
	}
}

void replaceInk(void)
{
	printerControl &= ~NO_INK;
	// ~NO_INK = 0b 1111 1110
}

void useColourAndSelectScan(void)
{
	printerControl |= SELECT_SCAN | COLOUR;
}

void toggleMode(void)
{
	printerControl ^= SELECT_PRINT | SELECT_SCAN;
}

void start(void)
{
	int printMode = !!(printerControl & SELECT_PRINT);
	int scanMode = !!(printerControl & SELECT_SCAN);

	if (printMode == scanMode) {
		printf("Invalid mode\n");
		return;
	}

	if (printerControl & SELECT_PRINT) {
		if (printerControl & NO_INK) {
			printf("Trying to print, but no ink.\n");
			return;
		}
		printf("Printing in %s\n...",
			printerControl & COLOUR ? "colour" : "greyscale"
		);
	} else {
		printf("Scanning in %s\n...",
			printerControl & COLOUR ? "colour" : "greyscale"
		);
	}

	printerControl |= START;

	while (printerControl & START) {
		// Poll until done
		// This will infinite loop since this is just a demo
		// There's no real printer on the other end clearing `START`
	}

	printf("Done!\n");
}
