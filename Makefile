CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
OUTPUT_DIR = output
TARGET = csv_to_json_converter

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/csv_parser.c $(SRC_DIR)/json_writer.c
OBJ = $(SRC:.c=.o)
INCLUDE = -I$(INC_DIR)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Build the object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Run tests
tests: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(TEST_DIR)/*.c -o tests/test_runner
	./tests/test_runner

# Clean the build
clean:
	rm -f $(OBJ) $(TARGET) tests/test_runner $(OUTPUT_DIR)/*.json


.PHONY: all clean tests