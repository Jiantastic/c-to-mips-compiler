
      .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000


lw              $2,4($sp)
li              $2,4
sw              $2,4($sp)

li              $8,2
li              $9,5
mul             $10,$9,$8
sw              $10,500($sp)
lw              $8,500($sp)
li              $9,2
addu            $10,$9,$8
sw              $10,504($sp)
li              $8,2
lw              $9,4($sp)
div             $10,$9,$8
mfhi            $10
mflo            $10
sw              $10,508($sp)
lw              $8,504($sp)
lw              $9,508($sp)
subu            $10,$8,$9
sw              $10,512($sp)
sw              $10,8($sp)
lw              $2,8($sp)

      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main

