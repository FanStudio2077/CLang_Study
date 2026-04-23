#include<stdio.h>
int main(){ 
    int raw;
    scanf("%d",&raw);
    if (raw == 0)
    {
        printf("不能为0");
    }else{
        if(1 <= raw && raw <= 5){
            printf("今天为工作日,%d",raw);
        }else{
            printf("今天为休息日,%d",raw);
        }
    }
    return 0;
}