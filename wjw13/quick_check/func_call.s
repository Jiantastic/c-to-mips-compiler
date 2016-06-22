      .text
      .align 2
      .globl f
      .ent    f
      .type f,@function
f:
       addiu  $sp,$sp,-1000
li              $2,3
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  f
      
      .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
main:
       addiu  $sp,$sp,-1000
                sw              $31,992($sp)
                jal f
                nop
                lw              $31,992($sp)
                sw              $2,4($sp)
sw              $10,8($sp)
lw              $2,4($sp)
      addiu $sp,$sp,1000
      j     $31
      nop

      .end  main

