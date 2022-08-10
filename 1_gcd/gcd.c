#include<stdio.h>
#include<stdlib.h>

void euclids(int m,int n){
    int x=m;
    int y=n;
    int count=0;
    while(n!=0){
        int temp=m%n;
        m=n;
        n=temp;
        count++;
    }
    printf("The operation count for gcd of numbers %d and %d ,gcd = %d by euclids method is %d\n",x,y,m,count);
}

void modifyEuclid(int m,int n){
    int x=m;
    int y=n;
    int count=0;
    while(n>0){
        if(m>n){
            m=m-n;
        }
        else{
            n=n-m;
        }
        count++;
    }
    printf("The operation count for gcd of numbers %d and %d ,gcd = %d by modified method is %d\n",x,y,m,count);
}

void sub(int m,int n){
    int x=m;
    int y=n;
    int count=0;
    int min=m>n?m:n;
    for(int i=min;i>0;i--){
        count++;
        if(m%i==0){
            if(n%i==0){
                break;
            }
        }
    }
    printf("The operation count for gcd of numbers %d and %d ,gcd = %d by sub method is %d\n",x,y,m,count);
}


void main(){
    int m,n;
    printf("Enter two numbers>>");
    scanf("%d%d",&m,&n);
    
    euclids(m,n);
    modifyEuclid(m,n);
    sub(m,n);

}
