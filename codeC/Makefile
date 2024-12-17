TARGET = ../exe

CC = gcc
CFLAGS = -Wall -std=c99

# Source files
SRCS = main.c treat_dat.c avl.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

	@echo "Compilation successful"

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET) temp.dat hvb other_argument


