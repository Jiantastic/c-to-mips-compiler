
      .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000
li              $8,100
li              $9,55
addu            $10,$9,$8
sw              $10,500($sp)
sw              $10,4($sp)
move            $2,$10
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main


