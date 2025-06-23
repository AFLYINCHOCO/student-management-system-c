# 基于C语言的命令行学生信息管理系统

### 1. 项目简介
这是一个基于C语言独立开发的命令行学生信息管理系统。项目旨在实践C语言核心编程能力与结构化编程思想，完整实现了对学生数据记录的增、删、改、查（CRUD）功能，并通过文件I/O实现了数据的本地持久化存储，使应用能够在关闭后保留状态。

### 2. 核心功能
- **添加学生 (Create)**: 添加新的学生记录（学号、姓名、成绩），并进行学号唯一性检查。
- **查询学生 (Read)**: 支持按学号精确查找，或显示当前系统中所有学生的信息列表。
- **修改学生 (Update)**: 根据学号定位并更新指定学生的信息。
- **删除学生 (Delete)**: 根据学号从系统中移除指定的学生记录。
- **数据持久化 (Persistence)**: 
    - 程序启动时，自动从本地文件 `students.txt` 加载数据。
    - 程序退出时，自动将内存中的所有数据保存回 `students.txt` 文件。

### 3. 如何编译与运行

**使用GCC编译器 (Linux/Mac/MinGW):**
```bash
# 编译
gcc main.c -o student_system

# 运行
./student_system
```

**使用Visual Studio (Windows):**
1. 创建一个新的“控制台应用”项目。
2. 将代码粘贴到主 `.c` 文件中。
3. 使用快捷键 `Ctrl + F5` (开始执行，不调试) 来编译并运行程序。

### 4. 技术栈
- **语言**: C
- **核心知识**: 结构化编程, 数据结构(Struct, Array), 文件I/O, CRUD模型, 模块化设计

---

# Command-Line Student Information Management System in C

### 1. Project Overview
This is a command-line student information management system independently developed in C. The project focuses on practicing core C programming skills and structured programming principles. It fully implements CRUD (Create, Read, Update, Delete) functionalities for student records and achieves data persistence through file I/O, allowing the application to retain its state after closing.

### 2. Core Features
- **Create Student**: Add a new student record (ID, Name, Score) with a check for ID uniqueness.
- **Read Student**: Search for a specific student by ID or display a list of all students currently in the system.
- **Update Student**: Modify the information of a specific student located by ID.
- **Delete Student**: Remove a specific student record from the system by ID.
- **Data Persistence**: 
    - Automatically loads data from a local file (`students.txt`) upon program startup.
    - Automatically saves all data from memory back to `students.txt` upon program exit.

### 3. How to Compile & Run

**Using GCC Compiler (Linux/Mac/MinGW):**
```bash
# Compile
gcc main.c -o student_system

# Run
./student_system
```

**Using Visual Studio (Windows):**
1. Create a new "Console App" project.
2. Paste the code into the main `.c` file.
3. Use the shortcut `Ctrl + F5` (Start Without Debugging) to compile and run the program.

### 4. Tech Stack
- **Language**: C
- **Core Concepts**: Structured Programming, Data Structures (Struct, Array), File I/O, CRUD Model, Modular Design
