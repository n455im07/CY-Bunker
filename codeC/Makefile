TARGET = ../exe

CC = gcc
CFLAGS = -Wall -std=c99

# Source files
SRCS = main.c treat_csv.c avl.c output_csv.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

	

$(TARGET): $(OBJS)
	@$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	@./$(TARGET) temp.dat hvb other_argument

