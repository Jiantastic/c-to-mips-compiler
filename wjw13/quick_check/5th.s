.text	
.align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000
lw              $2,4($sp)
li              $2,3
sw              $2,4($sp)

lw              $8,4($sp)
li              $9,3
addu            $10,$9,$8

sw              $10,500($sp)

sw              $10,8($sp)
lw	$2,8($sp)
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main

