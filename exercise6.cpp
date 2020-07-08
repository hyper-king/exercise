int CRT(int *M_, int *P_,int len) {
		int M = 1;
		int x = 0;
		for (int i = 0; i < len;i++) {
			M = M * P_[i];
		}
		for (int j = 0; j < len; j++) {
			x = (int)(x + M_[j] * pow(M / P_[j], (P_[j]) - 1)) % M;
		}
				
		return x;
}
