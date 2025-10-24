# Matrix Calculator

A comprehensive command-line matrix calculator written in C that supports various matrix operations including basic arithmetic, determinants, matrix transformations, and advanced operations like matrix inversion and power calculations.

## Features

### Core Matrix Operations
- **Matrix Addition & Subtraction** - Add or subtract matrices of the same dimensions
- **Matrix Multiplication** - Standard matrix multiplication with dimension validation
- **Scalar Multiplication** - Multiply matrices by scalar values
- **Matrix Transpose** - Calculate the transpose of any matrix

### Advanced Operations
- **Determinant Calculation** - Compute determinants for square matrices
- **Minor Matrix** - Generate minor matrices by removing specified rows/columns  
- **Cofactor Matrix** - Calculate cofactor matrices with proper sign alternation
- **Adjoint Matrix** - Compute the adjoint (adjugate) matrix
- **Matrix Inverse** - Calculate inverse matrices (when they exist)
- **Matrix Power** - Raise square matrices to integer powers

### Special Features
- **Fraction Support** - Display results as simplified fractions when appropriate
- **Input Validation** - Robust error handling and input validation
- **Interactive Menu** - User-friendly command-line interface
- **Cross-Platform** - Works on Linux, macOS, and Windows

## Requirements

- **C Compiler**: GCC, Clang, or compatible C compiler
- **Make**: GNU Make or compatible build system
- **Standard Libraries**: stdio.h, stdlib.h (included in all standard C installations)

## Installation & Building

### Quick Start (Recommended)
```bash
# Clone or download the project
git clone <repository-url>
cd MatrixCalc

# Build the project
make

# Run the calculator
./matrix_calc
```

### Platform-Specific Instructions

#### Linux/Ubuntu/Debian
```bash
# Install build tools (if not already installed)
sudo apt update
sudo apt install build-essential

# Build and run
make
./matrix_calc
```

#### macOS
```bash
# Install Xcode Command Line Tools (if not already installed)
xcode-select --install

# Build and run
make
./matrix_calc
```

#### Windows (MinGW/MSYS2)
```cmd
# Using MinGW or MSYS2 terminal
make
matrix_calc.exe
```

#### Windows (Visual Studio Command Prompt)
```cmd
# Alternative manual compilation
gcc -Wall -Wextra -std=c99 -O2 *.c -o matrix_calc.exe
matrix_calc.exe
```

### Build Options

```bash
# Standard build
make

# Debug build (with debugging symbols)
make debug

# Optimized release build
make release

# Clean build artifacts
make clean

# Install to system PATH (Linux/macOS only)
sudo make install

# Show all available targets
make help
```

## Usage

### Starting the Calculator
```bash
./matrix_calc          # Linux/macOS
matrix_calc.exe         # Windows
```

### Main Menu Options
The calculator presents an interactive menu with the following options:

1. **Matrix Addition Calculator**
2. **Matrix Subtraction Calculator** 
3. **Matrix Scalar Multiplication Calculator**
4. **Matrix Multiplication Calculator**
5. **Transpose Matrix Calculator**
6. **Matrix Determinant Calculator**
7. **Minor Matrix Calculator**
8. **Cofactor Matrix Calculator**
9. **Adjoint Matrix Calculator**
10. **Inverse Matrix Calculator**
11. **Matrix Power Calculator**

### Example Session
```
     Matrix Calculator v1.2

 (1) Matrix Addition Calculator
 (2) Matrix Subtraction Calculator
 (3) Matrix Scalar Multiplication Calculator
 ...

Enter the number of the calculator you want to use: 1

Enter the size of the matrices (rows columns): 2 2

Enter Matrix A:
Enter element [1][1]: 1
Enter element [1][2]: 2
Enter element [2][1]: 3
Enter element [2][2]: 4

Enter Matrix B:
Enter element [1][1]: 5
Enter element [1][2]: 6
Enter element [2][1]: 7
Enter element [2][2]: 8

Result Matrix (A + B):
[  6   8 ]
[ 10  12 ]

Do you want to perform another calculation? (Y/N): N
```

### Input Guidelines
- **Matrix Dimensions**: Enter as "rows columns" (e.g., "3 3" for a 3×3 matrix)
- **Matrix Elements**: Enter integers when prompted
- **Fractions**: When applicable, results may be displayed as simplified fractions
- **Navigation**: Use the menu numbers to select operations

## Project Structure

```
MatrixCalc/
├── calc_header.h      # Function declarations and structures
├── main.c             # Main program and user interface
├── add_sub.c          # Addition and subtraction operations
├── multiply.c         # Multiplication operations
├── det_cofac.c        # Determinant and cofactor calculations
├── special.c          # Transpose, inverse, and special operations
├── matrixio.c         # Matrix input/output functions
├── dclr.c             # Dynamic memory allocation functions
├── fract.c            # Fraction handling and simplification
├── testing.c          # Testing utilities
├── Makefile           # Cross-platform build configuration
└── README.md          # This documentation
```

## Algorithm Details

### Matrix Operations
- **Addition/Subtraction**: Element-wise operations with dimension validation
- **Multiplication**: Standard row-column dot product algorithm
- **Determinant**: Recursive cofactor expansion for n×n matrices
- **Inverse**: Uses adjoint matrix method: A⁻¹ = (1/det(A)) × adj(A)

### Memory Management
- Dynamic memory allocation for matrices of arbitrary size
- Proper cleanup and error handling to prevent memory leaks
- Bounds checking for all array operations

### Fraction Arithmetic
- GCD-based fraction simplification
- Automatic conversion between integer and fractional representations
- Proper handling of fraction arithmetic in matrix operations

## Error Handling

The calculator includes robust error handling for:
- Invalid matrix dimensions
- Non-square matrices for operations requiring them
- Singular matrices (zero determinant) for inverse calculations
- Memory allocation failures
- Invalid user input

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-operation`)
3. Make your changes
4. Test thoroughly on your platform
5. Commit your changes (`git commit -am 'Add new matrix operation'`)
6. Push to the branch (`git push origin feature/new-operation`)
7. Create a Pull Request

### Development Guidelines
- Follow existing code style and naming conventions
- Add appropriate error checking for new functions
- Update this README if adding new features
- Test on multiple platforms when possible

## License

This project is open source. Please check the repository for license details.

## Troubleshooting

### Common Issues

**Build fails with "command not found"**
- Ensure GCC and Make are installed on your system
- On Windows, use MinGW, MSYS2, or Visual Studio tools

**Program crashes during matrix input**
- Check that you're entering valid integers
- Ensure matrix dimensions are positive integers
- Verify you have sufficient memory for large matrices

**"cls" command not found (Linux/macOS)**
- ✅ **Fixed!** The project now uses cross-platform clear screen commands
- Windows: Uses `cls` command
- Linux/macOS: Uses `clear` command

**Memory allocation errors**
- Reduce matrix size for very large matrices
- Check available system memory

### Platform-Specific Notes

**Linux**: Should work out of the box with most distributions
**macOS**: Requires Xcode Command Line Tools
**Windows**: Best compatibility with MinGW or MSYS2; may require path configuration

## Version History

- **v1.2**: Current version with cross-platform support
- **v1.1**: Added fraction support and improved error handling
- **v1.0**: Initial release with basic matrix operations

---

*For bug reports or feature requests, please open an issue in the project repository.*