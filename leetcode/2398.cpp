class Solution {
public:
	int maximumRobots (vector<int>& chargeTimes, vector<int>& runningCosts,
	                   long long budget) {
		int n = chargeTimes.size(), ans = 0, j = 0;
		deque <int> dec;
		vector <long long> pre (n);
		for (int i = 0; i < n; i++) {
			pre[i] = (i == 0 ? 0 : pre[i - 1]) + runningCosts[i];
			while (dec.empty() == 0 and chargeTimes[dec.back()] < chargeTimes[i])
				dec.pop_back();
			dec.push_back (i);
			if (dec.empty() == 0) {
				int k = i - j + 1;
				long long su = pre [i] - (j == 0 ? 0 : pre [j - 1]);
				long long curCo = chargeTimes [dec.front()] + su * k;
				if (curCo <= budget) {
					ans = max (ans, k);
					cout << dec.front() << " " << dec.back() << " " << curCo << "\n";
				}
				else if (dec.front() == j++) {
					dec.pop_front();
				}
			}
		}
		return ans;
	}
};