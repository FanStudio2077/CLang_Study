#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calcCircle();
int su();
int su()//计算偶数和
{
    int i;
    int sum=0;
    for(i=0;i<100;i++){
        if(i % 2 ==0){
            sum=sum+i;
        };
    };
    return sum;
};
void calcCircle()//计算圆的面积
{
    double radius,s;

    printf("请输入一个半径:");
    scanf("%lf",&radius);
    s = pow(radius,2)* 3.14;
    printf("半径为%.2lf的圆面积为%.2lf\n",radius,s);
    
}
int main(){
    // calcCircle();
    int sum=su();
    printf("%d",sum);
    
}