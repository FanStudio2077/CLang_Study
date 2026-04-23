/*

#include<stdio.h>
#include<stdlib.h>
#define N 5

int main(){
    double score [N];
    int i;

    for (i=0;i<N;i++){
        printf("请输入第%d位的成绩：\n",i+1);
        scanf("%lf",&score[i]);

    }
    for(i=0;i<N;i++){
        printf("第%d的成绩为:%.2lf\n",i+1,score[i]);
    }


}


**/
/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int nums[]={1,5,2,6,83,44,66};
    int i;
    int search_nums;
    /*
    for(i=0;i<7;i++){
        printf("%d\t",nums[i]);
    }

    for(i=0;i<7;i++){
        
    }
    */
   /*
   printf("输入你想寻找的数字:");
   scanf("%d",&search_nums);

   for(i=0;i<7;i++){
    if(search_nums == nums[i]){
        printf("找到了\n");
        break;

    }else{
        printf("未找到相关结果\n");
    }
   }
   if(i==7){
    printf("在茫茫人海中没找到你所要求的数字");
   }
}
**/


#include<stdio.h>
#include<stdlib.h>
#define N 10
 int main(){

    int nums[N];//数值
    int i,j;//循环变量
    int temp;//缓存


    for(i=0;i<N;i++)
    {
        printf("请输入第%d位的数值:\n",i+1);
        scanf("%d",&nums[i]);
    }

    for(i=0;i<N-1;i++)//外层循环控制次数
    {
        for(j=0;j<N-i-1;j++)//内层排序
        {

            if(nums[j]<nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;

            }


        }


    }
    for(i=0;i<N-1;i++){
        printf("%d\t",nums[i]);
    }

 }