#include <stdio.h>
int main() {
	int n;
	int last;
	while (scanf("%d", &n) != EOF) {
		last = 2;
		int day[7] = {0};
		for (int i = 1900; i <= 1900 + n - 1; i++) {
			for (int j = 1; j <= 12; j++) {
				if (j == 2 || j == 4 || j == 6 || j == 8 || j == 9 || j == 11 || j == 1) {
					if (last + 3 < 7) {
						day[last + 3]++;
						last += 3;
					} else {
						day[last + 3 - 7]++;
						last = last + 3 - 7;
					}
				} else if (j == 3) {
					if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
						if (last + 1 < 7) {
							day[last + 1]++;
							last += 1;
						} else {
							day[last + 1 - 7]++;
							last = last + 1 - 7;
						}
					} else {
						day[last]++;
					}
				} else {
					if (last + 2 < 7) {
						day[last + 2]++;
						last += 2;
					} else {
						day[last + 2 - 7]++;
						last = last + 2 - 7;
					}
				}
			}

		}
		printf("%d %d %d %d %d %d %d\n", day[5], day[6], day[0], day[1], day[2], day[3], day[4]);
	}
}
