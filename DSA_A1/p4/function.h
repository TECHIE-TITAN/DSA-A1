#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ele;
    struct node* prev;
    struct node* next;
}node;

node* Insert(node* head, int num);
node* Find(node* head, int num);
void Print(node* head);
