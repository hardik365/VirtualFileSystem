# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = vfs

# Source files
SRCS = main.c func.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)
