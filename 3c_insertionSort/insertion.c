#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;

void insertion(int *arr,int size){

    int i,j;
    for(i=1;i<size;i++){
        j=i-1;
        int val=arr[i];
        
        while (j>=0 && arr[j]>val)
        {
            count++;
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            j--;
        }
        arr[j+1]=val;
    }
}

void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
                //Best case
        fprintf(fd,"Best case:\n");
        for (j = 0; j < i; j++)
        {
            arr[j] = j+1;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n");
        insertion(arr,i);
        fprintf(fb,"%d\t%d\n",i,count);
        fprintf(fd,"Sorted:\n");
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        count=0;

        //Average case
        fprintf(fd,"Average case:\n");
        for (j = 0; j < (i/2); j++)
        {
            arr[j] =100-j;
        }
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n");
        insertion(arr,i);
        fprintf(fa,"%d\t%d\n",i,count);
        fprintf(fd,"Sorted:\n");
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        count=0;

        //Worst case
        fprintf(fd,"Worst case:\n");
        for (j = 0; j < i; j++)
        {
            arr[j] = 200-j;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n");
        insertion(arr,i);
        fprintf(fw,"%d\t%d\n",i,count);
        fprintf(fd,"Sorted:\n");
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
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
