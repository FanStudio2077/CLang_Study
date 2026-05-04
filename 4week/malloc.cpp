#include <stdio.h>
#include <stdlib.h>
int main(){
    int *nums;
    int i;
    nums=(int*)malloc(20);
    for(i=0;i<5;i++){
        scanf("%d",&nums[i]);
    };
    for(i=0;i<5;i++){
        printf("%d",nums[i]);
    }
    free(num);
    

}