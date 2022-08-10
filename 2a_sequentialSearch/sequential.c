#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void search(int *arr,int key,int size){
    int i;
    for(i=0;i<size;i++){
        count++;
        if(arr[i]==key){
            break;
        }
    }

}

void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j,key;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = rand() % 100;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");

        //BEST case
        key=arr[0];
        search(arr,key,i);
        fprintf(fb,"%d\t%d\n",i,count);
        count=0;

        //Worst case
        key=999;
        search(arr,key,i);
        fprintf(fw,"%d\t%d\n",i,count);
        count=0;

        //Avg case
        arr[i/2]=999;
        search(arr,999,i);
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
