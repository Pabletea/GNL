# Get_Next_Line

## Overview
The **Get_Next_Line** project is designed to read a line from a file descriptor, one line at a time. It is a key project for understanding and practicing file I/O operations, buffer management, and dynamic memory allocation in C. This repository contains both the mandatory and bonus implementations of the project.

## Project Structure
Below is a breakdown of each file in this repository and its purpose:

| File                        | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| **`get_next_line.c`**       | Implements the main function to read a line from a file descriptor.         |
| **`get_next_line.h`**       | Header file containing function prototypes and necessary macros.            |
| **`get_next_line_utils.c`** | Contains utility functions used by `get_next_line.c`.                      |
| **`get_next_line_bonus.c`** | Bonus implementation supporting multiple file descriptors simultaneously.   |
| **`get_next_line_bonus.h`** | Header file for the bonus implementation.                                   |
| **`get_next_line_utils_bonus.c`** | Utility functions for the bonus implementation.                       |

## Features
- **Read a line from a file descriptor**: The `get_next_line` function reads and returns the next line from a file descriptor, including the newline character if present.
- **Buffer management**: Efficiently manages a static buffer to minimize the number of system calls.
- **Bonus implementation**: Supports reading from multiple file descriptors simultaneously.

## Getting Started

### Prerequisites
To build and run this project, ensure you have the following installed on your system:
- A C compiler, such as `gcc`
- `make` utility (optional, if using a Makefile)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/Get_Next_Line.git
   cd Get_Next_Line
   ```

2. Compile the project:
   ```bash
   gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
   ```

3. For the bonus implementation:
   ```bash
   gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
   ```

### Usage
1. Create a text file (e.g., `test.txt`) with some lines of text.
2. Run the program:
   ```bash
   ./gnl test.txt
   ```
3. For bonus features, test with multiple file descriptors simultaneously:
   ```bash
   ./gnl_bonus file1.txt file2.txt
   ```

## Testing
You can use the provided test cases or create your own to verify the functionality of the program. The bonus implementation ensures that `get_next_line` works seamlessly with multiple file descriptors.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License
This project is open-source and available under the [MIT License](LICENSE).

---

**Note**: The buffer size can be adjusted during compilation by defining the `BUFFER_SIZE` macro. For example:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

