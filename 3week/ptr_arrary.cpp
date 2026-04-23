#include<stdio.h>
#define N 5
int main(){
    int nums[N]={44,24,22,57,43};
    int *ptr_num;
    int i;
    int temp;
    int *ptr_start=nums;
    int *ptr_end=nums+4;
/*
    for(i=0;i<N/2;i++){
        temp=nums[i];
        nums[i]=nums[N-i-1];
        nums[N-i-1]=temp;

    }
*/


    while (ptr_start != ptr_end){
        temp=*ptr_start;
        *ptr_start=*ptr_end;
        *ptr_end=temp;
        
        ptr_start++;
        ptr_end--;
        
    }

    ptr_num=nums;
    for(i=0;i<N;i++){
        //printf("%d\t",nums[i]);
        printf("%d\t",*(ptr_num+i));
    }

}