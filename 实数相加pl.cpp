#include<stdio.h>
#include<string.h>
struct nums {
	char l1[500];
	char l2[500];
};
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	nums x;
	memset(x.l1, 0, sizeof(x.l1));
	memset(x.l2, 0, sizeof(x.l2));
	nums y;
	memset(y.l1, 0, sizeof(y.l1));
	memset(y.l2, 0, sizeof(y.l2));
	char a[500] = {0};
	char b[500] = {0};
	int d1 = 0, d2 = 0;
	while (scanf("%s", &a) != EOF) {
		scanf("%s", &b);
		//²ð·Ö²¿·Ö
		for (int i = 0;; i++) {
			x.l1[i] = a[i];
			if (a[i + 1] == '.' || i >= strlen(a)-1) {
				d1 = i + 1;
				break;
			}
		}
		x.l1[d1] = '\0';
		if (d1 != 0) {
			for (int i = d1 + 1; i < strlen(a); i++) {
				x.l2[i - d1 - 1] = a[i];
			}
			x.l2[strlen(a) - d1 - 1] = '\0';
		}
		for (int i = 0;; i++) {
			y.l1[i] = b[i];
			if (b[i + 1] == '.' || i >= strlen(b)-1) {
				d2 = i + 1;
				break;
			}
		}
		y.l1[d2] = '\0';
		if (d2 != 0) {
			for (int i = 0; i < strlen(b); i++) {
				y.l2[i - d2 - 1] = b[i];
			}
			y.l2[strlen(b) - d2 - 1] = '\0';
		}
		printf("%S*%s\n\n",x.l1,y.l1);
		//printf("%s*%s  %s*%s\n\n\n",x.l1,x.l2,y.l1,y.l2);

		int lenx = max(strlen(x.l2), strlen(y.l2)), sum = 0, num = 0, flag = 0;
		int cnt = lenx - 1;
		char ans1[500] = {0}, ans2[500] = {0};
		if (d1 != 0 || d2 != 0) {
			for (int i = lenx - 1; i >= 0; i--) {
				num = 0;
				if (x.l2[cnt] <= '9' && x.l2[cnt] >= '0')num += x.l2[cnt] - '0';
				if (y.l2[cnt] <= '9' && y.l2[cnt] >= '0')num += y.l2[cnt] - '0';
				num += sum;
				sum = num / 10;
				if (num >= 10)num %= 10;
				ans1[i] = num + '0';
				cnt--;
			}
			ans1[lenx + 1] = '\0';
		}
		int lenz = max(strlen(x.l1) - 1, strlen(y.l1) - 1), numz = 0, sumz = 0, flag1 = 0, m = strlen(x.l1) - 1, n = strlen(y.l2);
		for (int i = lenz; i >= 0; i--) {
			numz = 0;
			if (i == lenz && sumz > 0)numz++;
			if (i == 0 && sumz > 0)flag = 1;
			if (m >= 0)numz += x.l1[m] - '0';
			if (n >= 0)numz += y.l1[n] - '0';
			numz += sumz;
			sumz = numz / 10;
			if (numz >= 10)numz %= 10;
			ans2[i] = numz + '0';
			m--;
			n--;
		}
		ans2[lenz + 1] = '\0';

		//printf("%s.%s\n\n\n", ans2, ans1);
		if (d1 != 0 || d2 != 0) {
			for (int i = 0; i < lenx; i++)if (ans1[i] != '0')flag1 = 1;
			int len1 = strlen(ans2), c = 0;
			for (int i = 0; i < len1; i++) {
				if (ans2[i] == '0') {
					if (c != 0) {
						printf("%c", ans2[i]);
						c++;
					}
				} else {
					printf("%c", ans2[i]);
					c++;
				}
			}
			if (flag1)printf(".");
			int len2 = strlen(ans1);
			c = 0;
			for (int i = 0; i < len2; i++) {
				if (ans1[i] == '0') {
					if (c != 0) {
						printf("%c", ans1[i]);
						c++;
					}
				} else {
					printf("%c", ans1[i]);
					c++;
				}
			}
			printf("\n");
		} else printf("%s\n", ans2);
	}
}
