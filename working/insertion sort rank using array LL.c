// Using insertion sort arrange rank of students using array and linked list

//implement insertion sort in C to sort an array of student records by their rank

#include <stdio.h>
#include <stdlib.h>

// Struct to represent a student
typedef struct {
  int rank;
  char name[100];
} Student;

// Function prototypes
void insertion_sort(Student *students, int n);
void print_students(Student *students, int n);

int main(int argc, char **argv) {
  // Create an array of students
  Student students[] = {{3, "Alice"}, {1, "Bob"}, {4, "Eve"}, {2, "Mallory"}};
  int n = sizeof(students) / sizeof(Student);

  // Sort the array of students by their rank
  insertion_sort(students, n);

  // Print the sorted array of students
  print_students(students, n);

  return 0;
}

void insertion_sort(Student *students, int n) {
  for (int i = 1; i < n; i++) {
    Student key = students[i];
    int j = i - 1;
    while (j >= 0 && students[j].rank > key.rank) {
      students[j + 1] = students[j];
      j--;
    }
    students[j + 1] = key;
  }
}

void print_students(Student *students, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d %s\n", students[i].rank, students[i].name);
  }
}
