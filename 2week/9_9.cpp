#include<stdio.h>

int main(){
    int i,j;//设置两个变量i,j
    
    for ( i = 1; i <= 9; i++)//外循环
    {

        for(j=1;j <= i;j++)//内循环
        {
            printf("%d*%d=%-4d",i,j,i*j);

        }

        printf("\n");//执行换行操作

    }
    


}