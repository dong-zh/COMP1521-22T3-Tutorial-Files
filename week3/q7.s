# Header comment goes here

	.data
numbers_array:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9

	.text
main:
	# t0 = i
	# t1 = numbers[i] address calculation
	# t3 = numbers[i]

main__i_init:
	li	$t0, 0
main__i_cond:
	bge	$t0, 10, main__i_end
main__i_body:

	mul	$t1, $t0, 4	# t1 = i * 4
	# la	$t2, numbers_array
	# add	$t1, $t2, $t1	# t1 = base + (i * 4)
	# lw	$t3, ($t1)
	lw	$t3, numbers_array($t1)
	bgez	$t3, main__number_ge_0

main__number_lt_0:
	mul	$t1, $t0, 4	# t1 = i * 4
	lw	$t3, numbers_array($t1)
	add	$t3, $t3, 42

	mul	$t1, $t0, 4	# t1 = i * 4
	sw	$t3, numbers_array($t1)	# numbers[i] = numbers[i] + 42
main__number_ge_0:
main__i_step:
	add	$t0, $t0, 1
	b	main__i_cond
main__i_end:

	jr	$ra
