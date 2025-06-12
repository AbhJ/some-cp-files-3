class Solution {
public:
	int cnt;
	void solve (int n, vector <bool>& vis, int cur) {
		if (cur == n + 1)
			cnt++;
		for (int i = 0; i < n; i++) if (vis[i] == false) {
				vis [i] = true;
				if ((i + 1) % cur == 0 or cur % (i + 1) == 0)
					solve (n, vis, cur + 1);
				vis [i] = false;
			}
	}
	int countArrangement (int n) {
		vector <bool> vis (n);
		solve (n, vis, 1);
		return cnt;
	}
};