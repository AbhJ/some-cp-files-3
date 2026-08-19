class Solution {
public:
	string pushDominoes (string dominoes) {
		string d = 'L' + dominoes + 'R', ans;
		int n = d.length();
		for (int i = 0, j = 1; j < n; j++) {
			if (d[j] == '.')
				continue;
			int len = j - i - 1;
			if (d[i] == d[j]) {
				ans += string (len, d[i]);
			}
			else if (d[i] == 'L') {
				ans += string (len, '.');
			}
			else if (d[i] == 'R') {
				int m = (i + j) / 2;
				if ((i + j) & 1 ^ 1)
					ans += string (len >> 1, 'R') + '.' + string (len >> 1, 'L');
				else
					ans += string (len >> 1, 'R') + string (len >> 1, 'L');
			}
			else {
				ans = "-1";
			}
			if (j != n - 1)
				ans += d[j];
			i = j;
		}
		return ans;
	}
};