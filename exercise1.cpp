#include <stdio.h>
#include <stdlib.h>

//简单乘法
int simple_multiply(int a, int b) {
	int sum = 0;
	int count = 0;

	//考虑b为0的情况
	if (b == 0) {
		return 0;
	}

	//考虑负数的情况
	int flag = b < 0;
	if (flag) {
		b = -b;
	}

	while (b != 0) {
		int t = b & 0x01;
		if (t == 1) {
			sum += a << count;
		}
		count++;
		b >>= 1;
	}
	return flag ? -sum : sum;
}

//二进制gcd
int binary_gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
		
	if (b == 0) {
		return a;
	}
	if (a % 2 == 0 && b % 2 == 0) {
		return 2 * binary_gcd(a >> 1, b >> 1);
	}
	else if (a % 2 == 0) {
		return binary_gcd(a >> 1, b);
	}
	else if (b % 2 == 0) {
		return binary_gcd(a, b >> 1);
	}
	else {
		int min = a < b ? a : b;
		int max = a > b ? a : b;
		return binary_gcd(max - min, min);
	}
}

//二进制 egcd
int binary_egcd(int a, int b, int &x, int& y) {
	int d = a;
	if (d != 0) {
		d = binary_egcd(b, a%b, y, x);
		y = (y - (a / b)*y);
	}
	else {
		x = 1;
		y = 0;
	}
	return 0;
}

int main() {
	
	//int a = -5, b = 0;
	//int c = simple_multiply(a, b);
	
	int b = 12345, a = 678;
	int c = binary_gcd(a, b);
	printf("%d\n", c);
	system("pause");
	
}
