// Goto version of Q8
// Dongzhu Huang (z5257526)
// 22T3

#include <stdio.h>

int main(void)
{
main__i_init:
	;
	int i = 1;
main__i_cond:
	if (i > 10) goto main__i_end;
main__i_body:

main__j_init:
	;
	int j = 0;
main__j_cond:
	if (j >= i) goto main__j_end;
main__j_body:
	putchar('*');
main__j_step:
	j++;
	goto main__j_cond;
main__j_end:
	putchar('\n');

main__i_step:
	i++;
	goto main__i_cond;
main__i_end:
	return 0;
}
