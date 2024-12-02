# Variables
CC = $(shell which gcc)
CFLAGS = -Wall -Wextra -Werror -std=c11 -I./includes
TARGET = cwordle
SRC = src/main.c
OBJ = $(SRC:.c=.o)

# Define Phone Targets
.PHONY: all clean run install

# Define Targets
all: $(TARGET)

# Build Target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)


# Compile Objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean
clean:
	rm -f $(OBJ) $(TARGET)


# Run
run: $(TARGET)
	./$(TARGET)

# Install (TBD)