#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

typedef struct Node {
    struct Node* next;
    int data;
} Node; // 16 bytes

void setList();

#endif