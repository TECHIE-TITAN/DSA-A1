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

char* compressString(char* str, int length){
    char ch = str[0];
    char* res = (char*)malloc(sizeof(char));
    int reslen = 0;
    int count = 1;
    char* num = (char*)malloc(sizeof(char)*20);
    for(int i=1; i<length; i++){
        if(str[i]==ch){
            count++;
        }
        else{
            /* printf("%d", count);
            printf("%c", ch);*/
            res = (char*)realloc(res, sizeof(reslen+1));
            res[reslen++] = ch;
            if(count>9){
                sprintf(num, "%d", count);
                //printf("%s\n", num);
                for(int j=0;j<strlen(num);j++){
                    res = (char*)realloc(res, sizeof(reslen+1));
                    res[reslen++] = num[j];
                }
            }
            else{
                res = (char*)realloc(res, sizeof(reslen+1));
                res[reslen++] = (char)(count+48);
            }
            ch = str[i];
            count = 1;
        }
    }
    res = (char*)realloc(res, sizeof(reslen+1));
    res[reslen++] = ch;
    if(count>9){
        sprintf(num, "%d", count);
        for(int j=0;j<strlen(num);j++){
            res = (char*)realloc(res, sizeof(reslen+1));
            res[reslen++] = num[j];
        }
    }
    else{
        res = (char*)realloc(res, sizeof(reslen+1));
        res[reslen++] = (char)(count+48);
    }
    //printf("%s\n", res);
    return res;
}

int* uniqueElements(int* arr, int length){
    /* int max=arr[0];
    for(int i=0;i<length;i++){
        if(arr[i]>max)
            max = arr[i];
    } */
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
