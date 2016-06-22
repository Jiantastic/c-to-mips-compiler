
      .text
      .align 2
      .globl main
      .ent    main
      .type f,@function
main:
       addiu  $sp,$sp,-1000

lw              $2,4($sp)
li              $2,3
sw              $2,4($sp)
lw              $2,8($sp)
li              $2,5
sw              $2,8($sp)
lw              $8,8($sp)
lw              $9,4($sp)
bne             $8,$0,$L2
nop
beq             $9,$0,$L3
nop
$L2:
li              $10,1
b               $L4
nop
$L3:
move            $10,$0
$L4:
nop
sw              $10,500($sp)
sw              $10,12($sp)
move            $2,$10
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main

