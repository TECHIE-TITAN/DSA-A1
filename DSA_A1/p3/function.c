#include "function.h"

void reverseString(char* str, int length){
    int left = 0;
    int right = length-1;
    char ch;
    while((right)>(left)){
        ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        right--;
        left++;
    }
    return;
}

// Removed many realloc usage to tackle RTE(aborted)
char* compressString(char* str, int length){

    char ch = str[0];
    int count = 1;

    char* res = (char*)malloc(sizeof(char)*(2*length + 1));
    int reslen = 0;
    
    char* num = (char*)malloc(sizeof(char)*(6));
    int num_count = 0;

    int i = 0;
    for(i = 1; i<length; i++){
        if(str[i]==ch){
            count++;
        }
        else{
            res[reslen++] = ch;
            if(count>9){
                num_count = 0;
                while(count!=0){
                    num[num_count++] = (char)((count%10)+48);
                    count = count/10;
                }
                num[num_count] = '\0';
                reverseString(num, num_count);
                for(int j=0;j<num_count;j++){
                    res[reslen++] = num[j];
                }
            }
            else{
                res[reslen++] = (char)(count+48);
            }
            ch = str[i];
            count = 1;
        }
    }
    res[reslen++] = ch;
    if(count>9){
        num_count = 0;
        while(count!=0){
            num[num_count++] = (char)((count%10)+48);
            count = count/10;
        }
        num[num_count] = '\0';
        reverseString(num, num_count);

        for(int j=0;j<num_count;j++){
            res[reslen++] = num[j];
        }
    }
    else{
        res[reslen++] = (char)(count+48);
    }
    res[reslen] = '\0';
    free(num);
    return res;
}

/* int* uniqueElements(int* arr, int length){
    int* temp = (int*)calloc(length, sizeof(int));
    int j = 0;
    int flag = 1;
    
    for(int i=0;i<length;i++){
        j = 0;
        flag = 1;
        while(temp[j]!=0){
            if(temp[j]==arr[i]){
                flag = 0;
                break;
            }
            j++;
        }
        if(flag==1){
            temp[ind] = arr[i];
            ind++;
        }
    }
    j = 0;
    int* res = (int*)malloc(sizeof(int)*ind);
    while(temp[j]!=0){
        res[j] = temp[j];
        j++;
    }
    free(temp);
    return res;
} */

int* uniqueElements(int* arr, int length){
    int max = arr[0];
    for(int i=0;i<length;i++){
        if(arr[i]>max)
            max = arr[i];
    }
/*     int* temp = (int*)calloc(max+1, sizeof(int)); */
    int* temp = (int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<max+1;i++){
        temp[i] = 0;
    }

    ind = 0;
    for(int i=0;i<length;i++){
        if(temp[arr[i]]==0){
            ind++;
            temp[arr[i]] = 1;
        }
    }

    /* for(int i = 0; i < length; i++) {
        if(temp[arr[i]]==1) {
            ind++;
        }
    } */
    //printf("%d\n", ind);
    int* res = (int*)malloc(sizeof(int)*ind);
    int j = 0;

    for(int i=0; i<length; i++){
        if(temp[arr[i]]==1){
            res[j] = arr[i];
            j++;
            temp[arr[i]] = 0;
        }
    }
    free(temp);
    return res;
}

int** transpose(int** matrix, int NumRow, int NumCol){
    int** res = (int**)malloc(sizeof(int*)*NumCol);
    for(int i=0;i<NumCol;i++){
        res[i] = (int*)malloc(sizeof(int)*NumRow);
        for(int j=0;j<NumRow;j++){
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}
