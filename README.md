# FileComparator
C program that compares the contents of two files using low-level system calls.

The program using low-level system calls like `read`, `open`, `write`, `access` and more. This tool checks if the files are identical, similar (with differences in spaces or newlines), or different, providing clear results for file comparison tasks. The program leverages direct interaction with the operating system, making it efficient and reliable for file handling.

## How to Run

1. **Clone the Repository:**
  ```bash
    git clone https://github.com/tomerp1812/FileComparator.git
    cd FileComparator
  ```
2. **Compile the Program:**
  ```bash
    gcc FileComperator.c -o FileComperator
  ```
3. **Run the Program:**
  ```bash
    ./FileComperator file1.txt file2.txt
  ```
  - Replace `file1.txt` and `file2.txt` with the paths to the files you want to compare.
4. **Interpret the Output:**
    
    1: Files are exactly the same.
    
    2: Files are different.
    
    3: Files are similar (differences only in spaces or newlines).
