#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}


void heapSort(int *arr,int n){
    int i;
    for(i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void main(){

    int i,j,n;

    printf("Enter the number of elements>>");
    scanf("%d",&n);


    int *arr=(int*)malloc(n*sizeof(int));

    printf("Enter the array elements>>");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    printf("Sorted:\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }

}
