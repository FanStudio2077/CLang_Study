#include <stdio.h>
int main(){
    int year = 2015;
    double money = 800;
    int year_1 = 0;

    while(money <= 2000){
        money = money + money * 0.25;
        year_1++;
    }

    printf("%d\n", year + year_1);
    return 0;
}