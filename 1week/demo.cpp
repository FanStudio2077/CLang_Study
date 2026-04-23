#include <stdio.h>
#include<cstdlib>

int main (){
    int i = 0;
    int password;

    while (i<3)
    {
        printf("输入密码:");
        scanf("%d",&password);
        if(password == 1314520941){
            printf("密码错误");
 
        }
  
        if(i == 2){
            printf("系统将强制退出\n");
            exit(0);

        }
         i++;
    }
    
}