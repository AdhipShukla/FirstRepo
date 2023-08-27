#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main(){

    int size=512; // Number of iterations per jump size
    int Jump=1; // Jump size
    int cnt=0; // Number of iterrations in each cycle
    int *Arr= calloc(size,sizeof(int));
    int *tempArr;
    //int **pArr=malloc(sizeof(int *));
    //*pArr=Arr;
    clock_t Start_Stamp, End_Stamp;
    double TimePassed;
    clock_t temp1,temp2;
    temp1=clock();
    while(1){
        tempArr=(int*)realloc((void *)Arr,size*sizeof(int));
        if (tempArr!=NULL)
            Arr=tempArr;
        //s*pArr=tempArr;
        Start_Stamp=clock();
        for (int k=0; k<2;k++){
        for(int i=0; i<size; i+=Jump){
            Arr[i]++;
            cnt++;
        }
        }
        End_Stamp=clock();
        TimePassed=(double)((End_Stamp-Start_Stamp))/CLOCKS_PER_SEC;
        printf("Size of Array: %fKB, Iterations : %d, Time to load and write: %.5f\n",(float)size*4/1000,cnt,TimePassed);
        cnt=0;
        if (size*4<128000){
            size*=2; // Doubling the size of the array
            Jump*=2; // Doubling the jump to make sure same number of iterations
        }
        else{
            size*=2; // Low gain after L1 cache
            Jump*=2;
        }
        free(Arr);
        if (size*4>100000000)
            break;
    }
    temp2=clock();
    return 0;
}