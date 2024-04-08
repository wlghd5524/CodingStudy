#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char* x) {
	int len = strlen(x);
	for (int i = 0; i < len / 2; i++) {
		char temp = x[i];
		x[i] = x[len - i - 1];
		x[len - i - 1] = temp;
	}
}
int main() {
	char a[10002], b[10002], tmp[10002], result[10002] = { 0 };
	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	if (strlen(b) > strlen(a)) {
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
	}
	for (int i = 0; i < strlen(a); i++) {
		if (i >= strlen(b)) {
			if (a[i] >= 10 + '0') {
				if (i == strlen(a) - 1) {
					result[i + 1] = '1';
				}
				else {
					a[i + 1]++;
				}
				a[i] -= 10;
			}
			result[i] = a[i];
			continue;
		}
		int temp = a[i] - '0' + b[i] - '0';
		if (temp >= 10) {
			temp -= 10;
			if (i == strlen(b) - 1 && strlen(a) == strlen(b)) {
				result[i + 1] = '1';
				a[i] = temp + '0';
			}
			else {
				a[i + 1]++;
			}
		}
		result[i] = temp + '0';
	}
	reverse(result);
	printf("%s", result);
	return 0;
}