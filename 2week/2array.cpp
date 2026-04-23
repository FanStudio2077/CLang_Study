#include<stdio.h>
int main(){
    int scores[5][3];//定义二维成绩数组
    char subjects[3][10]={"语文","数学","英语"};//定义语数外的字符数组
    int i,j;//循环变量

    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            printf("请输入第%d位的%s成绩:\n",i+1,subjects[j]);
            scanf("%d",&scores[i][j]);
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            printf("第%d位的%s成绩是%d:\n",i+1,subjects[j],scores[i][j]);
        }
    }
    
}