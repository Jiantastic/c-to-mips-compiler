	.file	1 "important.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,24,$31		# vars= 8, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-1000
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	li	$2,5			# 0x5
	sw	$2,24($fp)
	lw	$2,24($fp)
	sll	$2,$2,1
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$2,$3,$2
	sw	$2,8($fp)
	lw	$2,8($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,1000
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 5.3.1-8) 5.3.1 20160205"
