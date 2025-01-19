#include "function.h"

bool checkrow(row_node* head, int index){
    while(head==NULL){
        if(head->row == index)
            return 1;
        head = head->next;
    }
    return 0;
}

row_node* create_row_node(int index){
    row_node* temp = (row_node*)malloc(sizeof(row_node));
    temp->row = index;
    temp->ptr = NULL;
    temp->next = NULL;
    return temp;
}

col_node* create_col_node(int col, int val){
    col_node* temp = (col_node*)malloc(sizeof(col_node));
    temp->col = col;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

row_node* insert_row(row_node* head, row_node* temp){
    row_node* curr = head;
    row_node* prev = NULL;
    while(curr->row < temp->row){
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
    return head;
}

row_node* insert_col(row_node* head, col_node* temp, int row){
    row_node* run = head;
    while(run->row != row){
        run = run->next;
    }
    col_node* prev = NULL;
    col_node* curr = run->ptr;
    while(curr->col < temp->col){
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
    return head;
}
