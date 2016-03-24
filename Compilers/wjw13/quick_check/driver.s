	.file	1 "driver.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.rdata
	.align	2
$LC1:
	.ascii	"%d,%d,%d\012\000"
	.align	2
$LC0:
	.word	0
	.word	-1
	.word	1
	.word	-2
	.word	2
	.word	78686
	.word	-454
	.word	65535
	.word	-65535
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,96,$31		# vars= 56, regs= 2/0, args= 24, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-96
	sw	$31,92($sp)
	sw	$fp,88($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	24
	lui	$2,%hi($LC0)
	addiu	$3,$fp,48
	addiu	$2,$2,%lo($LC0)
	li	$4,36			# 0x24
	move	$6,$4
	move	$5,$2
	move	$4,$3
	lw	$2,%call16(memcpy)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,memcpy
1:	jalr	$25
	nop

	lw	$28,24($fp)
	li	$2,9			# 0x9
	sw	$2,40($fp)
	sw	$0,32($fp)
	b	$L2
	nop

$L5:
	sw	$0,36($fp)
	b	$L3
	nop

$L4:
	lw	$2,32($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$4,16($2)
	lw	$2,36($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$2,16($2)
	move	$5,$2
	lw	$2,%call16(f)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,f
1:	jalr	$25
	nop

	lw	$28,24($fp)
	sw	$2,44($fp)
	lw	$2,%got(stdout)($28)
	lw	$4,0($2)
	lw	$2,32($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$5,16($2)
	lw	$2,36($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$3,16($2)
	lw	$2,44($fp)
	sw	$2,16($sp)
	move	$7,$3
	move	$6,$5
	lui	$2,%hi($LC1)
	addiu	$5,$2,%lo($LC1)
	lw	$2,%call16(fprintf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fprintf
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,36($fp)
	addiu	$2,$2,1
	sw	$2,36($fp)
$L3:
	lw	$3,36($fp)
	lw	$2,40($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L4
	nop

	lw	$2,32($fp)
	addiu	$2,$2,1
	sw	$2,32($fp)
$L2:
	lw	$3,32($fp)
	lw	$2,40($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L5
	nop

	move	$2,$0
	move	$sp,$fp
	lw	$31,92($sp)
	lw	$fp,88($sp)
	addiu	$sp,$sp,96
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 5.3.1-8) 5.3.1 20160205"
