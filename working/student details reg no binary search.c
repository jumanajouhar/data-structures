/* Display student details using binary search. Search should be done with reg no. Assume input is unsorted.
 Details
Roll no, reg no, name, sem, department */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// structure for a student record
typedef struct student {
    int roll_no;
    int reg_no;
    char name[50];
    int sem;
    char department[50];
} Student;

// function to search for a student record by registration number using binary search
Student* search_student(Student* students, int n, int reg_no) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].reg_no == reg_no) {
            return &students[mid];
        }
        else if (students[mid].reg_no < reg_no) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return NULL;
}

int main() {
    // create an array of student records
    Student students[MAX_STUDENTS] = {
        {1, 1001, "John", 3, "Computer Science"},
        {2, 1002, "Jane", 4, "Electrical Engineering"},
        {3, 1003, "Bob", 2, "Mechanical Engineering"},
        {4, 1004, "Alice", 3, "Computer Science"}
    };
    int n = 4;

    // search for a student by registration number
    int reg_no;
    printf("Enter registration number: ");
    scanf("%d", &reg_no);
    Student* student = search_student(students, n, reg_no);

    // print the student details
    if (student) {
        printf("Roll no: %d\n", student->roll_no);
        printf("Reg no: %d\n", student->reg_no);
        printf("Name: %s\n", student->name);
        printf("Sem: %d\n", student->sem);
        printf("Department: %s\n", student->department);
    }
    else {
        printf("Student not found\n");
    }

    return 0;
}
