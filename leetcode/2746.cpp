class Solution {
public:
	int dp[1001][26][26];
	int f (vector<string>& words, int i, char fir, char las) {
		int n = words.size();
		if (i == n) {
			return 0;
		}
		if (~ dp[i][fir - 'a'][las - 'a'])
			return dp[i][fir - 'a'][las - 'a'];
		int ans = 1e9;
		if (words[i][0] == las) {
			ans = min (ans, (int) words[i].length() - 1 + f (words, i + 1, fir,
			           words[i].back()));
		}
		else {
			ans = min (ans, (int) words[i].length() + f (words, i + 1, fir,
			           words[i].back()));
		}
		if (words[i].back() == fir) {
			ans = min (ans, (int) words[i].length() - 1 + f (words, i + 1, words[i][0],
			           las));
		}
		else {
			ans = min (ans, (int) words[i].length() + f (words, i + 1, words[i][0], las));
		}
		return dp[i][fir - 'a'][las - 'a'] = ans;
	}
	int minimizeConcatenatedLength (vector<string>& words) {
		memset (dp, -1, sizeof (dp));
		return (int) words[0].length() + f (words, 1, words[0][0], words[0].back());
	}
};