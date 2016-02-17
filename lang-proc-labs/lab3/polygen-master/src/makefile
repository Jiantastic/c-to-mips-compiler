#
# PolyGen
# src-level makefile
#
# Alvise Spano' (2002-03)
#

NAME       := polygen

VERSION    := $(shell cat <VERSION)
DATE       := $(shell cat <DATE)

MLDEP	    = ocamldep -native
MLC 		= ocamlopt.opt
MLCOPTS		= -inline 23 -unsafe
MLLDOPTS	= unix.cmxa
MLLEX		= ocamllex
MLYACC		= ocamlyacc

# must be linked in this order
OBJS	   := ver.cmx		        \
	          prelude.cmx           \
              err.cmx               \
              absyn.cmx             \
              env.cmx               \
              check.cmx             \
              pre.cmx               \
              gen.cmx               \
              fake.cmx	   	        \
	          parser.cmx lexer.cmx  \
	          io.cmx		        \
              main.cmx
SRCS       := $(OBJS:.cmx=.ml)


all: $(NAME)

$(NAME): $(OBJS)
	$(MLC) $(MLLDOPTS) $(OBJS) -o $@

%.cmi: %.mli
	$(MLC) -c $(MLCOPTS) $< -o $@

%.cmx: %.ml
	$(MLC) -c $(MLCOPTS) $< -o $@

parser.mli parser.ml lexer.ml: lexer.mll parser.mly
	$(MLLEX) lexer.mll
	$(MLYACC) parser.mly
    # workaround for ocamlyacc "open" lack
	@mv parser.mli _parser.mli
	@echo "open Absyn\n" >parser.mli
	@cat <_parser.mli >>parser.mli
	@rm -f _parser.mli

ver.ml: ver.ml.template
	sed -e "s/%VERSION%/$(VERSION)/" -e "s/%DATE%/$(DATE)/" ver.ml.template >ver.ml

clean:
	rm -f *.o *.cm* a.out *.bak *.obj *~ *.annot *.stackdump parser.ml lexer.ml parser.mli ver.ml
	cat </dev/null >.depend

distclean: clean
	rm -f $(NAME) $(NAME).exe

.depend: parser.mli
	$(MLDEP) $(SRCS) parser.mli >.depend


include .depend
