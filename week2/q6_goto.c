// Goto version of Q6
// Dongzhu Huang (z5257526)
// 22T3

#include <stdio.h>

int main(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);


	if (x <= 100) goto main__x_small_big;
	if (x >= 1000) goto main__x_small_big;
main__x_medium:
	printf("medium\n");
	goto main__x_phi;
main__x_small_big:
	printf("small/big\n");
main__x_phi:
	return 0;
}
