#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int col;
    int val;
    struct Node* next;
}col_node;

typedef struct node{
    int row;
    col_node* ptr;
    struct node* next;
}row_node;

