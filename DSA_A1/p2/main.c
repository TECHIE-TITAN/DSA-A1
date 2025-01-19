#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void sort(int** ptr, int first, int last){
    if(last==(first+1) || last==first){
        if((*ptr)[first]>(*ptr)[last])
            swap(&(*ptr)[first], &(*ptr)[last]);
        return;
    }
    int mid = (first+last)/2;

    sort(ptr, first, mid);
    sort(ptr, mid+1, last);

    int temp[last-first+1];
    int i=first, j=mid+1;
    int k=0;
    while(i<=mid && j<=last){
        if((*ptr)[i]<=(*ptr)[j]){
            temp[k++]=(*ptr)[i++];
        }
        else temp[k++]=(*ptr)[j++];
    }

    if(i==(mid+1)){
        while(j<=last){
            temp[k++]=(*ptr)[j++];
        }
    }
    else{
        while(i<=mid){
            temp[k++]=(*ptr)[i++];
        }
    }
    for(k=first;k<=last;k++){
        (*ptr)[k] = temp[k-first];
    }
    return;
}

int main(){
    int n,l;
    scanf("%d %d", &n, &l);
    int arr[n];
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d %d", &arr[i], &temp);
    }

    int* ptr = &arr[0];
    sort(&ptr, 0, n-1);

    
    /* for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    } */
    int j=0;
    int count=1;
    for(int i=1; i<n; i++){
        if(arr[i]>=(arr[j]+l)){
            j=i;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
} 
