# c-to-mips-compiler

Compiles C code into MIPS Assembly. Source code is in the wjw13 folder

Takes in C code on `stdin`, spits out MIPS Assembly on `stdout`

Developed with good old [Flex](https://github.com/westes/flex) and [Bison](https://www.gnu.org/software/bison/)

Have a look at [VisualMips](https://visualmips.github.io/) if you would like to try out a web-based MIPS assembler!

## Usage

`cd c-to-mips-compiler/wjw13/ && make` builds the project

`cd bin && cat test1.c | ./c_compiler` for an example usage

You should now see some generated MIPS assembly code 

      .text
      .align 2
      .globl main
      .ent    main
      .type main,@function
      
      
## References

'Dragon Book'





