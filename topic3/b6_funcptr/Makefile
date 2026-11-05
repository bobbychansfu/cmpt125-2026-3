# CMPT 125 Topic 3b: a struct that carries pointers to its own functions
#   make           builds ./driver
#   make run       builds and runs it (prints 1 2 3)
#   make check     builds ./driver_check with AddressSanitizer + UBSan and runs it
#   make clean     removes the programs

CC     = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
SRCS   = driver.c queue.c LL.c
HDRS   = queue.h LL.h

driver: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

run: driver
	./driver

check: driver_check
	./driver_check

driver_check: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer -o $@ $(SRCS)

clean:
	rm -f driver driver_check

.PHONY: run check clean
