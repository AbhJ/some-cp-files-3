class Solution {
public:
	static int f (int a, int b, int k) {
		string A = to_string (a);
		string B = to_string (b);
		if (k > A.length() or k < B.length())
			return 0;
		if (k > B.length())
			B = string (k - B.length(), '0') + B;
		int cnt = 0;
		for (int i = 0; i < A.length() - B.length() + 1; i++) {
			if (A.substr (i, B.length()) == B) {
				cout << B << "\n";
				cnt++;
			}
		}
		return cnt;
	}
	int divisorSubstrings (int num, int k) {
		int cnt = 0;
		for (int i = 1; i * i <= num; i++)
			if (num % i == 0) {
				string I = to_string (i);
				cnt += f (num, i, k);
				if (i * i != num) {
					I = to_string (num / i);
					cnt += f (num, num / i, k);
				}
			}
		return cnt;
	}
};
