#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int num;
    int inp;
    int next;
    int i;

    for(;;)//主程序
    {
        int i1;
            int score=10;

        printf("欢迎游玩拆数字\n输入1进入游戏：");
        scanf("%d",&i1);
        if(i1 == 1){
            printf("即将进入游戏");
        }else{
            printf("即将退出游戏");
            break;
        }

        for (;;)//游戏进程
    {
        srand(time(NULL));
        num = rand() % 100;

        for (;;i++)
        {
            if(score <= 0)
            {
                printf("你的分数不足以继续游戏");
                break;
            }
            printf("输入你的数字:");
            scanf("%d", &inp);
            if (inp < num)
            {
                printf("小了，重新猜,扣一分");
                score-=1;
            }
            else if (inp > num)
            {
                printf("大了重新猜,扣一分");
                score-=1;
            }
            else
            {
                printf("拆队了，你正邦,加一分");
                score+=1;
                break;
            }
        }
        printf("是否继续游戏，输入1或0");
        scanf("%d", &next);

        if (next == 1)
        {
            printf("将继续游戏");
            
        }else 
        {
            
            break;
        }
    }
    printf("你的分数为%d",score);





    }
    
}
