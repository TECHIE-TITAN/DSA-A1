#include "function.c"

int main(){
    row_node* head = NULL;
    row_node* temp_row_node = NULL;
    col_node* temp_col_node = NULL;
    char* query = (char*)malloc(sizeof(char)*4);
    scanf("%s", query);

    if(strcmp(query, "TRA")==0){
        int m, n, k, row, col, val;
        scanf("%d %d %d", &n, &m, &k);
        for(int i=0;i<k;i++){
            scanf("%d %d %d", &row, &col, &val);
            if(checkrow(head, row)==0){
                temp_row_node = create_row_node(row);
                head = insert_row(head, temp_row_node);
            }
            temp_col_node = create_col_node(col, val);
            head = insert_col(head, temp_col_node, row);
        }
        
    }
}
