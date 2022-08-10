#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;


void match(int *arr,int m,int *ptn,int n){
    int i=0,j;
    while(i<m){
        j=0;
        while(j<n && arr[i+j]==ptn[j]){
            count++;
            j++;
        }
        if(j==n){
            return;
        }
        i++;
    }
}

void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        int ptn[4]={0};
        //best case
        arr = (int *)calloc(sizeof(int),i);
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        match(arr,i,ptn,4);
        fprintf(fb,"%d\t%d\n",i,count);
        count=0;

        //worst case
        arr[i-1]=1;
        ptn[3]=1;
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        match(arr,i,ptn,4);
        fprintf(fw,"%d\t%d\n",i,count);
        count=0;

        //average case
        arr[(i/2)+2]=1;
        ptn[3]=1;
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        match(arr,i,ptn,4);
        fprintf(fa,"%d\t%d\n",i,count);
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
