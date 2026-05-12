#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

int main() {
    Node* head;
    Node* tail;

    Node* a;
    Node* b;

    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));

    head = a;

    a->data = 1;
    b->data = 2;

    a->next = b;
    b->next = NULL;

    tail = b;

    Node* current = a;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("%p, %p\n", &a, &b);
    printf("%p, %p", &head, &tail);

    return 0;
}