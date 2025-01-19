#include "function.h"

node* createnode(int num){
    node* temp = (node*)malloc(sizeof(node));
    temp->ele = num;
    temp->prev = NULL;
    temp->next = NULL; 
    return temp;
}

node* Insert(node* head, int num){
    if(head==NULL){
        head = createnode(num);
        head->prev = head;
        head->next = head;
        return head;
    }
    
    node* temp = head->prev; 
    head->prev = createnode(num);
    temp->next = head->prev;
    head->prev->next = head;
    temp->next->prev = temp;
    head = head->prev;
    temp = NULL;
    free(temp);
    return head;
}

node* Find(node* head, int num){
    node* temp = head;
    while(temp->ele!=num){
        temp = temp->next;
        if(temp==head)
            return head;
    }

    if(temp->next==head){
        return head;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = NULL;
    temp->prev = NULL;

    head->prev->next = temp;
    temp->prev = head->prev;
    head->prev = temp;
    temp->next = head;
    head = temp;
    temp = NULL;
    free(temp);
    return head;
}

void Print(node* head){
    node* temp = head;
    do
    {
        printf("%d ", temp->ele);
        temp = temp->next;
    } while (temp!=head);
    return;
}
