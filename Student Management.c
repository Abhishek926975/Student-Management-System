#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll_no;
    char name[50];
    int age;
    char course[50];
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("❌ Cannot add more students. Limit reached!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &students[count].roll_no);
    getchar(); // consume newline

    printf("Enter Name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &students[count].age);
    getchar();

    printf("Enter Course: ");
    fgets(students[count].course, sizeof(students[count].course), stdin);
    students[count].course[strcspn(students[count].course, "\n")] = 0;

    count++;
    printf("✅ Student added successfully!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n----- Student List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d | Name: %s | Age: %d | Course: %s\n",
               students[i].roll_no, students[i].name, students[i].age, students[i].course);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("🔍 Found: Roll No: %d | Name: %s | Age: %d | Course: %s\n",
                   students[i].roll_no, students[i].name, students[i].age, students[i].course);
            return;
        }
    }
    printf("❌ Student not found.\n");
}

void updateStudent() {
    int roll;
    printf("Enter Roll No to update: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("Enter New Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);
            getchar();

            printf("Enter New Course: ");
            fgets(students[i].course, sizeof(students[i].course), stdin);
            students[i].course[strcspn(students[i].course, "\n")] = 0;

            printf("✅ Student updated successfully!\n");
            return;
        }
    }
    printf("❌ Student not found.\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("🗑️ Student deleted successfully!\n");
            return;
        }
    }
    printf("❌ Student not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("🚪 Exiting... Thank you!\n");
                exit(0);
            default: 
                printf("❌ Invalid choice. Try again.\n");
        }
    }
    return 0;
}
