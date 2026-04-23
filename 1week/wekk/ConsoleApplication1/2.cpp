#include <stdio.h>
int main() {
	int i;
	int num = 0;

	for (i = 0;i <= 100;i++) {
		if (i%2 == 0) {
			num = i + num;

		}
	}
	printf("%d", num);
	return 0;
}