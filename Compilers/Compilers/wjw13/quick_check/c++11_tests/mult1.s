	.file	1 "mult1.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp,32,$31		# vars= 16, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$fp,28($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	sw	$5,36($fp)
	li	$2,6			# 0x6
	sw	$2,8($fp)
	lw	$2,32($fp)
	sll	$2,$2,1
	sw	$2,12($fp)
	lw	$3,32($fp)
	lw	$2,36($fp)
	mul	$2,$3,$2
	sw	$2,16($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$fp,28($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.ident	"GCC: (Debian 5.3.1-8) 5.3.1 20160205"
