# Variables
CC = $(shell which gcc)
CFLAGS = -Wall -Wextra -Werror -std=c11 -I./includes
BIN_DIR = bin

TARGET = $(BIN_DIR)/cwordle
TARGET_WIN64 = $(BIN_DIR)/cwordleW64.exe
SRC = src/main.c src/words.c
OBJ = $(SRC:.c=.o)

# Define Phone Targets
.PHONY: all clean run install

# Define Targets
all: clean $(TARGET)

# Build Target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Build Target for Windows
build_win: clean $(TARGET_WIN64)
$(TARGET_WIN64): $(OBJ)
	x86_64-w64-mingw32-gcc $(CFLAGS) -o $(TARGET_WIN64) $(OBJ)


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