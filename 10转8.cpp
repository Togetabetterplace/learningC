
#include <stdio.h>
#include <math.h>
int main() {
	int n, a, sum = 0, i = 0;
	//printf("���һ����n\n");
	scanf("%d", &n);
	while (n) {
		a = n % 8;
		n = n / 8;
		sum += a * pow(10, i);
		i++;
	}
	printf("�˽���sum:%d", sum);
}
