class Solution {
public:
	const long long int M    =     1e9 + 7;
	long long int add(long long int a, long long int b) {
		a += b;
		return (a >= M ? a - M : a);
	}
	long long int mul(long long int a, long long int b) {
		return (a * b) % M;
	}
	long long int sub(long long int a, long long int b) {
		return (a - b + M) % M;
	}
	long long int powM(long long int p, long long int b) {
		long long int r = 1;
		for (; p; b = mul(b, b), p >>= 1)
			if (p & 1)
				r = mul(r, b);
		return r;
	}
	long long int invM(long long int x) {
		return powM(x, M - 2);
	}
	long long int f[(int)1e6], b[(int)1e6];
	void binomialCoeff() {
		f[0] = 1;
		for (long long int i = 1; i <= (int)1e6 - 1; i++)
			f[i] = mul(f[i - 1], i);
		b[(int)1e6 - 1] = powM(f[(int)1e6 - 1], M - 2);
		for (long long int i = (int)1e6 - 2; i >= 0; i--)
			b[i] = mul(b[i + 1], i + 1);
	}
	long long int C(long long int n, long long int r) {
		return (r > n ? 0LL : mul(f[n], mul(b[r], b[n - r])));
	}
	int countGoodNumbers(long long n) {
		long long int koiEven = 4, koiPrime = 5;
		return mul(powM(n / 2, koiEven), powM(n - (n / 2), koiPrime));
	}
};