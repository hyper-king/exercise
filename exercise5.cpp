
int gcd(int a, int b) {
	if (a %b == 0){
		return b;
	}
	else {
		return gcd(b, a%b);
	}
}

//二次剩余的阶为(p-1)/2
void Generator(int p,vector<int> list) {
	for (int i = 2; i < p; i++) {
		if (is_primitive_root(i, p)) {
			list.push_back(i);
		}
	}
}


bool is_primitive_root(int a, int p) {
	vector<int> flist;
	prime_factors_list(p - 1, flist);
	for (int i = 0; i < flist.size(); i++) {
		if (pow(a, int((p - 1) / flist[i]) % p) == 1) {
			return false;
		}
	}
	return true;
}
	//*
void prime_factors_list(int n, vector<int> list) {
	bool isprime = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (gcd(i, j) == 1) {
				continue;
			}
			else {
				isprime = false;
			}
		}
		if (isprime) {
			list.push_back(i);
		}
		else {
			isprime = true;
		}
	}
}

/*
(a) $\Z_p$ 阶为 p = 2q ,生成元有 $\phi(\phi(p))$ = (q -1) 个
因为 $g = h^2 , h \in \Z^*_p, d == gcd(2,2q) = 2, 2q/2 = q$
所以 < g > 阶为 q

(b) 
因为 < g > 是素数阶循环群
设$ k \in < g > , k = g^i = h^{2i} , d = gcd(2i,g) = 1 $
所以 < g > 的生成元个数为 \phi(q) = q -1
*/
void g_generator(int h, int p, vector<int> res) {
	int i = 0;
	while (i < p) {
		int a = (int)pow(h ^ 2, i) % (2 * p + 1);
		res.push_back(a);
		i++;
	}
}
