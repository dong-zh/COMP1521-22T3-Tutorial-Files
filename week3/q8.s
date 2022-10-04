	.data
numbers_array:
	.word	0, 1, 2, 3, 4, 5, 6, 7, 8, 9

	.text
main:
	# t0 = i
	# t1 = x
	# t2 = y


#####################
	# numbers[9 - i] = x
	# addr = base + index * sizeof(element)
	# addr = numbers_array + (9 - i) * 4

	sub	$t3, 9, $t0
	mul	$t3, $t3, 4
	lw	$t2, numbers_array($t3)

	sub	$t3, 9, $t0
	mul	$t3, $t3, 4
	sw	$t2, numbers_array($t3)
#####################
	lw	$t9, numbers_array + 24
	sw	$t9, numbers_array + 12
