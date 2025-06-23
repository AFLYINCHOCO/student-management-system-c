#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- 宏定义与全局变量 ---

#define MAX_STUDENTS 100     // 系统最多能存储的学生数量
#define MAX_NAME_LEN 50      // 学生姓名的最大长度
#define DATA_FILE "students.txt" // 数据持久化文件名

// --- 数据结构定义 ---

// 使用结构体(struct)来封装一个学生的完整信息
typedef struct {
    int id;                      // 学号 (唯一标识)
    char name[MAX_NAME_LEN];     // 姓名
    float score;                 // 成绩
} Student;

// --- 全局数据区 ---

Student students[MAX_STUDENTS]; // 使用结构体数组，作为在内存中存储所有学生的“数据库”
int student_count = 0;          // 全局变量，记录当前系统中实际的学生数量

// --- 函数声明 ---
// 这样做可以让main函数更清晰，也符合结构化编程思想

void displayMenu();      // 显示主菜单
void addStudent();       // 添加学生信息
void findStudent();      // 查询单个学生信息
void displayAllStudents(); // 显示所有学生信息
void updateStudent();    // 修改学生信息
void deleteStudent();    // 删除学生信息
void saveToFile();       // 将数据保存到文件
void loadFromFile();     // 从文件加载数据

// --- 主函数 (程序入口) ---

int main() {
    int choice;

    // 1. 程序启动时，首先尝试从文件加载数据
    loadFromFile();

    // 2. 进入主循环，等待用户操作
    while (1) {
        displayMenu();
        printf("请输入您的选择 (1-7): ");
        scanf("%d", &choice);

        // 清除输入缓冲区，防止影响后续的字符串输入
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            findStudent();
            break;
        case 3:
            displayAllStudents();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            saveToFile();
            break;
        case 7:
            // 在退出前自动保存一次，确保数据不丢失
            saveToFile();
            printf("感谢使用，系统已退出。\n");
            return 0; // 正常退出程序
        default:
            printf("无效输入，请输入1到7之间的数字。\n");
            break;
        }
        printf("\n按回车键继续...");
        while (getchar() != '\n'); // 等待用户按回车
    }

    return 0;
}

// --- 各模块功能函数的具体实现 ---

// 显示主菜单
void displayMenu() {
    system("cls || clear"); // 清屏命令，兼容Windows(cls)和Linux/Mac(clear)
    printf("====================================\n");
    printf("     学生信息管理系统 V1.0\n");
    printf("====================================\n");
    printf("  1. 添加学生信息\n");
    printf("  2. 查询学生信息\n");
    printf("  3. 显示所有学生信息\n");
    printf("  4. 修改学生信息\n");
    printf("  5. 删除学生信息\n");
    printf("  6. 手动保存数据到文件\n");
    printf("  7. 退出系统\n");
    printf("====================================\n");
}

// 1. 添加学生信息 (Create)
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("系统已满，无法添加更多学生！\n");
        return;
    }

    Student new_student;
    printf("请输入新学生的学号: ");
    scanf("%d", &new_student.id);
    while (getchar() != '\n');

    // 检查学号唯一性
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == new_student.id) {
            printf("错误：学号 %d 已存在！\n", new_student.id);
            return;
        }
    }

    printf("请输入新学生的姓名: ");
    scanf("%s", new_student.name);

    printf("请输入新学生的成绩: ");
    scanf("%f", &new_student.score);

    // 将新学生存入数组，并更新计数器
    students[student_count] = new_student;
    student_count++;

    printf("学生信息添加成功！\n");
}

// 2. 查询学生信息 (Read)
void findStudent() {
    if (student_count == 0) {
        printf("系统中没有任何学生信息。\n");
        return;
    }
    int id_to_find;
    printf("请输入要查询的学生的学号: ");
    scanf("%d", &id_to_find);
    while (getchar() != '\n');

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id_to_find) {
            printf("找到了学生信息：\n");
            printf("学号: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("成绩: %.2f\n", students[i].score);
            return;
        }
    }
    printf("未找到学号为 %d 的学生。\n", id_to_find);
}

// 3. 显示所有学生信息
void displayAllStudents() {
    if (student_count == 0) {
        printf("系统中没有任何学生信息。\n");
        return;
    }
    printf("所有学生信息如下：\n");
    printf("------------------------------------\n");
    printf("学号\t\t姓名\t\t成绩\n");
    printf("------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].score);
    }
    printf("------------------------------------\n");
}

// 4. 修改学生信息 (Update)
void updateStudent() {
    if (student_count == 0) {
        printf("系统中没有任何学生信息。\n");
        return;
    }
    int id_to_update;
    printf("请输入要修改的学生的学号: ");
    scanf("%d", &id_to_update);
    while (getchar() != '\n');

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id_to_update) {
            printf("找到了学号为 %d 的学生，请输入新信息：\n", id_to_update);
            printf("请输入新的姓名: ");
            scanf("%s", students[i].name);
            printf("请输入新的成绩: ");
            scanf("%f", &students[i].score);
            printf("学生信息修改成功！\n");
            return;
        }
    }
    printf("未找到学号为 %d 的学生。\n", id_to_update);
}

// 5. 删除学生信息 (Delete)
void deleteStudent() {
    if (student_count == 0) {
        printf("系统中没有任何学生信息。\n");
        return;
    }
    int id_to_delete;
    int index_to_delete = -1;

    printf("请输入要删除的学生的学号: ");
    scanf("%d", &id_to_delete);
    while (getchar() != '\n');

    // 首先找到要删除的学生在数组中的位置(索引)
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id_to_delete) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("未找到学号为 %d 的学生。\n", id_to_delete);
    }
    else {
        // 将被删除元素之后的所有元素，依次向前移动一个位置
        for (int i = index_to_delete; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--; // 学生总数减一
        printf("学号为 %d 的学生信息已删除。\n", id_to_delete);
    }
}

// 6. 将数据保存到文件 (Save - 持久化)
void saveToFile() {
    FILE* file_pointer = fopen(DATA_FILE, "w"); // "w"模式：写入，会覆盖原文件

    if (file_pointer == NULL) {
        printf("错误：无法打开数据文件 %s 进行写入！\n", DATA_FILE);
        return;
    }

    // 循环遍历内存中的学生数组，将每条记录写入文件
    for (int i = 0; i < student_count; i++) {
        fprintf(file_pointer, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].score);
    }

    fclose(file_pointer); // 关闭文件是个好习惯
    printf("数据已成功保存到 %s 文件中。\n", DATA_FILE);
}

// 7. 从文件加载数据 (Load - 持久化)
void loadFromFile() {
    FILE* file_pointer = fopen(DATA_FILE, "r"); // "r"模式：读取

    if (file_pointer == NULL) {
        // 如果文件不存在（比如第一次运行），这不是一个错误，只是说明没有数据可加载
        printf("提示：未找到数据文件 %s，将以空系统启动。\n", DATA_FILE);
        return;
    }

    // 循环从文件中读取数据，直到文件末尾
    // fscanf返回成功读取的项数，我们期望每行读到3项
    while (student_count < MAX_STUDENTS &&
        fscanf(file_pointer, "%d,%[^,],%f\n",
            &students[student_count].id,
            students[student_count].name,
            &students[student_count].score) == 3) {
        student_count++;
    }

    fclose(file_pointer);
    printf("已从 %s 文件中成功加载了 %d 条数据。\n", DATA_FILE, student_count);
}