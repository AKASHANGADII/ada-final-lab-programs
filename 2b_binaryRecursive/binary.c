#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void binary(int *arr,int l,int r,int key){
    int mid=(l+r)/2;
    if(l<=r)
    {
        count++;
        if(arr[mid]==key){
            return;
        }
        if(arr[mid]>key){
            r=mid-1;
            
        }
        else{
            l=mid+1;
        }
        binary(arr,l,r,key);
    }
    
}

void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = j+1;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");

        //Best case
        binary(arr,0,i-1,arr[(i-1)/2]);
        fprintf(fb,"%d\t%d\n",i,count);
        count=0;

        //Average case
        binary(arr,0,i-1,arr[i/4]);
        fprintf(fa,"%d\t%d\n",i,count);
        count=0;


        binary(arr,0,i-1,999);
        fprintf(fw,"%d\t%d\n",i,count);
        count=0;
    }
}

void main()
{
    int ch;
    int *arr;
    srand(time(0));
    FILE *fb, *fa, *fw, *fd;
    system("del best.txt");
    system("del avg.txt");
    system("del worst.txt");
    system("del data.txt");

    fb = fopen("best.txt", "a");
    fa = fopen("avg.txt", "a");
    fw = fopen("worst.txt", "a");
    fd = fopen("data.txt","a");
    array(arr,fb,fa,fw,fd);
}
