# Advanced-c-programming-Assessment

# Table of Contents

1. Introduction
2. Objectives
3. Technologies Used
4. Module 1 – Structures, Pointers, and Arrays
5. Module 2 – Threads, Signals, and System Programming
6. Compilation and Execution
7. Concepts Learned
8. Time Complexity
9. Important Linux/System Programming Concepts
10. Viva Questions and Answers
11. Learning Outcomes
12. Conclusion

---

# 1. Introduction

This training program focuses on advanced concepts in the C programming language, including:

- Structures
- Pointer arithmetic
- Dynamic memory concepts
- Arrays and matrix operations
- Multi-threading
- Signal handling
- Process management
- Synchronization techniques
- Time complexity analysis
- Linux system programming

The assignments are designed to improve:
- problem-solving skills
- memory management understanding
- system-level programming knowledge
- multi-threaded application development

---

# 2. Objectives

The objectives of this training are:

- Understand advanced C programming concepts
- Learn data organization using structures
- Master pointer arithmetic
- Implement efficient algorithms
- Learn thread creation and management
- Handle Linux signals
- Understand process creation using `fork()`
- Explore synchronization mechanisms
- Analyze time complexity of algorithms

---

# 3. Technologies Used

| Technology | Purpose |
|------------|----------|
| C Language | Core programming |
| GCC Compiler | Compilation |
| POSIX Threads (`pthread`) | Multi-threading |
| Linux Signals | Signal handling |
| Standard C Library | Input/output and memory operations |

---

# 4. Module 1 – Structures, Pointers, and Arrays

---

# Topic 1 – Structures

## Problem Statement

Create a calendar program representing one week where each day contains:
- day name
- maximum 3 tasks

The program should:
1. Define appropriate structures
2. Allow user input
3. Display all tasks grouped by day

---

# Structure Design

```c
struct Day
{
    char dayName[20];
    char tasks[3][100];
    int taskCount;
};
