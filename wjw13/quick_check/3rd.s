      .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000
li              $8,2
li              $9,1
addu            $10,$9,$8

sw              $10,500($sp)
li              $8,3
lw              $9,500($sp)
addu            $10,$9,$8

sw              $10,504($sp)
li              $8,4
lw              $9,504($sp)
addu            $10,$9,$8


sw              $10,508($sp)
li              $8,5
lw              $9,508($sp)
addu            $10,$9,$8

sw              $10,512($sp)
li              $8,6
lw              $9,512($sp)
addu            $10,$9,$8

sw              $10,516($sp)
li              $8,7
lw              $9,516($sp)
addu            $10,$9,$8


sw              $10,520($sp)
li              $8,8
lw              $9,520($sp)
addu            $10,$9,$8

sw              $10,524($sp)
li              $8,9
lw              $9,524($sp)
addu            $10,$9,$8

sw              $10,528($sp)
li              $8,10
lw              $9,528($sp)
addu            $10,$9,$8

sw              $10,532($sp)
sw $10,4($sp)
lw $2,4($sp)
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main
