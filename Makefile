# Variables
CC = $(shell which gcc)
CFLAGS = -Wall -Wextra -Werror -I./includes
BIN_DIR = bin

TARGET = $(BIN_DIR)/cwordle
SRC = src/main.c src/words.c
OBJ = $(SRC:.c=.o)

# Define Phone Targets
.PHONY: all clean run install

# Define Targets
all: clean $(TARGET)

# Build Target
$(TARGET): $(OBJ) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile Objects
%.o: %.c
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@


# Clean
clean:
	rm -f $(OBJ) $(TARGET)


# Run
run: $(TARGET)
	./$(TARGET)

# Install (TBD)