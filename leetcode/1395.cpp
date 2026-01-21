class Solution {
public:
	int numTeams (vector<int>& rating) {
		int n = rating.size(), ans = 0;
		for (int i = 0; i < n; i++) {
			int Lsm = 0, Lgr = 0, Rsm = 0, Rgr = 0;
			for (int l = 0; l < i; l++) {
				Lsm += rating [l] < rating [i];
				Lgr += rating [l] > rating [i];
			}
			for (int r = i + 1; r < n; r++) {
				Rsm += rating [r] < rating [i];
				Rgr += rating [r] > rating [i];
			}
			ans += Lsm * Rgr + Lgr * Rsm;
		}
		return ans;
	}
};