#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void selection(int *arr,int size){
    int i,j,min;
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            count++;
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

void array(int *arr,FILE *fb,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = rand()%40;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n");
        selection(arr,i);
        fprintf(fb,"%d\t%d\n",i,count);
        fprintf(fd,"Sorted:\n");
        for (j = 0; j < i; j++)
        {
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        
    }
}

void main()
{
    int ch;
    int *arr;
    srand(time(0));
    FILE *fb, *fa, *fw, *fd;
    system("del output.txt");
    system("del data.txt");

    fb = fopen("output.txt", "a");
    
    fd = fopen("data.txt","a");
    array(arr,fb,fd);
}
