#include<stdio.h>
#include<stdlib.h>
int visited[10]={0};
int arr[10][10];
int n,ascyclic=0;
void dfs(int x){
    int i;
    visited[x]=1;
    printf("%d-->",x);
    for(i=0;i<n;i++){
        if(arr[x][i]==1 && visited[i]){
            ascyclic=1;
        }
        if(arr[x][i]==1 && !visited[i]){
            dfs(i);
        }
    }
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
    int num=0;
    dfs(0);
    for(i=0;i<n;i++){
        if(visited[i]){
            num++;
        }
    }
    if(num==n){
        printf("Connected graph\n");
    }
    else{
        printf("Disconnected graph %d\n",num);
    }
    if(!ascyclic){
        printf("Acyclic  graph\n");
    }
    else{
        printf("Cyclic graph\n");
    }
}
