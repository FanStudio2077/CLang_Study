#include<stdio.h> 
int main() {
	int i=0;
	int j;
	int num=0;

	printf("输入你的数字n");

	scanf_s("%d",&i);
	
	printf("已确认您输入的n位：%d\n",i);
	for (j = 1;j <= i;j++) {
		if (j % 3 == 0) {
			num += 1;
		}
		
	}
	printf("数量为：%d", num);

}