#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int num = 0;
	int ran = 0;
	srand(time(NULL));

	for (;;) {
		printf("请输入你的数字:");
		scanf_s("%d", &num);

		if (num > 100) {
			printf("数字超过100");
			break;
		}
		else {

			if (num < ran){
				printf("数字小了，重新输入");
			}
			else {
				printf("数字大了，重新输入");
			}


		}

	}
	
}