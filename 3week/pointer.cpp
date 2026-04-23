#include<stdio.h>
int main(){
    int num =131411111;
    int *ptr_1;
    ptr_1=&num;
    printf("%p",ptr_1);
    *ptr_1=1314;
    printf("%d",num);
}