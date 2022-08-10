#include<stdio.h>
#include<stdlib.h>
int visited[10]={0};
int arr[10][10];
int n;

void main(){
    int i,j;
    printf("Enter the number of vertices>>");
    scanf("%d",&n);
    printf("Enter the graph matrix values>>");
    arr[n][n];
    int inDegree[n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            inDegree[j]+=arr[i][j];
        }
    }
    int count=0;
    while (count<n)
    {
       for(i=0;i<n;i++){
        if(!visited[i] && !inDegree[i]){
            printf("%d-->",i);
            visited[i]=1;
            for(j=0;j<n;j++){
                if(arr[i][j]){
                    arr[i][j]=0;
                    --inDegree[j];
                }
            }
            count++;
        }
       }
    }
    
    

}
