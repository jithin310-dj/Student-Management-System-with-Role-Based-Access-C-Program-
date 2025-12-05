#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
typedef struct {
    char username[20];
    char password[20];
    char role[10];
} User;
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;
Student students[MAX_STUDENTS];
int studentCount = 0;
void displayStudents() {
    int i;
    if (studentCount == 0) {
        printf("\nNo students available.\n");
        return;
    }
    printf("\nID\tNAME\tMARKS\n");
    for (i = 0; i < studentCount; i++)
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].marks);
}
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent list is full.\n");
        return;
    }
    Student s;
    printf("\nEnter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    students[studentCount++] = s;
    printf("\nStudent added successfully.\n");
}
int findStudentIndexById(int id) {
    int i;
    for (i = 0; i < studentCount; i++)
        if (students[i].id == id)
            return i;
    return -1;
}
void searchStudent() {
    int id, idx;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);
    idx = findStudentIndexById(id);
    if (idx == -1)
        printf("\nStudent not found.\n");
    else
        printf("\nID: %d\nName: %s\nMarks: %.2f\n", students[idx].id, students[idx].name, students[idx].marks);
}
void updateStudent() {
    int id, idx;
    printf("\nEnter ID to update: ");
    scanf("%d", &id);
    idx = findStudentIndexById(id);
    if (idx == -1) {
        printf("\nStudent not found.\n");
        return;
    }
    printf("Enter new Name: ");
    scanf("%s", students[idx].name);
    printf("Enter new Marks: ");
    scanf("%f", &students[idx].marks);
    printf("\nStudent updated successfully.\n");
}
void deleteStudent() {
    int id, idx, i;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);
    idx = findStudentIndexById(id);
    if (idx == -1) {
        printf("\nStudent not found.\n");
        return;
    }
    for (i = idx; i < studentCount - 1; i++)
        students[i] = students[i + 1];
    studentCount--;
    printf("\nStudent deleted successfully.\n");
}
void adminMenu() {
    int choice;
    do {
        printf("\n===== ADMIN MENU =====\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Logout\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("\nLogging out...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 6);
}
void staffMenu() {
    int choice;
    do {
        printf("\n===== STAFF MENU =====\n");
        printf("1. Display Students\n2. Search Student\n3. Update Student\n4. Logout\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displayStudents(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: printf("\nLogging out...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 4);
}
void userMenu() {
    int choice;
    do {
        printf("\n===== USER MENU =====\n");
        printf("1. Display Students\n2. Search Student\n3. Logout\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displayStudents(); break;
            case 2: searchStudent(); break;
            case 3: printf("\nLogging out...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 3);
}
void guestMenu() {
    int choice;
    do {
        printf("\n===== GUEST MENU =====\n");
        printf("1. Display Students\n2. Logout\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displayStudents(); break;
            case 2: printf("Logging out...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 2);
}
int login(User users[], int n, User *loggedIn) {
    char uname[20], pass[20];
    int i;
    printf("\n===== Login =====\nUsername: ");
    scanf("%s", uname);
    printf("Password: ");
    scanf("%s", pass);
    for (i = 0; i < n; i++)
        if (strcmp(uname, users[i].username) == 0 && strcmp(pass, users[i].password) == 0) {
            *loggedIn = users[i];
            return 1;
        }
    return 0;
}
int main() {
    User users[] = {
        {"admin", "admin123", "ADMIN"},
        {"staff", "staff123", "STAFF"},
        {"guest", "guest123", "GUEST"},
        {"user", "user123", "USER"}
    };
    int userCount = 4;
    students[0].id = 1002; strcpy(students[0].name, "SHRAVAN"); students[0].marks = 560.0;
    students[1].id = 1003; strcpy(students[1].name, "Rayalu"); students[1].marks = 580.0;
    students[2].id = 1004; strcpy(students[2].name, "Pks"); students[2].marks = 585.0;
    students[3].id = 1005; strcpy(students[3].name, "Mahesh"); students[3].marks = 589.0;
    students[4].id = 1006; strcpy(students[4].name, "Suresh"); students[4].marks = 499.0;
    studentCount = 5;
    while (1) {
        User current;
        if (!login(users, userCount, &current)) {
            printf("\nInvalid username or password. Try again.\n");
            continue;
        }
        printf("\nLogged in as %s (%s)\n", current.username, current.role);
        if (!strcmp(current.role, "ADMIN"))
            adminMenu();
        else if (!strcmp(current.role, "STAFF"))
            staffMenu();
        else if (!strcmp(current.role, "GUEST"))
            guestMenu();
        else
            userMenu();
    }
    return 0;
}
