#include <stdio.h>
#include <stdlib.h>
#define N 5
//录入
//排序
//打印
void input(double[]);
void sort(double[]);
void show(double[]);


int main(){
    double scores[N];
    input(scores);
    sort(scores);
    show(scores);




//排序
//打印

}
void sort(double scores[]){
    int i, j;
    double temp;
    for (i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(scores[j]>scores[j+1]){
                temp=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=temp;
            

            }
        }
    }
}
void input(double scores[]){
    int i;//循环变量
    for (i=0;i<N;i++){
        printf("请输入第%d门课的成绩:",i+1);
        scanf("%lf",&scores[i]);

    }

}
void show(double scores[])//录入
{

    printf("***********\n");
    printf("语文\t数学\t英语\t物理\t化学");
    int i;
    for(i=0;i<N;i++){
        printf("%.2lf\t",scores[i]);
        }

}


