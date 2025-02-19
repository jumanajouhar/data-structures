// Construct binary search tree using total marks  calculate rank of the students of your class. display name reg no .total mark rank through inorder traversal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
  char name[MAX_NAME_LEN];
  int reg_no;
  int marks;
  int rank;
  struct Student *left;
  struct Student *right;
} Student;

Student *new_student(char *name, int reg_no, int marks) {
  Student *s = (Student *)malloc(sizeof(Student));
  strcpy(s->name, name);
  s->reg_no = reg_no;
  s->marks = marks;
  s->rank = 0;
  s->left = NULL;
  s->right = NULL;
  return s;
}

Student *insert(Student *root, Student *s) {
  if (root == NULL) {
    return s;
  }
  if (s->marks > root->marks) {
    root->right = insert(root->right, s);
  } else {
    root->left = insert(root->left, s);
  }
  return root;
}

void set_ranks(Student *root, int *current_rank) {
  if (root == NULL) {
    return;
  }
  set_ranks(root->right, current_rank);
  root->rank = (*current_rank)++;
  set_ranks(root->left, current_rank);
}

void inorder_traverse(Student *root) {
  if (root == NULL) {
    return;
  }
  inorder_traverse(root->left);
  printf("Name: %s, Reg No: %d, Marks: %d, Rank: %d\n", root->name, root->reg_no, root->marks, root->rank);
  inorder_traverse(root->right);
}

int main() {
  Student *root = NULL;
  root = insert(root, new_student("Alice", 1, 90));
  root = insert(root, new_student("Bob", 2, 80));
  root = insert(root, new_student("Eve", 3, 70));
  root = insert(root, new_student("Mallory", 4, 60));
  root = insert(root, new_student("Trent", 5, 50));

  int rank = 1;
  set_ranks(root, &rank);

  inorder_traverse(root);

  return 0;
}
