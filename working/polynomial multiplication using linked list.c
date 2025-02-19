#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *next;
};

struct node *create_node(int coefficient, int exponent) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

struct node *insert_node(struct node *head, struct node *new_node) {
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

struct node *polynomial_multiplication(struct node *p1, struct node *p2) {
    struct node *result = NULL;
    struct node *temp1 = p1;
    while (temp1 != NULL) {
        struct node *temp2 = p2;
        while (temp2 != NULL) {
            int coefficient = temp1->coefficient * temp2->coefficient;
            int exponent = temp1->exponent + temp2->exponent;
            struct node *new_node = create_node(coefficient, exponent);
            result = insert_node(result, new_node);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

void print_polynomial(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *poly1 = create_node(1, 2);
    poly1 = insert_node(poly1, create_node(2, 1));
    poly1 = insert_node(poly1, create_node(3, 0));
    printf("Polynomial 1: ");
    print_polynomial(poly1);

    struct node *poly2 = create_node(1, 2);
    poly2 = insert_node(poly2, create_node(2, 1));
    poly2 = insert_node(poly2, create_node(4, 0));
    printf("Polynomial 2: ");
    print_polynomial(poly2);

    struct node *result = polynomial_multiplication(poly1, poly2);
    printf("Result: ");
    print_polynomial(result);

    return 0;
}
