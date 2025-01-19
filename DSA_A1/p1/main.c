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
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    
    int* ptr = &arr[0];
    sort(&ptr, 0, n-1);
    /* for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    } */

    int left = 0;
    int right = n-1;
    int min = target - (arr[right] + arr[left]);
    int n1, n2;
    while(right>left){
        if(min>=(target - (arr[right] + arr[left]))){
            min = (target - (arr[right] + arr[left]));
            n1 = arr[left];
            n2 = arr[right];
        }
        if(target<= arr[right]+arr[left]){
            right--;
        }
        else left++;
    }
    printf("%d %d\n", n1, n2);
    return 0;
}
