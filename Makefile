# Matrix Calculator - Cross-Platform Makefile
# Project: Matrix_Calc
# Compatible with Linux, macOS, and Windows

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG

# Platform detection
UNAME_S := $(shell uname -s 2>/dev/null || echo Windows)

# Platform-specific settings
ifeq ($(UNAME_S),Linux)
    # Linux settings
    RM = rm -f
    MKDIR = mkdir -p
    TARGET = matrix_calc
    CLEAR_CMD = clear
endif
ifeq ($(UNAME_S),Darwin)
    # macOS settings
    RM = rm -f
    MKDIR = mkdir -p
    TARGET = matrix_calc
    CLEAR_CMD = clear
endif
ifeq ($(UNAME_S),Windows)
    # Windows settings (MinGW/MSYS2)
    RM = del /Q
    MKDIR = mkdir
    TARGET = matrix_calc.exe
    CLEAR_CMD = cls
endif

# If running on pure Windows (cmd/PowerShell without uname)
ifndef UNAME_S
    RM = del /Q
    MKDIR = mkdir
    TARGET = matrix_calc.exe
    CLEAR_CMD = cls
endif

# Source files
SOURCES = main.c add_sub.c dclr.c det_cofac.c fract.c matrixio.c multiply.c special.c testing.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = calc_header.h

# Build directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Default target
all: $(TARGET)

# Create build directories
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Main target
$(TARGET): $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(OBJECTS))
	$(CC) $(addprefix $(OBJ_DIR)/, $(OBJECTS)) -o $(TARGET)
	@echo "Build completed successfully!"
	@echo "Run './$(TARGET)' to start the Matrix Calculator"

# Object file compilation
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build (optimized)
release: CFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)

# Clean build artifacts
clean:
ifeq ($(UNAME_S),Windows)
	-$(RM) $(TARGET) 2>nul
	-$(RM) $(OBJ_DIR)\*.o 2>nul
	-rmdir /S /Q $(BUILD_DIR) 2>nul
else
	-$(RM) $(TARGET)
	-$(RM) $(OBJ_DIR)/*.o
	-rm -rf $(BUILD_DIR)
endif

# Install (copy to system path - requires sudo on Unix systems)
install: $(TARGET)
ifeq ($(UNAME_S),Windows)
	@echo "Windows install not implemented. Add the directory to your PATH manually."
else
	sudo cp $(TARGET) /usr/local/bin/
	@echo "Matrix Calculator installed to /usr/local/bin/"
endif

# Uninstall
uninstall:
ifeq ($(UNAME_S),Windows)
	@echo "Windows uninstall not implemented."
else
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Matrix Calculator uninstalled from /usr/local/bin/"
endif

# Run the program
run: $(TARGET)
	./$(TARGET)

# Show help
help:
	@echo "Matrix Calculator Build System"
	@echo "Available targets:"
	@echo "  all      - Build the matrix calculator (default)"
	@echo "  debug    - Build with debug symbols and information"
	@echo "  release  - Build optimized release version"
	@echo "  clean    - Remove all build artifacts"
	@echo "  install  - Install to system path (Unix/Linux/macOS only)"
	@echo "  uninstall- Remove from system path (Unix/Linux/macOS only)"
	@echo "  run      - Build and run the calculator"
	@echo "  help     - Show this help message"
	@echo ""
	@echo "Platform detected: $(UNAME_S)"
	@echo "Target executable: $(TARGET)"

# Phony targets
.PHONY: all debug release clean install uninstall run help

# Print variables (for debugging the Makefile)
print-%:
	@echo $* = $($*)