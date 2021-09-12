class Solution {
public:
	long long wonderfulSubstrings(string word) {
		map<long long, long long>m;
		bitset<26> f(0), occur(0); long long cnt = 0;
		m[(long long)(f.to_ulong())]++;
		for (long long i = 0; i < (long long)word.size(); i++) {
			occur[word[i] - 'a'] = 1;
			f[word[i] - 'a'] = !f[word[i] - 'a'];
//             one change
			for (long long j = 0; j < 26; j++)if (occur[j]) {
					f[j] = !f[j];
					cnt += m[(long long)(f.to_ulong())];
					f[j] = !f[j];
				}
//             no change
			cnt += m[(long long)(f.to_ulong())]++;
		}
		return cnt;
	}
};