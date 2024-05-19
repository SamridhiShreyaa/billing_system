# Makefile for the Billing System

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = billing_system

all: $(TARGET)

$(TARGET): main.o customer.o product.o file_io.o user.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o customer.o product.o file_io.o user.o

main.o: main.c billing_system.h
	$(CC) $(CFLAGS) -c main.c

customer.o: customer.c billing_system.h
	$(CC) $(CFLAGS) -c customer.c

product.o: product.c billing_system.h
	$(CC) $(CFLAGS) -c product.c

file_io.o: file_io.c billing_system.h
	$(CC) $(CFLAGS) -c file_io.c

user.o: user.c billing_system.h
	$(CC) $(CFLAGS) -c user.c

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
