#include<stdio.h>
#include<stdlib.h>
int visited[10]={0};
int arr[10][10];
int n;
int stack[15];
int top=-1;
void dfs(int x){
    int i;
    visited[x]=1;
    for(i=0;i<n;i++){
        if(arr[x][i]==1 && !visited[i]){
            dfs(i);
        }
    }
    stack[++top]=x;
}

void main(){
    int i,j;
    printf("Enter the number of vertices>>");
    scanf("%d",&n);
    printf("Enter the graph matrix values>>");
    arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(top>-1){
        printf("%d-->",stack[top--]);
    }
}
