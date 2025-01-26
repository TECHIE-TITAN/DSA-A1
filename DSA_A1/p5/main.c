#include "function.c"

int main(){
    
    char* query = (char*)malloc(sizeof(char)*4);
    scanf("%s", query);

    if(query[0]=='T'){
        row_node* head = NULL;
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int row, col, val;
        for(int i=0;i<k;i++){
            scanf("%d %d %d", &row, &col, &val);
            head = sparse_matrix(head, row, col, val);
        }
        row_node* res = transpose(head);
        printf("%d\n", k);
        print(res);
        free(head);
        free(res);
    }
    else if(query[0]=='A'){
        row_node* num1 = NULL;
        row_node* num2 = NULL;
        int n, m, k1, k2;
        scanf("%d %d %d %d", &n, &m, &k1, &k2);
        int row, col, val;
        for(int i=0;i<k1;i++){
            scanf("%d %d %d", &row, &col, &val);
            num1 = sparse_matrix(num1, row, col, val);
        }
        for(int i=0;i<k2;i++){
            scanf("%d %d %d", &row, &col, &val);
            num2 = sparse_matrix(num2, row, col, val);
        }
        int count = 0;
        row_node* result = add_matrix(num1, num2, n, m, &count);
        printf("%d\n", count);
        print(result);
        free(num1);
        free(num2);
        free(result);
    }
}
