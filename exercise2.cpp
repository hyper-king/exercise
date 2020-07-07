#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include <math.h>


//1、写Python（或Sage程序）的求乘法逆元的函数，输入a和n，求a'，使得a a' = 1 (mod n)。要求：如果无解，请给出无解提示；输出必须是正数。
typedef long long ll;
ll EXGCD(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int z = EXGCD(b, a%b, x, y);
		int temp = x;
		x = y;
		y = temp - a / b*y;
		return z;
	}
}

//2、编写C语言程序完成模指数运算，即给定整数x，y和m为输入，计算并返回值x^y mod m。
long my_mod(int x, int y, int n) {
	double z = pow(x, y);
	return (long)z % n;
}

int extgcd(int a, int b, int& x, int& y) {
	if (b) {
		int r = extgcd(b, a%b, y, x);
		y -= x*(a / b); return r;
	}
	else { x = 1; y = 0; return a; }
}
//3、编写一个Python程序求解以下同余方程： a x = b(mod m)，即给定整数a，b和m作为输入，返回所有满足方程的解x，或者给出无解告警。
int solve(int a, int b, int M) {
	int x, y, r = extgcd(a, M, x, y);
	if (b%r) return -1; else x = (x + M) % M*b / r;
	// return x; 这个是返回通解
	return x % (M / r); //返回最小解
}

//4.设p是素数，计算(p-1)! (mod p），找出规律，写成定理，并给出证明。设n是合数，计算(n-1)! (mod n），找出规律，写成定理，并给出证明。提示：可以编程找规律。
int rule(int p) {
	int s = 1;
	for (int i = 1; i <= p; i++) {
		s *= i;
	}
	return s % p;
}
//规律  (p-1)!的逆元为p-1。
