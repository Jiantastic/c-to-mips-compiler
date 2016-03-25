	.file	1 "long_express.c"
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
	.frame	$fp,32,$31		# vars= 16, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$fp,28($sp)
	move	$fp,$sp
	li	$2,3			# 0x3
	sw	$2,8($fp)
	li	$2,5			# 0x5
	sw	$2,12($fp)
	li	$2,2			# 0x2
	sw	$2,16($fp)
	lw	$3,12($fp)
	move	$2,$3
	sll	$2,$2,2
	addu	$3,$2,$3
	lw	$2,8($fp)
	addu	$3,$3,$2
	lw	$2,16($fp)
	subu	$2,$3,$2
	sw	$2,20($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$fp,28($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 5.3.1-8) 5.3.1 20160205"
