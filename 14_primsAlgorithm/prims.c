#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i,j;
    printf("Enter the number of vertices>>");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the weights of the edges>>");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    int *vis=(int*)calloc(n,sizeof(int));
    vis[0]=1;
    int min,x,y,cost=0,count=0;
    while(count<n-1){
        min=9999;
        for(i=0;i<n;i++){
            if(vis[i]){
                for ( j = 0; j<n; j++)
                {
                    if(!vis[j] && graph[i][j]!=0){
                        if(min<graph[i][j] ){
                            x=i;
                            y=j;
                            min=graph[i][j];
                        }
                    }
                }
                
            }
        }
        printf("%d->%d-->>%d",x,y,min);
        vis[y]=1;
        count++;
        cost+=min;
    }
}
