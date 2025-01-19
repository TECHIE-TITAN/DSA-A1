#include "function.c"

int main(){
    node* head = NULL;
    int n;
    scanf("%d", &n);
    char* query = (char*)malloc(sizeof(char)*6);
    int num;
    while(n--){
        scanf("%s", query);
        if(query[4]=='1'){
            scanf("%d", &num);
            head = Insert(head, num);
        }
        else if(query[4]=='2'){
            scanf("%d", &num);
            head = Find(head, num);
        }
        else if(query[4]=='3'){
            Print(head);
        }
    }
    return 0;
}
