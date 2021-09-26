#include "bits/stdc++.h"
using namespace std;
int main() {
	int t;
	cin >> t;
	string s1, s2, S;
	while (t--) {
		cin >> s1 >> s2;
		int l1 = s1.length();
		int l2 = s2.length();
		int i = 0, j = 0;
		S.clear();
		while (i < l1 && j < l2) {
			while (i < l1 && j < l2 && s1[i] != s2[j]) {
				if (s1[i] < s2[j])
					S += s1[i++];
				else
					S += s2[j++];
			}
			int ch = 0, la = 0;
			while (i + ch < l1 && j + ch < l2 && s1[i + ch] == s2[j + ch] && s1[i + ch] == s1[i]) {
				++la;
				++ch;
			}
			while (i + ch < l1 && j + ch < l2 && s1[i + ch] == s2[j + ch] && s1[i + ch] <= s1[i])
				++ch;
			if (i + ch < l1 && j + ch < l2)
				if (s1[i + ch] < s2[j + ch])
					while (la--)
						S += s1[i++];
				else
					while (la--)
						S += s2[j++];
			else if (i + ch == l1)
				while (la--)
					S += s2[j++];
			else if (j + ch == l2)
				while (la--)
					S += s1[i++];
		}
		while (i < l1)
			S += s1[i++];
		while (j < l2)
			S += s2[j++];
		cout << S + "\n";
	}
	return 0;
}
