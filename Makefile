C=gcc
GCCFLAGS=-Wall -Wextra -g -

TARGETS=simple_wc

all: $(TARGETS)

simple_wc: simple_wc.c
	$(C) $^ -o $@ $(GCCFLAGS) 

clean:
	rm -f $(TARGETS) 
