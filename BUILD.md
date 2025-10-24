# Build Instructions - Cross-Platform Matrix Calculator

## System-Agnostic Build Instructions

### Prerequisites
- C compiler (GCC, Clang, or MSVC)
- Make utility (GNU Make, nmake, etc.)

### Quick Build Commands

#### Universal (all platforms):
```bash
make              # Build the project
make run          # Build and run immediately
make clean        # Clean build artifacts
make help         # Show all available options
```

#### Platform-Specific Quick Start:

**Linux/Ubuntu/Debian:**
```bash
sudo apt install build-essential  # Install tools if needed
make && ./matrix_calc
```

**macOS:**
```bash
xcode-select --install  # Install Xcode tools if needed
make && ./matrix_calc
```

**Windows (MinGW/MSYS2):**
```cmd
make && matrix_calc.exe
```

**Windows (Visual Studio):**
```cmd
gcc -Wall -O2 *.c -o matrix_calc.exe
matrix_calc.exe
```

### Advanced Build Options

```bash
make debug        # Build with debugging symbols
make release      # Optimized release build
make install      # Install to system PATH (Unix only)
make uninstall    # Remove from system PATH (Unix only)
```

### Manual Compilation (if Make is unavailable)

**All platforms:**
```bash
gcc -Wall -Wextra -std=c99 -O2 main.c add_sub.c dclr.c det_cofac.c fract.c matrixio.c multiply.c special.c testing.c -o matrix_calc
```

The executable will be named:
- `matrix_calc` on Linux/macOS
- `matrix_calc.exe` on Windows

### Troubleshooting

**"make: command not found"**
- Linux: `sudo apt install build-essential` or `sudo yum install make gcc`
- macOS: `xcode-select --install`
- Windows: Install MinGW, MSYS2, or Visual Studio

**"gcc: command not found"**
- Install development tools for your platform
- Windows users: Add MinGW/GCC to PATH

**Build warnings about unused variables**
- These are harmless and don't affect functionality
- Add `-Wno-unused-variable` to CFLAGS in Makefile to suppress

### Testing the Build

After successful compilation, test with:
```bash
./matrix_calc         # Linux/macOS
matrix_calc.exe       # Windows
```

You should see the Matrix Calculator main menu.

## Notes

- The Makefile automatically detects your platform
- No external dependencies required beyond standard C libraries
- Cross-platform clear screen commands are handled automatically
- Supports matrices of arbitrary size (limited by available memory)