/*students are swiping their id card to mark attendance at the beginning of the class.
They have a relaxation of 10 minutes to list details of all late students in a class without sorting.
Use appropriate data structure. The details are date, time, register number, semester, department, course name.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char date[20];
  char time[20];
  int registerNumber;
  int semester;
  char department[20];
  char courseName[20];
  struct node *next;
};

void addNode(struct node **head, struct node **tail, char *date, char *time, int registerNumber, int semester, char *department, char *courseName) {
  struct node *newNode = malloc(sizeof(struct node));
  strcpy(newNode->date, date);
  strcpy(newNode->time, time);
  newNode->registerNumber = registerNumber;
  newNode->semester = semester;
  strcpy(newNode->department, department);
  strcpy(newNode->courseName, courseName);
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  }
  if (*tail != NULL) {
    (*tail)->next = newNode;
  }
  *tail = newNode;
}

void deleteNode(struct node **head, struct node **tail, int registerNumber) {
  struct node *current = *head;
  struct node *prev = NULL;
  while (current != NULL) {
    if (current->registerNumber == registerNumber) {
      if (prev == NULL) {
        *head = current->next;
      } else {
        prev->next = current->next;
      }
      if (current->next == NULL) {
        *tail = prev;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void printList(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("Date: %s\n", current->date);
    printf("Time: %s\n", current->time);
    printf("Register number: %d\n", current->registerNumber);
    printf("Semester: %d\n", current->semester);
    printf("Department: %s\n", current->department);
    printf("Course name: %s\n", current->courseName);
    current = current->next;
  }
}

int main() {
  struct node *head = NULL;
  struct node *tail = NULL;

  addNode(&head, &tail, "2022-01-01", "10:00:00", 123456, 1, "Computer Science", "Data Structures");
  addNode(&head, &tail, "2022-01-02", "11:00:00", 234567, 2, "Computer Science", "Algorithms");
  addNode(&head, &tail, "2022-01-03", "12:00:00", 345678, 3, "Computer Science", "Computer Networks");

  deleteNode(&head, &tail, 234567);

  printList(head);

  return 0;
  
}

