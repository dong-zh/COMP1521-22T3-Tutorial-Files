int main(void)
{
	int i;
	int numbers[10] = {0,1,2,-3,4,-5,6,-7,8,9};

main__i_init:
	i = 0;
main__i_cond:
	if (i >= 10) goto main__i_end;
main__i_body:
	if (numbers[i] >= 0) goto main__number_ge_0;
main__number_lt_0:
	// numbers[i] += 42;
	numbers[i] = numbers[i] + 42;
main__number_ge_0:
main__i_step:
	i++;
	goto main__i_cond;
main__i_end:
	;
}
