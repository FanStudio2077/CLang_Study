#include<stdio.h>
int main(){
    int nums[5][3]={
        {44,42,54},
        {23,43,65},
        {12,34,86},
        {14,52,75},
        {13,96,22}
    };
    int i,j;
    for(j=0;j<5;j++){
        for(i=0;i<3;i++){
        printf("%d\t",nums[j][i]);
    }
    printf("\n");

    }

}