  .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000
li              $8,2
li              $9,3
addu            $10,$9,$8
sw              $10,500($sp)
li              $8,1
lw              $9,500($sp)
addu            $10,$9,$8
sw              $10,504($sp)
sw $10,4($sp)
lw $2,4($sp)
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main

