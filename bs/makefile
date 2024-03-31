CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c functions.c
OBJS = $(SRCS:.c=.o)
TARGET = billing_system

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
