#include<stdio.h>
#include<stdlib.h>
int w[10]={0},val[10]={0},table[10][10],items,max;

int MAX(int a,int b){
    if(a>b) return a;
    else return b;
}

int knap(int i,int j){
    if(table[i][j]==-1){
        if(j<w[i]){
            table[i][j]=knap(i-1,j);
        }
        else{
            table[i][j]=MAX(knap(i-1,j),val[i]+knap(i-1,j-w[i]));
        }
    }
    return table[i][j];
}
void main(){
    int i,j;
    
    printf("Enter the number of items>>\n");
    scanf("%d",&items);
    printf("Enter the maximum capacity of the sack>>\n");
    scanf("%d",&max);
    printf("Enter the weight and values of the items>>\n");
    for(i=1;i<=items;i++){
        scanf("%d%d",&w[i],&val[i]);
    }
    for(i=0;i<=items;i++){
        for(j=0;j<=max;j++){
            if(i==0 || j==0){
                table[i][j]=0;
            }
            
            else{
                table[i][j]=-1;
            }
        }
    }
    printf("Maximum value of the knapsack is>>%d\n",knap(items,max));
    for(i=0;i<=items;i++){
        for(j=0;j<=max;j++){
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    
    for(i=items;i>0;i--){
        if(table[i][max]!=table[i-1][max]){
            printf("%d ",i);
            max=max-w[i];
        }
    }
}
