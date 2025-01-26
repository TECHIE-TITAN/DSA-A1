#include "function.h"

bool checkrow(row_node* head, int index){
    while(head!=NULL){
        if(head->row == index)
            return 1;
        head = head->next;
    }
    return 0;
}

bool checkrow_add(row_node* row_tail, int index){
    if(row_tail==NULL || row_tail->row != index)
        return 0;
    else return 1;
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

row_node* insert_row_add(row_node* head, row_node** tail, row_node* temp){
    if(head==NULL){
        head = temp;
        (*tail) = head;
        return head;
    }
    (*tail)->next = temp;
    (*tail) = (*tail)->next;
    return head;
}

row_node* insert_col_add(row_node* head, row_node** row_tail, col_node** col_tail, col_node* temp){
    if((*row_tail)->ptr == NULL){
        (*row_tail)->ptr = temp;
        (*col_tail) = (*row_tail)->ptr;
        return head;
    }
    (*col_tail)->next = temp;
    (*col_tail) = (*col_tail)->next;
    return head;
}

row_node* sparse_matrix_add(row_node* head, row_node** row_tail, col_node** col_tail, int row, int col, int val){
    row_node* temp_row_node = NULL;
    col_node* temp_col_node = NULL;

    if(checkrow_add((*row_tail), row)==0){
        temp_row_node = create_row_node(row);
        head = insert_row_add(head, row_tail, temp_row_node);
    }
    temp_col_node = create_col_node(col, val);
    head = insert_col_add(head, row_tail, col_tail, temp_col_node);
    return head;
}

row_node* insert_row_tra(row_node* head, row_node* temp){
    if(head==NULL){
        head = temp;
        return head;
    }
    row_node* curr = head;
    row_node* prev = NULL;
    while(curr->row < temp->row){
        if(curr->next==NULL){
            curr->next = temp;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    if(prev==NULL)
        head = temp;
    else prev->next = temp;
    temp->next = curr;
    return head;
}

row_node* insert_col_tra(row_node* head, col_node* temp, int row){
    row_node* run = head;
    while(run->row != row){
        run = run->next;
    }
    if(run->ptr == NULL){
        run->ptr = temp;
        return head;
    }
    col_node* prev = NULL;
    col_node* curr = run->ptr;
    while(curr->col < temp->col){
        if(curr->next==NULL){
            curr->next = temp;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
    return head;
}

row_node* sparse_matrix_tra(row_node* head, int row, int col, int val){
    row_node* temp_row_node = NULL;
    col_node* temp_col_node = NULL;
    //int row, col, val;        /* scanf("%d %d %d", &row, &col, &val); */
    if(checkrow(head, row)==0){
        temp_row_node = create_row_node(row);
        head = insert_row_tra(head, temp_row_node);
    }
    temp_col_node = create_col_node(col, val);
    head = insert_col_tra(head, temp_col_node, row);
    return head;
}

row_node* transpose(row_node* head){
    row_node* s = head;
    row_node* res = NULL;
    while(s!=NULL){
        col_node* t = s->ptr;
        while(t!=NULL){
            res = sparse_matrix_tra(res, t->col, s->row, t->val);
            t = t->next;
        }
        s = s->next;
    }
    return res;
}

row_node* add_matrix(row_node* mat1, row_node* mat2, int n, int m, int* count){
    row_node* res = NULL;
    row_node* row_tail = NULL;
    col_node* col_tail = NULL;
    row_node* s1 = mat1;
    row_node* s2 = mat2;
    while(s1!=NULL || s2!=NULL){
        if(s1!=NULL && s2!=NULL){
            col_node* t1 = s1->ptr;
            col_node* t2 = s2->ptr;
            if(s1->row == s2->row){
                while(t1!=NULL || t2!=NULL){
                    if(t1!=NULL && t2!=NULL){
                        if(t1->col == t2->col){
                            if(t1->val+t2->val != 0){
                                res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t1->col, t1->val+t2->val);
                                (*count)++;
                            }
                            t1 = t1->next;
                            t2 = t2->next;
                        }
                        else if(t1->col < t2->col){
                            res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t1->col, t1->val);
                            (*count)++;
                            t1 = t1->next;
                        }
                        else if(t2->col < t1->col){
                            res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t2->col, t2->val);
                            (*count)++;
                            t2 = t2->next;
                        }
                    }
                    else if(t1==NULL){
                        res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t2->col, t2->val);
                        (*count)++;
                        t2 = t2->next;
                    }
                    else if(t2==NULL){
                        res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t1->col, t1->val);
                        (*count)++;
                        t1 = t1->next;
                    }
                }
                s1 = s1->next;
                s2 = s2->next;
            }
            else if(s1->row < s2->row){
                while(t1!=NULL){
                    res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t1->col, t1->val);
                    (*count)++;
                    t1 = t1->next;
                }
                s1 = s1->next;
            }
            else if(s2->row < s1->row){
                while(t2!=NULL){
                    res = sparse_matrix_add(res, &row_tail, &col_tail, s2->row, t2->col, t2->val);
                    (*count)++;
                    t2 = t2->next;
                }
                s2 = s2->next;
            }
        }
        else if(s1==NULL){
            col_node* t2 = s2->ptr;
            while(t2!=NULL){
                res = sparse_matrix_add(res, &row_tail, &col_tail, s2->row, t2->col, t2->val);
                (*count)++;
                t2 = t2->next;
            }
            s2 = s2->next;
        }
        else if(s2==NULL){
            col_node* t1 = s1->ptr;
            while(t1!=NULL){
                res = sparse_matrix_add(res, &row_tail, &col_tail, s1->row, t1->col, t1->val);
                (*count)++;
                t1 = t1->next;
            }
            s1 = s1->next;
        }
    }
    return res;
}

void print(row_node* head){
    row_node* s = head;
    while(s!=NULL){
        col_node* t = s->ptr;
        while(t!=NULL){
            printf("%d %d %d\n", s->row, t->col, t->val);
            t = t->next;
        }
        s = s->next;
    }
}