#include "function.c"

int main(){
    
    int n;
    scanf("%d", &n);
    char* query = (char*)malloc(sizeof(char)*5);
    int len;
    while(n--){
        scanf("%s", query);
        if(query[4]=='1'){
            scanf("%d", &len);
            char* str = (char*)malloc(sizeof(char)*(len+1));
            scanf("%s", str);
            reverseString(str, len);
            printf("%s\n", str);
        }
        else if(query[4]=='2'){
            scanf("%d", &len);
            char* str = (char*)malloc(sizeof(char)*(len+1));
            scanf("%s", str);
            printf("%s\n", compressString(str, len));
        }
        else if(query[4]=='3'){
            scanf("%d", &len);
            int* arr = (int*)malloc(sizeof(int)*len);
            for(int i=0;i<len;i++){
                scanf("%d", &arr[i]);
            }
            int* res = uniqueElements(arr, len);
            for(int i=0;i<ind;i++){
                printf("%d ", res[i]);
            }
        }
        else if(query[4]=='4'){
            int row, col;
            scanf("%d %d", &row, &col);
            int** arr = (int**)malloc(sizeof(int*)*row);
            for(int i=0;i<row;i++){
                arr[i] = (int*)malloc(sizeof(int)*col);
                for(int j=0;j<col;j++){
                    scanf("%d", &arr[i][j]);
                }
            }
            int** res = transpose(arr, row, col);
            for(int i=0;i<col;i++){
                for(int j=0;j<row;j++){
                    printf("%d ", res[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
