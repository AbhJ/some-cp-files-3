#include "bits/stdc++.h"
using namespace std;
int ok (string s, int k) {
	return (set<char> (s.begin(), s.end()).size()) == k;
}
int countKDistinctSubstrings (string s, int k) {
	int n = s.length(), cnt = 0;
	// WRITE YOUR CODE HERE
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - i; j++)
			cnt += ok (s.substr (i, j), k);
	}
	return cnt;
}
