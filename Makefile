# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = Stack
TEST_DIR = Tests
BUILD_DIR = build

# Array and Linked-based implementation directories
ARRAY_IMPL_DIR = $(SRC_DIR)/Array-based-implementation
LINKED_IMPL_DIR = $(SRC_DIR)/Linked-based-implementation

# Generalized Files
MAIN_FILE = main.c
TEST_FILE = $(TEST_DIR)/test_stack.c
MAIN_OBJ = $(BUILD_DIR)/main.o
TEST_OBJ = $(BUILD_DIR)/test_stack.o

# Headers
STACK_H = $(SRC_DIR)/stack.h
TESTS_H = $(TEST_DIR)/tests.h

# Flags for choosing implementation mode (array or linked)
IMPLEMENTATION_MODE ?= array # Default is array-based; override with `make IMPLEMENTATION_MODE=linked`

# Implementation-based settings
ifeq ($(IMPLEMENTATION_MODE), linked)
    IMPL_SRC = $(LINKED_IMPL_DIR)/stack.c
    IMPL_OBJ = $(BUILD_DIR)/stack_linked.o
    CFLAGS += -DLINKED_IMPL
else
    IMPL_SRC = $(ARRAY_IMPL_DIR)/stack.c
    IMPL_OBJ = $(BUILD_DIR)/stack_array.o
endif

# Target Executable
EXEC = program

# All target
all: $(BUILD_DIR) $(EXEC)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Main executable
$(EXEC): $(MAIN_OBJ) $(TEST_OBJ) $(IMPL_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Object file for main
$(MAIN_OBJ): $(MAIN_FILE) $(STACK_H) $(TESTS_H)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(TEST_DIR) -c $(MAIN_FILE) -o $@

# Object file for test_stack.c
$(TEST_OBJ): $(TEST_FILE) $(STACK_H) $(TESTS_H)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(TEST_DIR) -c $(TEST_FILE) -o $@

# Implementation object file
$(IMPL_OBJ): $(IMPL_SRC) $(STACK_H)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $(IMPL_SRC) -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Run the main program
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run