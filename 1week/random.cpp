#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    

    srand(time(NULL));
    int hp1=100,hp2=100;
    int att1,att2;
    
    while(hp1 >=0 && hp2 >= 0){
  
        att1=rand() % 11 + 5;
        att2=rand() % 11 + 5;
        if(att1 >> hp2){
            printf("游戏结束");
            break;
        }
        hp2 -= att1;
        hp1 -= att2;
     

        printf("\n**************\n");
        printf("玩家一攻击力为%d,玩家二剩余血量%d\n",att1,hp2);
        printf("玩家二攻击力为%d,玩家一剩余血量%d\n",att2,hp1);
        printf("\n**************\n");
    
    }


}