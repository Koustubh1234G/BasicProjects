
# My C++, Bash, and C Projects Repository

Welcome to my collection of Bash scripts, C/C++ programs, and simple Batch projects! This repository contains various tools, games, and utilities that can be run on different platforms. Below is a categorized list of each project, with installation instructions and system compatibility.

---
## Languages
- [Bash](#bash)
- [Batch](#batch)
- [C](#c)
- [C++](#cpp)

## Table of Contents

### Bash
1. [Annote](#annote) - Notes and journal CLI application
2. [Pomo](#pomo) - CLI Pomodoro timer with logs

### Batch
1. [Hello World](#hello-world) - Basic hello world application

### C
1. [Armstrong](#armstrong) - Check whether a number is an Armstrong number
2. [Factorial](#factorial) - Calculate factorial of a given number
3. [Fibonacci](#fibonacci) - Print Fibonacci series
4. [Marksheet](#marksheet) - Generate a student marksheet

### Cpp
- **Games**
    1. [Rock Paper Scissors](#rock-paper-scissors)
    2. [Casino Number Guessing](#casino-number-guessing)
- **Software**
    1. [Bank Management System](#bank-management-system)
    2. [Library Management System](#library-management-system)
- **TUI (Linux Terminal programs)**
    1. [cat](#cat-command) - Custom `cat` command that prints file content
    2. [grep](#grep-command) - Custom `grep` command to search for a word or character in a string/file

---

## Project Summaries

### Bash

#### 1. Annote
- **Description**: A CLI application for managing notes and journal entries. You can create, view, and delete notes directly from the terminal.
- **Location**: [view source...](./bash/annote.sh)
- **How to Use**: Run the script and follow the on-screen instructions.
  ```bash
  $ ./annote.sh
  ```
- **Compatibility**: Linux, macOS
- **Dependencies**: No external dependencies required.

#### 2. Pomo
- **Description**: A Pomodoro timer that logs your work/break sessions to a file for productivity tracking.
- **Location**: [view source...](./bash/pomo.sh)
- **How to Use**: Execute the script to start the timer. Logs are saved automatically.
  ```bash
  $ ./pomo.sh
  ```
- **Compatibility**: Linux, macOS
- **Dependencies**: No external dependencies required.

---

### Batch

#### 1. Hello World
- **Description**: A simple Batch script that prints "Hello, World!" to the console.
- **Location**: [view source...](./batch/hello_world.bat)
- **How to Use**: Double-click the Batch file or run it from the command prompt.
  ```cmd
  C:\path\to\file> hello_world.bat
  ```
- **Compatibility**: Windows
- **Dependencies**: No external dependencies required.

---

### C

#### 1. Armstrong
- **Description**: A program that checks whether a given number is an Armstrong number.
- **Location**: [view source...](./c/armstrong.c)
- **How to Use**: Compile and run the program using GCC.
  ```bash
  $ gcc armstrong.c -o armstrong
  $ ./armstrong
  ```
- **Compatibility**: Linux, macOS, Windows (with GCC)
- **Dependencies**: GCC

#### 2. Factorial
- **Description**: A program that calculates the factorial of a given number.
- **Location**: [view source...](./c/factorial.c)
- **How to Use**: Compile and run the program using GCC.
  ```bash
  $ gcc factorial.c -o factorial
  $ ./factorial
  ```
- **Compatibility**: Linux, macOS, Windows (with GCC)
- **Dependencies**: GCC

#### 3. Fibonacci
- **Description**: A program that prints the Fibonacci series up to a specified number.
- **Location**: [view source...](./c/fibonacci.c)
- **How to Use**: Compile and run the program using GCC.
  ```bash
  $ gcc fibonacci.c -o fibonacci
  $ ./fibonacci
  ```
- **Compatibility**: Linux, macOS, Windows (with GCC)
- **Dependencies**: GCC

#### 4. Marksheet
- **Description**: A program that generates a student marksheet based on input data.
- **Location**: [view source...](./c/marksheet.c)
- **How to Use**: Compile and run the program using GCC.
  ```bash
  $ gcc marksheet.c -o marksheet
  $ ./marksheet
  ```
- **Compatibility**: Linux, macOS, Windows (with GCC)
- **Dependencies**: GCC

---

### C++

#### Games

##### 1. Rock Paper Scissors
- **Description**: A simple terminal-based Rock, Paper, Scissors game written in C++.
- **Location**: [view source...](./cpp/games/RockPaperScissors/)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ rock_paper_scissors.cpp -o rock_paper_scissors
  $ ./rock_paper_scissors
  ```
- **Compatibility**: Linux, macOS, Windows (with g++)
- **Dependencies**: g++

##### 2. Casino Number Guessing
- **Description**: A number guessing game where the player tries to guess the correct number between 1 and 10.
- **Location**: [view source...](./cpp/games/CasinoNumberGuessing/)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ casino_number_guessing.cpp -o casino_number_guessing
  $ ./casino_number_guessing
  ```
- **Compatibility**: Linux, macOS, Windows (with g++)
- **Dependencies**: g++

---

#### Software

##### 1. Bank Management System
- **Description**: A basic bank management system where users can create, update, and view bank accounts.
- **Location**: [view source...](./cpp/software/BankManagementSys/)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ bank_management.cpp -o bank_management
  $ ./bank_management
  ```
- **Compatibility**: Linux, macOS, Windows (with g++)
- **Dependencies**: g++

##### 2. Library Management System
- **Description**: A system for managing library books, borrowing records, and more.
- **Location**: [view source...](./cpp/software/Library\ Management\ Sys/)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ library_management.cpp -o library_management
  $ ./library_management
  ```
- **Compatibility**: Linux, macOS, Windows (with g++)
- **Dependencies**: g++

---

#### TUI (Linux Terminal Programs)

##### 1. cat Command
- **Description**: A custom implementation of the Linux `cat` command that prints the contents of a file.
- **Location**: [view source...](./cpp/tui/mycat.cpp)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ cat_command.cpp -o cat_command
  $ ./cat_command filename.txt
  ```
- **Compatibility**: Linux, macOS
- **Dependencies**: g++

##### 2. grep Command
- **Description**: A custom implementation of the Linux `grep` command that searches for a word or character within a string or file.
- **Location**: [view source...](./cpp/tui/mygrep.cpp)
- **How to Use**: Compile and run using g++.
  ```bash
  $ g++ grep_command.cpp -o grep_command
  $ ./grep_command search_term filename.txt
  ```
- **Compatibility**: Linux, macOS
- **Dependencies**: g++

---

## How to Contribute

Feel free to fork this repository and submit pull requests if you'd like to improve any of these projects or add your own!

---

## License

This repository is licensed under the MIT License.

---
![GitHub repo size](https://img.shields.io/github/repo-size/koustubh1234g/BasicProjects)
![GitHub top language](https://img.shields.io/github/languages/top/koustubh1234g/BasicProjects)

