	.data
flag:
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

flag_pole:
	.asciiz	"|\n|\n|\n|\n|\n|\n|\n|\n"

# Constants
NUM_ROWS = 6
NUM_COLS = 12

	.text

# ------------------------------------------------------------------------------
#                                 Main Function
# ------------------------------------------------------------------------------
main:
main__prologue:
	push	$ra
main__body:

	jal	print_flag

	# print flag pole
	li	$v0, 4
	la	$a0, flag_pole
	syscall

	li	$a0, 160
	jal	print_hill

main__epilogue:
	pop	$ra
	jr	$ra

# ------------------------------------------------------------------------------
#                              Print Flag Function
# ------------------------------------------------------------------------------
print_flag:
print_flag__prologue:
	push	$ra
	push	$s0
print_flag_body:
	# s0 = row
print_flag__row_init:
	li	$s0, 0			# $s0 = 0
print_flag__row_cond:
	bge	$s0, NUM_ROWS, print_flag__row_end
print_flag__row_body:
	move	$a0, $s0
	jal	print_row
print_flag__row_step:
	add	$s0, $s0, 1		# $t0 = $t0 + 1
	b	print_flag__row_cond
print_flag__row_end:

print_flag__epilogue:

	pop	$s0
	pop	$ra

	jr	$ra
# ------------------------------------------------------------------------------
#                              Print Row Function
# ------------------------------------------------------------------------------
print_row:
	# t1 = address calculation
	# t2 = flag[row][col]
	# t3 = row
	move	$t3, $a0
print_row__col_init:
	li	$t0, 0
print_row__col_cond:
	bge	$t0, NUM_COLS, print_row__col_end
print_row__col_body:
	# put char syscall
	li	$v0, 11

	# Calculate flag[row][col]
	mul	$t1, $t3, NUM_COLS	# t1 = row * NUM_COLS
	add	$t1, $t1, $t0		# t1 = (row * NUM_COLS) + col
	lb	$t2, flag($t1)

	move	$a0, $t2
	syscall

print_row__col_step:
	add	$t0, $t0, 1
	b	print_row__col_cond
print_row__col_end:

	li	$v0, 11
	li	$a0, '\n'
	syscall

	jr	$ra
# ------------------------------------------------------------------------------
#                              Print Hill Function
# ------------------------------------------------------------------------------
print_hill:
print_hill__prologue:
	push	$ra
	push	$s0

	move	$s0, $a0
print_hill__body:
	# s0 = height
	# t0 = i
	blez	$s0, print_hill__epilogue

	# Recursive call
	sub	$a0, $s0, 1
	jal	print_hill

print_hill__i_init:
	li	$t0, 0
print_hill__i_cond:
	bge	$t0, $s0, print_hill__i_end
print_hill__i_body:
	li	$v0, 11
	li	$a0, '*'
	syscall
print_hill__i_step:
	add	$t0, $t0, 1
	b	print_hill__i_cond
print_hill__i_end:
	li	$v0, 11
	li	$a0, '\n'
	syscall

print_hill__epilogue:
	pop	$s0
	pop	$ra

	jr	$ra
