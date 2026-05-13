#include <stdio.h>
#include <stdlib.h>
#include "memory_management.h"

void set_list() {
    Node *head;
    Node *tail;

    Node *a;
    Node *b;
    Node *c;
    Node *d;

    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));
    c = malloc(sizeof(Node));
    d = malloc(sizeof(Node));

    head = a;

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    tail = d;

    Node* current = a;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    
    free(a);
    free(b);
    free(c);
    free(d);

    printf("%p, %p\n", &a, &b);
    printf("%p, %p\n\n", &c, &d);
    printf("%p, %p", &head, &tail);
}