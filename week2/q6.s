# Prints whether a number is small/big or medium
# COMP1521 week 2 question 6
# 22T3

	.data

prompt_string:
	.asciiz	"Enter a number: "

medium_string:
	.asciiz	"medium\n"

small_big_string:
	.asciiz	"small/big\n"

	.text
main:
	# t0 = x
	# Print string syscall
	li	$v0, 4
	la	$a0, prompt_string
	syscall


	# Read int syscall
	li	$v0, 5
	syscall
	# expect to find user input in v0
	move	$t0, $v0

	ble	$t0, 100, main__x_small_big
	bge	$t0, 1000, main__x_small_big
main__x_medium:
	# Print string syscall
	li	$v0, 4
	la	$a0, medium_string
	syscall
	b	main__x_phi
main__x_small_big:
	# Print string syscall
	li	$v0, 4
	la	$a0, small_big_string
	syscall
main__x_phi:

	# return 0
	li	$v0, 0
	jr	$ra
