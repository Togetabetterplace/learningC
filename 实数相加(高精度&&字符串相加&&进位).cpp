#include<stdio.h>
#include<string.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	char a[500] = {0};
	char b[500] = {0};
	while (scanf("%s", &a) != EOF) {
		scanf("%s", &b);
		int d1 = strlen(a) - 1;
		int d2 = strlen(b) - 1;
		int m = 0, n = 0, sum = 0, su = 0, len1 = 0, flag1 = 0,flag0=0, flag2 = 0;
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] == '.') {
				d1 = i;
				flag0 = 1;
			}
		}
		for (int i = 0; i < strlen(b); i++) {
			if (b[i] == '.') {
				d2 = i;
				flag1 = 1;
			}
		}
		char c[500] = {0};
		char d[500] = {0};
		if (flag0&&flag1) {
			n = max(strlen(b) - 1, strlen(a) - 1);
			int len2 = max(strlen(a) - d1 - 1, strlen(b) - d2 - 1);
			for (int i = len2 - 1 ; i >= 0; i--) {
				int nu = 0;
				if (a[n] <= '9' && a[n] >= '0')nu += a[n] - '0';
				if (b[n] <= '9' && b[n] >= '0')nu += b[n] - '0';
				nu += su;
				su = nu / 10;
				if (nu >= 10)nu %= 10;
				d[i] = nu + '0';
				n--;
			}
			d[len2] = '\0';
		}
		len1 = max(d1 - 1, d2 - 1);
		if (!flag0&&!flag1)len1 = max(strlen(a) - 1, strlen(b) - 1);
		sum = 0;
		m = d1 - 1;
		n = d2 - 1;
		if (!flag0&&flag1) {
			m = d1;
			n = d2;
		}
		for (int i = len1; i >= 0; i--) {
			int num = 0;
			if (i == len1 && su > 0)num++;
			if (i == 0 && sum > 0)flag2 = 1;
			if (m >= 0)num += a[m] - '0';
			if (n >= 0)num += b[n] - '0';
			num += sum;
			sum = num / 10;
			if (num >= 10)num %= 10;
			c[i] = num + '0';
			m--;
			n--;
		}
		c[len1 + 1] = '\0';
		//printf("%s\n\n\n", c);
		if (flag2)printf("1");
		if (flag1)printf("%s.%s\n", c, d);
		else printf("%s\n", c);
	}
}
