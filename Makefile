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

# Build the main executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Build the object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Test executables
tests/test_csv_parser: $(SRC_DIR)/csv_parser.c $(TEST_DIR)/test_csv_parser.c
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/csv_parser.c $(TEST_DIR)/test_csv_parser.c -o tests/test_csv_parser

tests/test_json_writer: $(SRC_DIR)/json_writer.c $(TEST_DIR)/test_json_writer.c
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/json_writer.c $(TEST_DIR)/test_json_writer.c -o tests/test_json_writer

# Run tests
tests: tests/test_csv_parser tests/test_json_writer
	./tests/test_csv_parser
	./tests/test_json_writer

# Clean the build
clean:
	rm -f $(OBJ) $(TARGET) tests/test_csv_parser tests/test_json_writer $(OUTPUT_DIR)/*.json

.PHONY: all clean tests
