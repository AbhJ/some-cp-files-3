class Solution {
public:
	int numPairsDivisibleBy60 (vector<int>& time) {
		int n = time.size(), ans = 0;
		vector <int> lessTime (n);
		map <int, int> cnt;
		for (int i = 0; i < n; i++) {
			ans += cnt[time[i] % 60];
			lessTime[i] = (60 - (time[i] % 60)) % 60;
			cnt[lessTime[i]]++;
		}
		return ans;
	}
};