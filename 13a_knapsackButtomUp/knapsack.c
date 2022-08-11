#include<stdio.h>
#include<stdlib.h>

int MAX(int a,int b){
    if(a>b) return a;
    else return b;
}

void main(){
    int i,j;
    int w[10]={0},val[10]={0},table[10][10],items,max;
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
            else if(j<w[i]){
                table[i][j]=table[i-1][j];
            }
            else{
                table[i][j]=MAX(table[i-1][j],val[i]+table[i-1][j-w[i]]);
            }
        }
    }
    for(i=0;i<=items;i++){
        for(j=0;j<=max;j++){
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    printf("Maximum value of the knapsack is>>%d\n",table[items][max]);
    for(i=items;i>0;i--){
        if(table[i][max]!=table[i-1][max]){
            printf("%d ",i);
            max=max-w[i];
        }
    }
}
