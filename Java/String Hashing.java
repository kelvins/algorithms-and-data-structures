Estructura para realizar operaciones de hashing. 

static long p[] = {257, 359};
static long mod[] = {1000000007, 1000000009};
static long X = 1000000010;

static class Hashing {
	long[][] h, pot;
	int n;
	
	public Hashing(String _s) {
		char[] s = _s.toCharArray();
		n = s.length;
		h = new long[2][n + 1];
		pot = new long[2][n + 1];
		
		for (int i = 0; i < 2; ++i) {
			pot[i][0] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 2; ++j) {
				h[j][i] = (h[j][i-1] * p[j] + s[i-1]) % mod[j];
				pot[j][i] = (pot[j][i-1] * p[j]) % mod[j];
			}
		}
	}
	//Hash del substring en el rango [i, j)
	long hash(int i, int j) {
		long a = (h[0][j] - (h[0][i] * pot[0][j-i] % mod[0]) + mod[0]) % mod[0];
		long b = (h[1][j] - (h[1][i] * pot[1][j-i] % mod[1]) + mod[1]) % mod[1];
		return a*X + b;
	}
}
