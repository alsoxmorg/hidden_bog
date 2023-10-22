# Makefile for compiling each C file individually in a "src" directory

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 \
	-Wunused-but-set-variable \
	`sdl2-config --cflags --libs`\
	-lGL -lSDL2_image

# Source files and their corresponding object files
SRCDIR = src
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# The executable name
EXECUTABLE = game

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXECUTABLE)
