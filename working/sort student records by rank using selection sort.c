/*To implement a program to sort student records using selection sort with details - Roll no, Reg no, name, total marks and rank
rank is not input. assign ranks on the basis of total marks via sorting*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// structure for a student record
typedef struct student {
    int roll_no;
    int reg_no;
    char name[50];
    float total_marks;
    int rank;
} Student;

// function to swap two student records
void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort student records by total marks using selection sort
void sort_students(Student* students, int n) {
    for (int i = 0; i < n - 1; i++) {
        // find the minimum element in the unsorted portion of the array
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j].total_marks > students[min_index].total_marks) {
                min_index = j;
            }
        }
        // swap the minimum element with the first element in the unsorted portion of the array
        swap(&students[min_index], &students[i]);
    }
}

int main() {
    // create an array of student records
    Student students[MAX_STUDENTS] = {
        {1, 1001, "John", 78.5, 0},
        {2, 1002, "Jane", 85.5, 0},
        {3, 1003, "Bob", 65.0, 0},
        {4, 1004, "Alice", 92.0, 0}
    };
    int n = 4;

    // sort the student records by total marks
    sort_students(students, n);

    // assign ranks to the student records
    for (int i = 0; i < n; i++) {
        students[i].rank = i + 1;
    }

    // print the sorted student records
    for (int i = 0; i < n; i++) {
        printf("Roll no: %d\n", students[i].roll_no);
        printf("Reg no: %d\n", students[i].reg_no);
        printf("Name: %s\n", students[i].name);
        printf("Total marks: %.2f\n", students[i].total_marks);
        printf("Rank: %d\n", students[i].rank);
        printf("\n");
    }

    return 0;
}
