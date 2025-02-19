// represent a expression using binary tree and perform postorder traversal. Linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a binary tree node
typedef struct node {
  char data;
  struct node *left;
  struct node *right;
}*root;

// Linked list node structure for postorder traversal
typedef struct list_node {
  char data;
  struct list_node *next;
} ListNode;

// Creates a new binary tree node and returns a pointer to it
struct node *createNode(char data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}


// Recursive function to perform postorder traversal of the binary tree
// and store the result in a linked list
void postorder(struct node *root, ListNode **head) {
  if (root == NULL) return;
  postorder(root->left, head);
  postorder(root->right, head);
  printf("%c",root->data);
 
}

int main() {
  // Create the binary tree representation of the expression (1 + 2) * (3 - 4)
  //        *
  //       / \
  //      +   -
  //     / \ / \
  //    1  2 3  4
  struct node* root = createNode('*');
  root->left = createNode('+');
  root->left->left = createNode('1');
  root->left->right = createNode('2');
  root->right = createNode('-');
  root->right->left = createNode('3');
  root->right->right = createNode('4');

  // Perform postorder traversal of the binary tree and store the result in a linked list
  ListNode *head = NULL;
   printf("Postorder traversal: ");
  postorder(root, &head);

  // Print the linked list
 
 

  printf("\n");

  return 0;
}
