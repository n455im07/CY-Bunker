# Name of the executable
TARGET = ../exe

# Compiler and compilation options
CC = gcc
CFLAGS = -Wall -std=c99

# Source files
SRCS = main.c

# Object files (generated from the source files, saved in the parent directory)
OBJS = $(SRCS:.c=.o)

# Default rule to compile the program
all: $(TARGET)

	@echo "Compilation successful"

# Rule to create the executable from object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to generate object files from source files
# The object files are created in the current directory
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Rule to run the program
run: $(TARGET)
	./$(TARGET) temp.dat hvb other_argument
