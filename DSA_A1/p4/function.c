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
    
    // If the list is empty
    if(head==NULL)
        return head;
    node* temp = head;
    // Traverse to the element, if not found return
    while(temp->ele!=num){
        temp = temp->next;
        if(temp==head)
            return head;
    }

    if(temp==head){             // If the element is at first pos
        return head;
    }
    else if(temp->next==head){  // If the element is at last pos
        head = temp;
        return head;
    }

    // If the element is at any other general pos
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
    if(head==NULL)
        return;
    node* temp = head;
    do
    {
        printf("%d ", temp->ele);
        temp = temp->next;
    } while (temp!=head);
        printf("\n");
    return;
}
