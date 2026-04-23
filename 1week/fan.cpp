#include <stdio.h>
#include <math.h>

int main(){
    long num;
    long w;
    printf("输入你的数字:");
    scanf("%d",&num);
    w=log10(num)+1;
    printf("%d",w);
/** 
    a = num % 10;
    b = num / 10 % 10;
    c = num / 100 % 10;
    d = num / 1000 % 10;

    printf("千:%d,百:%d,十:%d,个:%d",d,c,b,a);
    return 0;
*/


}