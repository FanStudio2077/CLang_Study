#include<stdio.h>
int main() {
	int i;
	int num=0;
	for (i=1;i<=100;i++) {
		num = i + num;
		printf("%d\n", i);
	}
	printf("%d", num);
	return 0;
}