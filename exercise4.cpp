int gcd(int a, int b) {
	if (a %b == 0){
		return b;
	}
	else {
		return gcd(b, a%b);
	}
}

int * mulgroup(int n) {
	int *res = (int *)malloc(n);
	int *res_ = (int *)malloc(n);
	for (int i = 1; i < n; i++) {
		if (gcd(n, i) == 1){
			int y = i*i %n;
			int x = i*i*i%n;
			res_[i] = y;
			res[i] = x;		
			return res;
		}
	}			
}
//二次剩余的阶为(p-1)/2
