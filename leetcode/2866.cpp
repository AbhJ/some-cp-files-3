class Solution {
public:
	long long maximumSumOfHeights (vector<int>& a) {
		int n = a.size();
		long long ans = 0;
		deque <int> incL, incR;
		vector <long long> lef (n), rig (n);
		for (int i = 0; i < n; i++) {
			while (incL.empty() == 0 and a[incL.back()] > a[i])
				incL.pop_back();
			if (incL.empty())
				lef[i] = (long long) (i + 1) * a[i];
			else
				lef[i] = lef[incL.back()] + (long long) (i - incL.back()) * a[i];
			incL.push_back (i);
			// cout << lef[i] << " ";
		}
		for (int i = n - 1; i > - 1; i--) {
			while (incR.empty() == 0 and a[incR.back()] > a[i])
				incR.pop_back();
			if (incR.empty())
				rig[i] = (long long) (n - i) * a[i];
			else
				rig[i] = rig[incR.back()] + (long long) (incR.back() - i) * a[i];
			incR.push_back (i);
			// cout << rig[i] << " ";
			ans = max (ans, lef[i] + rig[i] - a[i]);
		}
		return ans;
	}
};