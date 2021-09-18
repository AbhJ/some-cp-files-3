class Solution {
public:

	const long long M    =     1e9 + 7;

	long long add (long long a, long long b) {
		a += b;
		return (a >= M ? a - M : a);
	}

	long long mul (long long a, long long b) {
		return (a * b) % M;
	}

	long long sub (long long a, long long b) {
		return (a - b + M) % M;
	}

	long long powM (long long b, long long p) {
		long long r = 1;
		for (; p; b = mul (b, b), p >>= 1)
			if (p & 1)
				r = mul (r, b);
		return r;
	}

	long long invM (long long x) {
		return powM (x, M - 2);
	}

	vector<int> ok, primes;
	vector<vector<int>> prime_vector_sieve() {
		vector<vector<int>> prime (31);
		ok.resize (31, 1);
		for (int i = 2; i < 31; ++i)
			if (prime[i].empty()) {
				primes.emplace_back (i);
				for (int j = i; j < 31; j += i) {
					prime[j].emplace_back (i);
					if (j % (i * i) == 0)
						ok[j] = 0;
				}
			}
		return prime;
	}
	int numberOfGoodSubsets (vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> sieve = prime_vector_sieve();
		// TARGET IS IF SOME PRIME TAKEN, IT SHOULD NOT BE TAKEN AGAIN
		vector<int> freq_count (31);
		for (int i : nums)
			freq_count[i]++;
		int len = primes.size();
		int ma = 1 << len, ans = 0;
		vector<long long> dp (ma);
		dp[0] = 1;
		for (int i = 2; i <= 30; i++)
			if (ok[i] and freq_count[i]) {
				long long curMas = 0, koi = 0;
				for (auto j : primes) {
					if (i % j == 0)
						curMas |= (1 << koi);
					koi++;
				}
				auto tot = vector<int> (ma, 0);
				for (long long m = 0; m < ma; m++) {
					if ((m & curMas) == 0)
						tot[m | curMas] = mul (dp[m], freq_count[i]);
				}
				for (long long m = 0; m < ma; m++)
					dp[m] = add (tot[m], dp[m]);
			}
		for (long long m = 1; m < ma; m++)
			ans = add (ans, dp[m]);
		ans = mul (ans, powM (2, freq_count[1]));
		return ans;
	}
};
