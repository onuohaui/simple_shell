# Simple Makefile for compiling the shell

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJS = main.o prompt.o exec.o error_handling.o parse_input.o builtin.o wait.o
TARGET = simple_shell

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

