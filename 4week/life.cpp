#include<stdio.h>
int nums[];//全局变量会自动赋初值
int *changenum(){
    
    return nums;
}
int main(){
    int *nums=changenum();
    printf("%p",nums);
}