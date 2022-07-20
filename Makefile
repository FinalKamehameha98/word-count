C=gcc
GCCFLAGS=-Wall -Wextra -g -std=c99

TARGETS=simple_wc

all: $(TARGETS)

simple_wc: simple_wc.c
	$(C) $^ -o $@ $(GCCFLAGS) 

clean:
	rm -f $(TARGETS) 
